#include "necprotocol.h"

#include "pirexception.h"
#include <string>
//#include <iostream>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The official NEC protocol, as I understand it, has the following attributes:
// A "zero" is encoded with a 560 usec pulse, 560 usec space.
// A "one" is encoded with a 560 usec pulse, and 3*560 (1680) usec space.
// The header is a 9000 usec pulse, 4500 usec space.
// Commands end with a trailing 560 usec pulse.
// A repeat block is a 9000 usec pulse, 2250 usec space, then trailing pulse.
// Each command runs for 110000 usec before another can be executed.

// For standard NEC, use this constructor:
NECProtocol::NECProtocol(
  QObject *guiObject,
  unsigned int index,
  NECKeyFormat fmt)
  : PIRProtocol(guiObject, index, 110000, true),
    zeroPulse(560),
    zeroSpace(560),
    onePulse(560),
    oneSpace(1680),
    headerPulse(9000),
    headerSpace(4500),
    hasHeaderPair(true),
    trailerPulse(560),
    hasTrailerPulse(true),
    repeatPulse(9000),
    repeatSpace(2250),
    hasRepeatPair(true),
    repeatNeedsHeader(false),
    fullHeadlessRepeat(false),
    elevenBitToggle(false),
    encodingFormat(fmt)
{
}

// For non-standard NEC, use this constructor:
NECProtocol::NECProtocol(
  QObject *guiObject,
  unsigned int index,
  unsigned int zPulse,
  unsigned int zSpace,
  unsigned int oPulse,
  unsigned int oSpace,
  unsigned int gSpace,
  bool iclflag,
  NECKeyFormat fmt)
  : PIRProtocol(guiObject, index, gSpace, iclflag),
    zeroPulse(zPulse),
    zeroSpace(zSpace),
    onePulse(oPulse),
    oneSpace(oSpace),
    hasHeaderPair(false),
    hasTrailerPulse(false),
    hasRepeatPair(false),
    repeatNeedsHeader(false),
    fullHeadlessRepeat(false),
    elevenBitToggle(false),
    encodingFormat(fmt)
{
}

void NECProtocol::setHeaderPair(
  unsigned int pulse,
  unsigned int space)
{
  headerPulse = pulse;
  headerSpace = space;
  hasHeaderPair = true;
}

void NECProtocol::setTrailerPulse(
  unsigned int pulse)
{
  trailerPulse = pulse;
  hasTrailerPulse = true;
}

void NECProtocol::setRepeatPair(
  unsigned int pulse,
  unsigned int space)
{
  repeatPulse = pulse;
  repeatSpace = space;
  hasRepeatPair = true;
}

void NECProtocol::setRepeatNeedsHeader(
  bool flag)
{
  repeatNeedsHeader = flag;
}

void NECProtocol::setFullHeadlessRepeat(
  bool flag)
{
  fullHeadlessRepeat = flag;
}

void NECProtocol::setElevenBitToggle(
  bool flag)
{
  elevenBitToggle = flag;
}

void NECProtocol::startSendingCommand(
  unsigned int threadableID,
  PIRKeyName command)
{
  // Exceptions here are problematic; I'll try to weed them out by putting the
  // whole thing in a try/catch block:
  try
  {
    // First, check if we are meant to be the recipient of this command:
    if (threadableID != id) return;

    // An object that helps keep track of the number of commands:
//    PIRCommandCounter commandCounter;

    // Ok, we're going to lock down this method and make sure
    // only one guy at a time passes this point:
//    QMutexLocker commandLocker(&commandMutex);

    clearRepeatFlag();

    KeycodeCollection::const_iterator i = keycodes.find(command);

    // Do we even have this key defined?
    if (i == keycodes.end())
    {
      std::string s = "Tried to send a non-existent command.\n";
      throw PIRException(s);
    }

    // construct the device:
    PIRRX51Hardware rx51device(carrierFrequency, dutyCycle);

    int repeatCount = 0;
    int commandDuration = 0;
    while (repeatCount < MAX_REPEAT_COUNT)
    {
      // If we are currently repeating, and have a special "repeat signal",
      // use that signal.  Otherwise, generate a normal command string.
      if (hasRepeatPair && repeatCount)
      {
        commandDuration = generateRepeatCommand(rx51device);
      }
      else if (fullHeadlessRepeat && repeatCount)
      {
        commandDuration = generateHeadlessCommand((*i).second, rx51device);
      }
      else if (elevenBitToggle && (repeatCount % 2))
      {
        commandDuration = generateToggledCommand((*i).second, rx51device);
      }
      else
      {
        commandDuration = generateStandardCommand((*i).second, rx51device);
      }

      // Now, tell the device to send the whole command:
      rx51device.sendCommandToDevice();

      // sleep until the next repetition of command:
      sleepUntilRepeat(commandDuration);

      // Check whether we've reached the minimum required number of repetitons:
      if (repeatCount >= minimumRepetitions)
      {
        // Check whether we've been asked to stop:
        if (checkRepeatFlag())
        {
          QMutexLocker cifLocker(&commandIFMutex);
          commandInFlight = false;
          return;
        }
      }

      ++repeatCount;
    }
  }
  catch (PIRException e)
  {
    // inform the gui:
    emit commandFailed(e.getError().c_str());
  }

  QMutexLocker cifLocker(&commandIFMutex);
  commandInFlight = false;
}


