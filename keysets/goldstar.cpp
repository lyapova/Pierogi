//
// goldstar.cpp
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

#include "goldstar.h"
#include "protocols/necprotocol.h"
#include "protocols/rc5protocol.h"
//#include "protocols/lircprotocol.h"
#include "protocols/necxprotocol.h"
#include <QComboBox>

GoldStarTV1::GoldStarTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "105-210A TV",
      GoldStar_Make,
      TV_Panels,
      index)
{
  addControlledDevice(GoldStar_Make, "105-210A", TV_Device);
}


void GoldStarTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x04, 8);

  addKey("prup", ChannelUp_Key, 0x00, 8);
  addKey("prup", Up_Key, 0x00, 8);
  addKey("prdown", ChannelDown_Key, 0x01, 8);
  addKey("prdown", Down_Key, 0x01, 16);
  addKey("volup", VolumeUp_Key, 0x02, 8);
  addKey("volup", Right_Key, 0x02, 8);
  addKey("voldown", VolumeDown_Key, 0x03, 8);
  addKey("voldown", Left_Key, 0x03, 8);
  addKey("power", Power_Key, 0x08, 8);
  addKey("mute", Mute_Key, 0x09, 8);
  addKey("tvav", Input_Key, 0x0B, 8);
  addKey("picture", PictureMode_Key, 0x0C, 8);
  addKey("sleep", Sleep_Key, 0x0E, 8);
  addKey("0", Zero_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("qview", Unmapped_Key, 0x1A, 8);
  addKey("recall", PrevChannel_Key, 0x1B, 8);
  addKey("lowhigh", DoubleDigit_Key, 0x1C, 8);
  addKey("menu", Menu_Key, 0x43, 8);
  addKey("ok", Select_Key, 0x44, 8);
  addKey("psm", Unmapped_Key, 0x4F, 8);
}


GoldStarTV2::GoldStarTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      GoldStar_Make,
      TV_Panels,
      index)
{
}


void GoldStarTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

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
  addKey("<=", Unmapped_Key, 0x0B, 6);
  addKey("POWER", Power_Key, 0x0C, 6);
  addKey("MUTE", Mute_Key, 0x0D, 6);
  addKey("PP", PrevChannel_Key, 0x0E, 6);
  addKey("VOL+", VolumeUp_Key, 0x10, 6);
  addKey("VOL-", VolumeDown_Key, 0x11, 6);
  addKey("PROG+", ChannelUp_Key, 0x20, 6);
  addKey("PROG-", ChannelDown_Key, 0x21, 6);
  addKey("LOOP", Unmapped_Key, 0x22, 6);
  addKey("OK", Select_Key, 0x25, 6);
  addKey(">=<", Unmapped_Key, 0x29, 6);
  addKey("=o", Unmapped_Key, 0x2A, 6);
  addKey("=^", Unmapped_Key, 0x2B, 6);
  addKey("=?", TeletextReveal_Key, 0x2C, 6);
  addKey("=X", Unmapped_Key, 0x2D, 6);
  addKey("=/", Unmapped_Key, 0x2E, 6);
  addKey("YELLOW", Yellow_Key, 0x32, 6);
  addKey("BLUE", Blue_Key, 0x34, 6);
  addKey("=i", Unmapped_Key, 0x35, 6);
  addKey("GREEN", Green_Key, 0x36, 6);
  addKey("RED", Red_Key, 0x37, 6);
  addKey("AV", Unmapped_Key, 0x38, 6);
  addKey("MENU", Menu_Key, 0x3B, 6);
  addKey("=", Unmapped_Key, 0x3C, 6);
  addKey("=M", Unmapped_Key, 0x3E, 6);
  addKey("TV", Unmapped_Key, 0x3F, 6);
}


GoldStarVCR1::GoldStarVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      GoldStar_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(GoldStar_Make, "GSE-Q204P", VCR_Device);
  addControlledDevice(GoldStar_Make, "QUISY 500", VCR_Device);
}


void GoldStarVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

