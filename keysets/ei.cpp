#include "ei.h"
#include "protocols/rc5protocol.h"

// Based on LIRC Ei-TV90 config file
EiTV1::EiTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Ei_Make,
      index)
{
  addControlledDevice(Ei_Make, "COLOR 51100", TV_Device);
  addControlledDevice(Ei_Make, "COLOR 55100", TV_Device);
  addControlledDevice(Ei_Make, "COLOR 63105", TV_Device);
  addControlledDevice(Ei_Make, "COLOR 56105", TV_Device);
  addControlledDevice(Ei_Make, "COLOR 72105", TV_Device);

  threadableProtocol = new RC5Protocol(guiObject, index, 0x40);

  addKey("0", Zero_Key, 0x00, 6);
  addKey("1", One_Key, 0x01, 6);
  addKey("2", Two_Key, 0x02, 6);
  addKey("3", Three_Key, 0x03, 6);
  addKey("4", Four_Key, 0x04, 6);
  addKey("5", Five_Key, 0x05, 6);
  addKey("6", Six_Key, 0x06, 6);
  addKey("7", Seven_Key, 0x07, 6);
  addKey("8", Eight_Key, 0x08, 6);
  addKey("9", Nine_Key, 0x09, 6);
  addKey("-/--", DoubleDigit_Key, 0x0A, 6);
  addKey("Page Up", TeletextUp_Key, 0x0A, 6);
  addKey("Page Down", TeletextDown_Key, 0x0B, 6);
  addKey("ON-OFF", Power_Key, 0x0C, 6);
  addKey("MUTE", Mute_Key, 0x0D, 6);
  addKey("->*<-PP", Unmapped_Key, 0x0E, 6);
  addKey("TV_STATUS", Info_Key, 0x0F, 6);
  addKey("VOLUME+", VolumeUp_Key, 0x10, 6);
  addKey("VOLUME-", VolumeDown_Key, 0x11, 6);
  addKey("LIGHT+", BrightnessUp_Key, 0x12, 6);
  addKey("LIGHT-", BrightnessDown_Key, 0x13, 6);
  addKey("COLOR+", ColorUp_Key, 0x14, 6);
  addKey("COLOR-", ColorDown_Key, 0x15, 6);
  addKey("CONTRAST+", ContrastUp_Key, 0x1C, 6);
  addKey("CONTRAST-", ContrastDown_Key, 0x1D, 6);
  addKey("->*", Unmapped_Key, 0x1E, 6);
  addKey("P+", ChannelUp_Key, 0x20, 6);
  addKey("P-", ChannelDown_Key, 0x21, 6);
  addKey("P<P", PrevChannel_Key, 0x22, 6);
  addKey("SLEEP", Sleep_Key, 0x26, 6);
  addKey("Stop TXT", TeletextHold_Key, 0x29, 6);
  addKey("Time TXT", TeletextTime_Key, 0x2A, 6);
  addKey("Zoom", TeletextSize_Key, 0x2B, 6);
  addKey("?", TeletextReveal_Key, 0x2C, 6);
  addKey("TV in TXT", TeletextAndTV_Key, 0x2D, 6);
  addKey("Background TV", TeletextBackgroundTV_Key, 0x2E, 6);
  addKey("c", Unmapped_Key, 0x32, 6);
  addKey("d", Unmapped_Key, 0x34, 6);
  addKey("i", Unmapped_Key, 0x35, 6);
  addKey("b", Unmapped_Key, 0x36, 6);
  addKey("a", Unmapped_Key, 0x37, 6);
  addKey("AV", Input_Key, 0x38, 6);
  addKey("TXT On", Teletext_Key, 0x3C, 6);
  addKey("TV", TeletextOff_Key, 0x3F, 6);
}
