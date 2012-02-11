#include "philco.h"
#include "protocols/necprotocol.h"

PhilcoTV::PhilcoTV(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Philco_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x50, 8);

  addKey("EIGHT", Eight_Key, 0x04, 8);
  addKey("NINE", Nine_Key, 0x05, 8);
  addKey("XPRESS", Unmapped_Key, 0x06, 8);
  addKey("GUIDE", Guide_Key, 0x07, 8);
  addKey("SAP", Audio_Key, 0x08, 8);
  addKey("TVAV", Input_Key, 0x09, 8);
  addKey("LASTCH", PrevChannel_Key, 0x0A, 8);
  addKey("MUTE", Mute_Key, 0x0B, 8);
  addKey("ZERO", Zero_Key, 0x0C, 8);
  addKey("ONE", One_Key, 0x0D, 8);
  addKey("TWO", Two_Key, 0x0E, 8);
  addKey("THREE", Three_Key, 0x0F, 8);

  addKey("DISPLAY", Info_Key, 0x10, 8);
  addKey("TIMER", Sleep_Key, 0x11, 8);
  addKey("VOL+", VolumeUp_Key, 0x12, 8);
  addKey("PREF", Unmapped_Key, 0x13, 8);
  addKey("VOL-", VolumeDown_Key, 0x15, 8);
  addKey("POWER", Power_Key, 0x17, 8);
  addKey("CHANNEL-", ChannelDown_Key, 0x18, 8);
  addKey("CHANNEL+", ChannelUp_Key, 0x19, 8);
  addKey("FOUR", Four_Key, 0x1C, 8);
  addKey("FIVE", Five_Key, 0x1D, 8);
  addKey("SIX", Six_Key, 0x1E, 8);
  addKey("SEVEN", Seven_Key, 0x1F, 8);

  addKey("MAGIC", Unmapped_Key, 0x5B, 8);
  addKey("MENU", Menu_Key, 0x5E, 8);
}
