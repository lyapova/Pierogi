//
// philips.h
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

#ifndef PHILIPS_H
#define PHILIPS_H

#include "pirkeysetmetadata.h"

class QObject;
class QComboBox;

class PhilipsTV1: public PIRKeysetMetaData
{
public:
  PhilipsTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsTV1a: public PhilipsTV1
{
public:
  PhilipsTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsTV1b: public PhilipsTV1
{
public:
  PhilipsTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsTV1c: public PhilipsTV1
{
public:
  PhilipsTV1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsTV1d: public PhilipsTV1
{
public:
  PhilipsTV1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsTV1e: public PhilipsTV1
{
public:
  PhilipsTV1e(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsTV1f: public PhilipsTV1
{
public:
  PhilipsTV1f(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsTV2: public PIRKeysetMetaData
{
public:
  PhilipsTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsTV2a: public PhilipsTV2
{
public:
  PhilipsTV2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsTV2b: public PhilipsTV2
{
public:
  PhilipsTV2b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsTV3: public PIRKeysetMetaData
{
public:
  PhilipsTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsDVD1: public PIRKeysetMetaData
{
public:
  PhilipsDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsDVD1a: public PhilipsDVD1
{
public:
  PhilipsDVD1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsDVD1b: public PhilipsDVD1
{
public:
  PhilipsDVD1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsDVD1c: public PhilipsDVD1
{
public:
  PhilipsDVD1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsDVD1d: public PhilipsDVD1
{
public:
  PhilipsDVD1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsDVD2: public PIRKeysetMetaData
{
public:
  PhilipsDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsDVD3: public PIRKeysetMetaData
{
public:
  PhilipsDVD3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class PhilipsDVD3a: public PhilipsDVD3
{
public:
  PhilipsDVD3a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsDVD4: public PIRKeysetMetaData
{
public:
  PhilipsDVD4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class PhilipsVCR1: public PIRKeysetMetaData
{
public:
  PhilipsVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsVCR1a: public PhilipsVCR1
{
public:
  PhilipsVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsVCR1b: public PhilipsVCR1
{
public:
  PhilipsVCR1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsVCR1c: public PhilipsVCR1
{
public:
  PhilipsVCR1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsSat1: public PIRKeysetMetaData
{
public:
  PhilipsSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsSat2: public PIRKeysetMetaData
{
public:
  PhilipsSat2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsSat2a: public PhilipsSat2
{
public:
  PhilipsSat2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsSat3: public PIRKeysetMetaData
{
public:
  PhilipsSat3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsAudio1: public PIRKeysetMetaData
{
public:
  PhilipsAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class PhilipsAudio1a: public PhilipsAudio1
{
public:
  PhilipsAudio1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsAudio1b: public PhilipsAudio1
{
public:
  PhilipsAudio1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class PhilipsAudio2: public PIRKeysetMetaData
{
public:
  PhilipsAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class PhilipsAudio3: public PIRKeysetMetaData
{
public:
  PhilipsAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PhilipsAudio4: public PIRKeysetMetaData
{
public:
  PhilipsAudio4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

//  virtual void populateInputList(
//    QComboBox *cb);
};

/*
class PhilipsAudio5: public PIRKeysetMetaData
{
public:
  PhilipsAudio5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};
*/

#endif // PHILIPS_H