int NECProtocol::generateStandardCommand(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "header" pulse (if any):
  if (hasHeaderPair)
  {
    rx51device.addPair(headerPulse, headerSpace);
    duration += (headerPulse + headerSpace);
  }

  // Now, check the encoding format:
  switch(encodingFormat)
  {
  case Standard_NEC:
    // Standard NEC is made up of an eight-bit "address" and an eight-bit
    // "command".  First the address bits are sent (in reverse order), then
    // the address bits are inverted and sent again (in reverse order).
    // Next, we do the same to the command bits.
    // - "preData" should contain 8-bit value
    // - "bits" should contain 8-bit value
    duration += pushReverseBits(preData, rx51device);
    duration += pushInvertedReverseBits(preData, rx51device);
    duration += pushReverseBits(bits, rx51device);
    duration += pushInvertedReverseBits(bits, rx51device);
    break;
  case Extended_NEC:
    // In extended NEC, the address has been extended to 16 bits, but only
    // the reversed bits are sent, not inverted.  The command portion stays
    // the same.
    // - "preData" should contain 16-bit value
    // - "bits" should contain 8-bit value
    duration += pushReverseBits(preData, rx51device);
    duration += pushReverseBits(bits, rx51device);
    duration += pushInvertedReverseBits(bits, rx51device);
    break;
  case LIRC_NEC: default:
    // In this case, we just dump the raw bits into the device:
    duration += pushBits(preData, rx51device);
    duration += pushBits(bits, rx51device);
    duration += pushBits(postData, rx51device);
    break;
  }

  // Finally add the "trail":
  if (hasTrailerPulse)
  {
    rx51device.addSingle(trailerPulse);
    duration += trailerPulse;
  }

  return duration;
}


int NECProtocol::generateHeadlessCommand(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "pre" data:
  duration += pushBits(preData, rx51device);

  // Next, add the actual command:
  duration += pushBits(bits, rx51device);

  // Next, add the "post" data:
  duration += pushBits(postData, rx51device);

  // Finally add the "trail":
  if (hasTrailerPulse)
  {
    rx51device.addSingle(trailerPulse);
    duration += trailerPulse;
  }

  return duration;
}


int NECProtocol::generateRepeatCommand(
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // Do we need the header?
  if (repeatNeedsHeader)
  {
    // Do we even have a header?
    if (hasHeaderPair)
    {
      // Ok, then add the header to the repeat:
      rx51device.addPair(headerPulse, headerSpace);
      duration += (headerPulse + headerSpace);
    }
  }

  // Add the repeat pulse:
  rx51device.addPair(repeatPulse, repeatSpace);
  duration += (repeatPulse + repeatSpace);

  // Finally add the trailer:
  if (hasTrailerPulse)
  {
    rx51device.addSingle(trailerPulse);
    duration += trailerPulse;
  }

  return duration;
}


// NOTE!  The following is a special command to toggle the last eleven bits
// of the fifteen-bit commands used by Denon, Sharp, and a few others.  It
// assumes the command sequence will contain all fifteen bits.  If this
// is not the case, it will work incorrectly!
int NECProtocol::generateToggledCommand(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  CommandSequence::const_iterator i = bits.begin();

  int bitcount = 0;
  // First 4 bits:
  while ((bitcount < 4) && (i != bits.end()))
  {
    if (*i)
    {
      // Send pulse for "one":
      rx51device.addPair(onePulse, oneSpace);
      duration += (onePulse + oneSpace);
    }
    else
    {
      // Send pulse for "zero":
      rx51device.addPair(zeroPulse, zeroSpace);
      duration += (zeroPulse + zeroSpace);
    }
    ++i;
    ++bitcount;
  }

  // Now, invert the last eleven bits:
  while (i != bits.end())
  {
    if (*i)
    {
      // Send pulse for "zero":
      rx51device.addPair(zeroPulse, zeroSpace);
      duration += (zeroPulse + zeroSpace);
    }
    else
    {
      // Send pulse for "one":
      rx51device.addPair(onePulse, oneSpace);
      duration += (onePulse + oneSpace);
    }
    ++i;
  }

  // Add trail on end:
  if (hasTrailerPulse)
  {
    rx51device.addSingle(trailerPulse);
    duration += trailerPulse;
  }

  return duration;
}


int NECProtocol::pushBits(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;
  CommandSequence::const_iterator i = bits.begin();
  while (i != bits.end())
  {
    if (*i)
    {
      // Send the pulse for "One":
      rx51device.addPair(onePulse, oneSpace);
      duration += (onePulse + oneSpace);
    }
    else
    {
      // Send the pulse for "Zero":
      rx51device.addPair(zeroPulse, zeroSpace);
      duration += (zeroPulse + zeroSpace);
    }
    ++i;
  }

  return duration;
}


int NECProtocol::pushReverseBits(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;
  CommandSequence::const_reverse_iterator i = bits.rbegin();
  while (i != bits.rend())
  {
    if (*i)
    {
      // Send the pulse for "One":
      rx51device.addPair(onePulse, oneSpace);
      duration += (onePulse + oneSpace);
    }
    else
    {
      // Send the pulse for "Zero":
      rx51device.addPair(zeroPulse, zeroSpace);
      duration += (zeroPulse + zeroSpace);
    }
    ++i;
  }

  return duration;
}


int NECProtocol::pushInvertedReverseBits(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;
  CommandSequence::const_reverse_iterator i = bits.rbegin();
  while (i != bits.rend())
  {
    if (*i)
    {
      // Send the pulse for "Zero":
      rx51device.addPair(zeroPulse, zeroSpace);
      duration += (zeroPulse + zeroSpace);
    }
    else
    {
      // Send the pulse for "One":
      rx51device.addPair(onePulse, oneSpace);
      duration += (onePulse + oneSpace);
    }
    ++i;
  }

  return duration;
}
