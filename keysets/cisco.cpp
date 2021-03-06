//
// cisco.cpp
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

#include "cisco.h"
#include "protocols/necprotocol.h"
#include "protocols/panasonicoldprotocol.h"
#include "protocols/nokia32protocol.h"
#include "protocols/rc5protocol.h"
#include <QComboBox>


CiscoSTB1::CiscoSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Cisco_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Cisco_Make, "8485DVB", Other_Device);
}

void CiscoSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xFD01, 16);

  addKey("vol up", VolumeUp_Key, 0x80, 8);
  addKey("vol down", VolumeDown_Key, 0x81, 8);
  addKey("record", Record_Key, 0x83, 8);
  addKey("green", Green_Key, 0x84, 8);
  addKey("channel up", ChannelUp_Key, 0x85, 8);
  addKey("channel down", ChannelDown_Key, 0x86, 8);
  addKey("0", Zero_Key, 0x87, 8);
//  addKey("exit", Exit_Key, 0x88, 8); // apparently, this is not "exit"
  addKey("exit", Info_Key, 0x88, 8);
  addKey("red", Red_Key, 0x89, 8);
  addKey("7", Seven_Key, 0x8A, 8);
  addKey("8", Eight_Key, 0x8B, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x8C, 8);
  addKey("pagedn", PageDown_Key, 0x8C, 8);
  addKey("replay", Replay_Key, 0x8D, 8);
  addKey("4", Four_Key, 0x8E, 8);
  addKey("5", Five_Key, 0x8F, 8);
  addKey("play", Play_Key, 0x91, 8);
  addKey("1", One_Key, 0x92, 8);
  addKey("2", Two_Key, 0x93, 8);
  addKey("hd", HDDInput_Key, 0x95, 8);
  addKey("blue", Blue_Key, 0x96, 8);
  addKey("stop", Stop_Key, 0x97, 8);
  addKey("radio", TunerInput_Key, 0x98, 8);
  addKey("left arrow", Left_Key, 0x99, 8);
  addKey("mute", Mute_Key, 0x9C, 8);
  addKey("right arrow", Right_Key, 0xC1, 8);
  addKey("pause", Pause_Key, 0xC3, 8);
  addKey("9", Nine_Key, 0xC4, 8);
  addKey("program guide", Guide_Key, 0xC5, 8);
  addKey("6", Six_Key, 0xC8, 8);
  addKey("up arrow", Up_Key, 0xCA, 8);
  addKey("3", Three_Key, 0xCC, 8);
  addKey("rewind", Rewind_Key, 0xCD, 8);
  addKey("select", Select_Key, 0xCE, 8);
  addKey("menu", Menu_Key, 0xCF, 8);
  addKey("fast fwd", FastForward_Key, 0xD0, 8);
  addKey("down arrow", Down_Key, 0xD2, 8);
  addKey("vod", Unmapped_Key, 0xD6, 8);
  addKey("yellow", Yellow_Key, 0xD9, 8);
  addKey("tv", Input_Key, 0xDA, 8); // Probably too obscure
  addKey("tv", AntennaInput_Key, 0xDA, 8);
  addKey("power", Power_Key, 0xDC, 8);
  addKey("pageup", PageUp_Key, 0xDD, 8);
  addKey("favourite", Favorites_Key, 0xDD, 8);
}


void CiscoSTB1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV", QVariant(Input_Key));
  cb->addItem("HD", QVariant(HDDInput_Key));
  cb->addItem("Radio", QVariant(TunerInput_Key));
}


CiscoSTB2::CiscoSTB2(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 2",
      Cisco_Make,
      TV_Panels,
      index)
{
}


