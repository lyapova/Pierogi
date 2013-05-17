#include "spaceprotocol.h"

#include "pirinfraredled.h"

SpaceProtocol::SpaceProtocol(
  QObject *guiObject,
  unsigned int index,
  unsigned int zerop,
  unsigned int zeros,
  unsigned int onep,
  unsigned int ones,
  unsigned int headerp,
  unsigned int headers,
  unsigned int trailerp,
  unsigned int gaps,
  bool iclflag)
  : PIRProtocol(guiObject, index, gaps, iclflag),
    zeroPulse(zerop),
    zeroSpace(zeros),
    onePulse(onep),
    oneSpace(ones),
    headerPulse(headerp),
    headerSpace(headers),
    trailerPulse(trailerp)
{
}


int SpaceProtocol::pushBits(
  const CommandSequence &bits,
  PIRInfraredLED &led)
{
  int duration = 0;
  CommandSequence::const_iterator i = bits.begin();
  while (i != bits.end())
  {
    if (*i)
    {
      // Send the pulse for "One":
      led.addPair(onePulse, oneSpace);
      duration += (onePulse + oneSpace);
    }
    else
    {
      // Send the pulse for "Zero":
      led.addPair(zeroPulse, zeroSpace);
      duration += (zeroPulse + zeroSpace);
    }
    ++i;
  }

  return duration;
}


int SpaceProtocol::pushReverseBits(
  const CommandSequence &bits,
  PIRInfraredLED &led)
{
  int duration = 0;
  CommandSequence::const_reverse_iterator i = bits.rbegin();
  while (i != bits.rend())
  {
    if (*i)
    {
      // Send the pulse for "One":
      led.addPair(onePulse, oneSpace);
      duration += (onePulse + oneSpace);
    }
    else
    {
      // Send the pulse for "Zero":
      led.addPair(zeroPulse, zeroSpace);
      duration += (zeroPulse + zeroSpace);
    }
    ++i;
  }

  return duration;
}


int SpaceProtocol::pushInvertedBits(
  const CommandSequence &bits,
  PIRInfraredLED &led)
{
  int duration = 0;
  CommandSequence::const_iterator i = bits.begin();
  while (i != bits.end())
  {
    if (*i)
    {
      // Send the pulse for "Zero":
      led.addPair(zeroPulse, zeroSpace);
      duration += (zeroPulse + zeroSpace);
    }
    else
    {
      // Send the pulse for "One":
      led.addPair(onePulse, oneSpace);
      duration += (onePulse + oneSpace);
    }
    ++i;
  }

  return duration;
}


int SpaceProtocol::pushInvertedReverseBits(
  const CommandSequence &bits,
  PIRInfraredLED &led)
{
  int duration = 0;
  CommandSequence::const_reverse_iterator i = bits.rbegin();
  while (i != bits.rend())
  {
    if (*i)
    {
      // Send the pulse for "Zero":
      led.addPair(zeroPulse, zeroSpace);
      duration += (zeroPulse + zeroSpace);
    }
    else
    {
      // Send the pulse for "One":
      led.addPair(onePulse, oneSpace);
      duration += (onePulse + oneSpace);
    }
    ++i;
  }

  return duration;
}