//  setPreData(0x7689, 16);
  setPreData(0x6E, 8);

  addKey("eject", Eject_Key, 0x00, 8);
  addKey("stop", Stop_Key, 0x01, 8);
  addKey("<rew", Rewind_Key, 0x02, 8);
  addKey("ff>", FastForward_Key, 0x03, 8);
  addKey("0", Zero_Key, 0x04, 16);
  addKey("1", One_Key, 0x05, 8);
  addKey("2", Two_Key, 0x06, 8);
  addKey("3", Three_Key, 0x07, 8);
  addKey("play", Play_Key, 0x08, 8);
  addKey("record", Record_Key, 0x09, 8);
  addKey("pause||", Pause_Key, 0x0B, 8);
  addKey("4", Four_Key, 0x0C, 8);
  addKey("5", Five_Key, 0x0D, 8);
  addKey("6", Six_Key, 0x0E, 8);
  addKey("7", Seven_Key, 0x0F, 8);
  addKey("f/a", StepForward_Key, 0x10, 8); // frame advance?
  addKey("slow", Slow_Key, 0x13, 8);
  addKey("power", Power_Key, 0x14, 8);
  addKey("tv_vcr", Input_Key, 0x15, 8);
  addKey("menu", Menu_Key, 0x16, 8);
  addKey("prog+", ChannelUp_Key, 0x18, 8);
  addKey("prog-", ChannelDown_Key, 0x19, 8);
  addKey("slow+", SlowPlus_Key, 0x1A, 8);
  addKey("slow-", SlowMinus_Key, 0x1B, 8);
  addKey("8", Eight_Key, 0x1C, 8);
  addKey("9", Nine_Key, 0x1D, 8);
  addKey("display", Info_Key, 0x1E, 8);
  addKey("clear", Clear_Key, 0x1F, 8);
  addKey("child_lock", Unmapped_Key, 0x3F, 8);
  addKey("viss", IndexSearch_Key, 0x41, 8);
  addKey("tracking+", TrackingPlus_Key, 0x44, 8);
  addKey("tracking-", TrackingMinus_Key, 0x45, 8);
  addKey("show_view", Unmapped_Key, 0x47, 8); // vhsplus+, etc.
  addKey("sp/lp", VHSSpeed_Key, 0x48, 8);
  addKey("vps", RecordPDC_Key, 0x49, 8);
  addKey("start", Unmapped_Key, 0x4A, 8);
  addKey("length", Unmapped_Key, 0x4B, 8);
  addKey("clock_count", Clock_Key, 0x4C, 8); // "memory"
  addKey("reset", Reset_Key, 0x4D, 8);
  addKey("preset", Unmapped_Key, 0x4E, 8);
  addKey("a_trk", AutoTracking_Key, 0x5F, 8);
  addKey("up", Up_Key, 0x82, 8);
  addKey("left", Left_Key, 0x83, 8);
  addKey("down", Down_Key, 0x89, 8);
  addKey("ok", Select_Key, 0x8E, 8);
  addKey("right", Right_Key, 0x90, 8);
}


GoldStarVCR1a::GoldStarVCR1a(
  unsigned int index)
  : GoldStarVCR1(index)
{
  setKeysetName("VCR Keyset 1a");
}


void GoldStarVCR1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  GoldStarVCR1::populateProtocol(guiObject);

  addKey("TU_AV", Input_Key, 0x56, 16);
}


GoldStarVCR1b::GoldStarVCR1b(
  unsigned int index)
  : GoldStarVCR1(index)
{
  setKeysetName("VCR Keyset 1b");
}


void GoldStarVCR1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  GoldStarVCR1::populateProtocol(guiObject);

  addKey("BACK", Exit_Key, 0x4C, 8);
}


GoldStarVCR1c::GoldStarVCR1c(
  unsigned int index)
  : GoldStarVCR1(index)
{
  setKeysetName("VCR Keyset 1c");
}


void GoldStarVCR1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  GoldStarVCR1::populateProtocol(guiObject);

  addKey("trk-", TrackingMinus_Key, 0xED, 8);
  addKey("trk+", TrackingPlus_Key, 0xEE, 8);
  addKey("a.trk", AutoTracking_Key, 0xE8, 8);
  addKey("a.repeart", Unmapped_Key, 0xF5, 8);
}


GoldStarAudio1::GoldStarAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      GoldStar_Make,
      Receiver_Panels,
      index)
{
  addControlledDevice(GoldStar_Make, "FFH-272A/L", Audio_Device);
}



// Based on LIRC 6710S-6000A config file
void GoldStarAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, true);

  setPreData(0x1010, 16);

  addKey("fm", FM_Key, 0x00, 8);
  addKey("mw", AM_Key, 0x01, 8);
  addKey("lw", LW_Key, 0x02, 8);
  addKey("cd", CDInput_Key, 0x03, 8);
  addKey("ply/pau", Play_Key, 0x04, 8);
  addKey("stop", Stop_Key, 0x05, 8);
  addKey("prev", Previous_Key, 0x06, 8);
  addKey("next", Next_Key, 0x07, 8);
  addKey("tape", TapeInput_Key, 0x08, 8);
  addKey("aux", AuxInput_Key, 0x09, 8);
  addKey("pre-", ChannelDown_Key, 0x12, 8);
  addKey("pre-", PrevPreset_Key, 0x12, 8);
  addKey("pre+", ChannelUp_Key, 0x13, 8);
  addKey("pre+", NextPreset_Key, 0x13, 8);
  addKey("vol-", VolumeDown_Key, 0x16, 8);
  addKey("vol+", VolumeUp_Key, 0x17, 8);

  addKey("power", Power_Key, 0x1E, 8);
  addKey("mute", Mute_Key, 0x1F, 8);

  addKey("eqpatt", Unmapped_Key, 0x40, 8);
  addKey("dskip", NextDisc_Key, 0x4A, 8);
  addKey("prog", Program_Key, 0x4D, 8);
  addKey("repeat", Repeat_Key, 0x4E, 8);
  addKey("random", Random_Key, 0x50, 8);
  addKey("remain", Unmapped_Key, 0x51, 8);
}


void GoldStarAudio1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("FM", QVariant(FM_Key));
  cb->addItem("MW", QVariant(AM_Key));
  cb->addItem("LW", QVariant(LW_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
}