void CiscoSTB2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new PanasonicOldProtocol(guiObject, index);

  addPanOldKey("DirectionUp", Up_Key, 0x1B, 0x02);
  addPanOldKey("DirectionLeft", Left_Key, 0x1B, 0x03);
  addPanOldKey("DirectionRight", Right_Key, 0x1B, 0x04);
  addPanOldKey("Pause", Pause_Key, 0x1B, 0x05);
  addPanOldKey("Guide", Guide_Key, 0x1B, 0x06);
  addPanOldKey("PowerToggle", Power_Key, 0x1B, 0x07);
  addPanOldKey("Info", Info_Key, 0x1B, 0x08);
  addPanOldKey("DirectionDown", Down_Key, 0x1B, 0x0B);
  addPanOldKey("Select/Ok", Select_Key, 0x1B, 0x0C);
  addPanOldKey("VideoSource", Input_Key, 0x1B, 0x0D);
  addPanOldKey("ChannelPrev", PrevChannel_Key, 0x1B, 0x0E);
  addPanOldKey("*", Unmapped_Key, 0x1B, 0x0F);
  addPanOldKey("1", One_Key, 0x1B, 0x10);
  addPanOldKey("2", Two_Key, 0x1B, 0x11);
  addPanOldKey("3", Three_Key, 0x1B, 0x12);
  addPanOldKey("4", Four_Key, 0x1B, 0x13);
  addPanOldKey("5", Five_Key, 0x1B, 0x14);
  addPanOldKey("6", Six_Key, 0x1B, 0x15);
  addPanOldKey("7", Seven_Key, 0x1B, 0x16);
  addPanOldKey("8", Eight_Key, 0x1B, 0x17);
  addPanOldKey("9", Nine_Key, 0x1B, 0x18);
  addPanOldKey("0", Nine_Key, 0x1B, 0x19);
  addPanOldKey("Live", LiveTV_Key, 0x1B, 0x1A);
  addPanOldKey("SkipForward", Advance_Key, 0x1B, 0x1B);
  addPanOldKey("ChannelUp", ChannelUp_Key, 0x1B, 0x1D);
  addPanOldKey("ChannelDown", ChannelDown_Key, 0x1B, 0x1E);
  addPanOldKey("Favorite", Favorites_Key, 0x1B, 0x1F);
  addPanOldKey("VolumeUp", VolumeUp_Key, 0x1B, 0x20);
  addPanOldKey("VolumeDown", VolumeDown_Key, 0x1B, 0x21);
  addPanOldKey("Mute", Mute_Key, 0x1B, 0x22);
  addPanOldKey("List", HDDInput_Key, 0x1B, 0x26); // "myDVR", might be wrong
  addPanOldKey("Replay", Replay_Key, 0x1B, 0x27); // "SkipBack"
  addPanOldKey("FastForward", FastForward_Key, 0x1B, 0x28);
  addPanOldKey("Rewind", Rewind_Key, 0x1B, 0x29);
  addPanOldKey("Exit", Exit_Key, 0x1B, 0x2C);
  addPanOldKey("M1", Unmapped_Key, 0x1B, 0x2D);
  addPanOldKey("PIPChannelup", PIPChannelUp_Key, 0x1B, 0x2E);
  addPanOldKey("Yellow A Triangle", Yellow_Key, 0x1B, 0x2F);
  addPanOldKey("Blue B Square", Blue_Key, 0x1B, 0x30);
  addPanOldKey("Red C Circle", Red_Key, 0x1B, 0x31);
  addPanOldKey("Play", Play_Key, 0x1B, 0x33);
  addPanOldKey("Stop", Stop_Key, 0x1B, 0x34);
  addPanOldKey("Record", Record_Key, 0x1B, 0x35);
  addPanOldKey("PageUp", PageUp_Key, 0x1B, 0x36);
  addPanOldKey("PageDown", PageDown_Key, 0x1B, 0x37);
  addPanOldKey("Settings", Unmapped_Key, 0x1B, 0x39);
  addPanOldKey("#/Aspect", AspectRatio_Key, 0x1B, 0x3A);
  addPanOldKey("PIPtoggle", PIP_Key, 0x1B, 0x3B);
  addPanOldKey("PIPSwap", PIPSwap_Key, 0x1B, 0x3C);
  addPanOldKey("PIPmove", PIPMove_Key, 0x1B, 0x3D);
  addPanOldKey("Menu", Menu_Key, 0x1B, 0x3E);
  addPanOldKey("PIPchanneldown", PIPChannelDown_Key, 0x1B, 0x3F);

  addPanOldKey("Search", Unmapped_Key, 0x1C, 0x17);
  addPanOldKey("900", Unmapped_Key, 0x1C, 0x18);

  addPanOldKey("+", Unmapped_Key, 0x1F, 0x07);
  addPanOldKey("DayUp/SkipForward", Unmapped_Key, 0x1F, 0x0F);
  addPanOldKey("DayDown/SkipBackward", Unmapped_Key, 0x1F, 0x10);
  addPanOldKey("OnDemand", Unmapped_Key, 0x1F, 0x1E);
  addPanOldKey("Shift/Mode", Unmapped_Key, 0x1F, 0x1F);
  addPanOldKey("M2", Unmapped_Key, 0x1F, 0x39); // "M1(alt)"
  addPanOldKey("Person", Unmapped_Key, 0x1F, 0x3B);
  addPanOldKey("Green D Diamond", Green_Key, 0x1F, 0x3D);
}


void CiscoSTB2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Video Source", QVariant(Input_Key));
  cb->addItem("Live", QVariant(LiveTV_Key));
  cb->addItem("List", QVariant(HDDInput_Key));
}


CiscoSTB3::CiscoSTB3(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 3",
      Cisco_Make,
      TV_Panels,
      index)
{
}


