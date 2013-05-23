//
// hantarex.cpp
//
// Copyright 2012, 2013 by John Pietrzak (jpietrzak8@gmail.com)
//
// This file is part of Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "hantarex.h"
#include "protocols/necprotocol.h"

HantarexTV1::HantarexTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Hantarex_Make,
      index)
{
}


void HantarexTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x96, 8);

  addKey("Blue", Blue_Key, 0x00, 8);
  addKey("Yellow", Yellow_Key, 0x01, 8);
  addKey("Green", Green_Key, 0x02, 8);
  addKey("Red", Red_Key, 0x03, 8);
  addKey("Rewind", Rewind_Key, 0x05, 8);
//  addKey("Skip -", Previous_Key, 0x05, 8);
  addKey("Play", Play_Key, 0x07, 8);
  addKey("Power", Power_Key, 0x08, 8);
  addKey("Mute", Mute_Key, 0x09, 8);
  addKey("Volume +", VolumeUp_Key, 0x0A, 8);
  addKey("Arrow_Right", Right_Key, 0x0A, 8);
  addKey("Volume -", VolumeDown_Key, 0x0B, 8);
  addKey("Arrow_Left", Left_Key, 0x0B, 8);
  addKey("9", Nine_Key, 0x0C, 8);
  addKey("0", Zero_Key, 0x0D, 8);
  addKey("Menu", Menu_Key, 0x0F, 8);
  addKey("EXIT", Exit_Key, 0x10, 8);
//  addKey("Pause", Pause_Key, 0x13, 8);
  addKey("FFWD", FastForward_Key, 0x13, 8);
  addKey("CH+", ChannelUp_Key, 0x14, 8);
  addKey("Arrow_Up", Up_Key, 0x14, 8);
  addKey("CH-", ChannelDown_Key, 0x15, 8);
  addKey("Arrow_Down", Down_Key, 0x15, 8);
  addKey("1", One_Key, 0x18, 8);
  addKey("2", Two_Key, 0x19, 8);
  addKey("3", Three_Key, 0x1A, 8);
  addKey("4", Four_Key, 0x1B, 8);
  addKey("5", Five_Key, 0x1C, 8);
  addKey("6", Six_Key, 0x1D, 8);
  addKey("7", Seven_Key, 0x1E, 8);
  addKey("8", Eight_Key, 0x1F, 8);
  addKey("Input/Source", Input_Key, 0x23, 8);
  addKey("OK/Select", Select_Key, 0x25, 8);
  addKey("Record", Record_Key, 0x26, 8);
  addKey("Info/Display", Info_Key, 0x30, 8);
}


HantarexTV2::HantarexTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Hantarex_Make,
      index)
{
}


void HantarexTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x4020, 16);

  addKey("Power", Power_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("Input/Source", Input_Key, 0x04, 8);
  addKey("4", Four_Key, 0x05, 8);
  addKey("5", Five_Key, 0x06, 8);
  addKey("6", Six_Key, 0x07, 8);
  addKey("Sleep", Sleep_Key, 0x08, 8);
  addKey("7", Seven_Key, 0x09, 8);
  addKey("8", Eight_Key, 0x0A, 8);
  addKey("9", Nine_Key, 0x0B, 8);
  addKey("DASH", Dash_Key, 0x0D, 8);
  addKey("Ok/Select", Select_Key, 0x0F, 8);
  addKey("Menu", Menu_Key, 0x0F, 8); // ?
  addKey("CH+", ChannelUp_Key, 0x10, 8);
  addKey("Arrow_Up", Up_Key, 0x10, 8);
  addKey("Page +", PageUp_Key, 0x10, 8);
  addKey("Volume +", VolumeUp_Key, 0x11, 8);
  addKey("Arrow_Right", Right_Key, 0x11, 8);
  addKey("Volume -", VolumeDown_Key, 0x12, 8);
  addKey("Arrow_Left", Left_Key, 0x12, 8);
  addKey("CH-", ChannelDown_Key, 0x13, 8);
  addKey("Arrow_Down", Down_Key, 0x13, 8);
  addKey("Page -", PageDown_Key, 0x13, 8);
  addKey("Yellow", Yellow_Key, 0x14, 8);
  addKey("CC", Captions_Key, 0x14, 8);
  addKey("Blue", Blue_Key, 0x15, 8);
  addKey("Mute", Mute_Key, 0x17, 8);
  addKey("0", Zero_Key, 0x18, 8);
  addKey("Last/Prev Ch", PrevChannel_Key, 0x1B, 8);
  addKey("EXIT", Exit_Key, 0x1B, 8);
  addKey("Info/Display", Info_Key, 0x1D, 8);
  addKey("Red", Red_Key, 0x1F, 8);
  addKey("Format 16:9", AspectRatio_Key, 0x40, 8);
  addKey("Guide", Guide_Key, 0x42, 8);
//  addKey("Last/Prev Ch", PrevChannel_Key, 0x42, 8);
  addKey("Green", Green_Key, 0x44, 8);
}
