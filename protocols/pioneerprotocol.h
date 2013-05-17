#ifndef PIONEERPROTOCOL_H
#define PIONEERPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// The Pioneer protocol is basically the same as the standard NEC protocol,
// with the exception that some keys are defined by a pair of NEC codes
// rather than a single one; to my understanding, where a single code is
// sent in full over and over again, a pair of codes is simply alternated
// one after the other.
//

class PioneerProtocol: public SpaceProtocol
{
public:
  PioneerProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  // First, define what is used to represent 0 and 1:
/*
  unsigned int zeroPulse;
  unsigned int zeroSpace;
  unsigned int onePulse;
  unsigned int oneSpace;
*/

  // Header pulse info:
  unsigned int headerPulse;
  unsigned int headerSpace;

  // Trailer info:
  unsigned int trailerPulse;

  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  int generateSecondaryCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);
};

#endif // PIONEERPROTOCOL_H