void CiscoSTB3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new Nokia32Protocol(guiObject, index);

  setPreData(0x2480, 16);
  setPostData(0x26, 7);

  addKey("0", Zero_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("jump", Unmapped_Key, 0x0A, 8);
  addKey("power", Power_Key, 0x0C, 8);
  addKey("info", Info_Key, 0x0F, 8);
  addKey("vol up", VolumeUp_Key, 0x10, 8);
  addKey("vol down", VolumeDown_Key, 0x11, 8);
  addKey("channel up", ChannelUp_Key, 0x20, 8);
  addKey("channel down", ChannelDown_Key, 0x21, 8);
  addKey("fast fwd", FastForward_Key, 0x28, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x29, 8);
  addKey("rewind", Rewind_Key, 0x29, 8);
  addKey("play", Play_Key, 0x2C, 8);
  addKey("pause", Pause_Key, 0x30, 8);
  addKey("stop", Stop_Key, 0x31, 8);
  addKey("record", Record_Key, 0x37, 8);
  addKey("a", Unmapped_Key, 0x38, 8);
  addKey("b", Unmapped_Key, 0x39, 8);
  addKey("multiscreen", PIP_Key, 0x3B, 8); // might be wrong
  addKey("search", Unmapped_Key, 0x40, 8);
  addKey("replay", Replay_Key, 0x4D, 8);
  addKey("menu", Menu_Key, 0x54, 8);
  addKey("exit", Exit_Key, 0x55, 8);
  addKey("up arrow", Up_Key, 0x58, 8);
  addKey("down arrow", Down_Key, 0x59, 8);
  addKey("left arrow", Left_Key, 0x5A, 8);
  addKey("right arrow", Right_Key, 0x5B, 8);
  addKey("select", Select_Key, 0x5C, 8);
  addKey("c", Unmapped_Key, 0x86, 8);
  addKey("advance", Advance_Key, 0x9C, 8);
  addKey("clear", Clear_Key, 0x9E, 8);
  addKey("program guide", Guide_Key, 0xCC, 8);
  addKey("interact", Unmapped_Key, 0xDA, 8);
  addKey("tvvideo", Input_Key, 0xE8, 8);
  addKey("recording", Record_Key, 0xF1, 8);
  addKey("livetv", LiveTV_Key, 0xF2, 8);
  addKey("phone", Unmapped_Key, 0xF9, 8);
}


CiscoSTB4::CiscoSTB4(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 4",
      Cisco_Make,
      TV_Panels,
      index)
{
}


void CiscoSTB4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("0", Zero_Key, 0x0280, 13);
  addKey("1", One_Key, 0x0281, 13);
  addKey("2", Two_Key, 0x0282, 13);
  addKey("3", Three_Key, 0x0283, 13);
  addKey("4", Four_Key, 0x0284, 13);
  addKey("5", Five_Key, 0x0285, 13);
  addKey("6", Six_Key, 0x0286, 13);
  addKey("7", Seven_Key, 0x0287, 13);
  addKey("8", Eight_Key, 0x0288, 13);
  addKey("9", Nine_Key, 0x0289, 13);
  addKey("power", Power_Key, 0x028C, 13);
  addKey("channel up", ChannelUp_Key, 0x02A0, 13);
  addKey("channel down", ChannelDown_Key, 0x02A1, 13);
  addKey("last (prev ch)", PrevChannel_Key, 0x02A2, 13);
  addKey("Skip-", Previous_Key, 0x02AA, 13);
  addKey("Skip+", Next_Key, 0x02AB, 13);
  addKey("display", Info_Key, 0x02AF, 13);
  addKey("play", Play_Key, 0x02B0, 13);
  addKey("pause", Pause_Key, 0x02B0, 13);
  addKey("rewind", Rewind_Key, 0x02B2, 13);
  addKey("ffwd", FastForward_Key, 0x02B4, 13);
  addKey("stop", Stop_Key, 0x02B6, 13);
  addKey("record", Record_Key, 0x02B7, 13);
  addKey("teletext", Teletext_Key, 0x02BC, 13);
  addKey("V+", Unmapped_Key, 0x1281, 13);
  addKey("menu", Menu_Key, 0x128F, 13);
  addKey("up arrow", Up_Key, 0x1290, 13);
  addKey("down arrow", Down_Key, 0x1291, 13);
  addKey("program guide", Guide_Key, 0x1292, 13);
  addKey("exit", Exit_Key, 0x1293, 13);
//  addKey("TV", Input_Key, 0x1293, 13); // odd
  addKey("left arrow", Left_Key, 0x1295, 13);
  addKey("right arrow", Right_Key, 0x1296, 13);
  addKey("select", Select_Key, 0x1297, 13);
  addKey("fav", Favorites_Key, 0x12A1, 13);
  addKey("red", Red_Key, 0x12AB, 13);
  addKey("green", Green_Key, 0x12AC, 13);
  addKey("yellow", Yellow_Key, 0x12AD, 13);
  addKey("blue", Blue_Key, 0x12AE, 13);
}
