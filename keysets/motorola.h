//
// motorola.h
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

#ifndef MOTOROLA_H
#define MOTOROLA_H

#include "pirkeysetmetadata.h"

class QObject;

class Motorola4DTV: public PIRKeysetMetaData
{
public:
  Motorola4DTV(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MotorolaSTB1: public PIRKeysetMetaData
{
public:
  MotorolaSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MotorolaSTB1a: public MotorolaSTB1
{
public:
  MotorolaSTB1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MotorolaSTB1b: public MotorolaSTB1
{
public:
  MotorolaSTB1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MotorolaSkyDigital: public PIRKeysetMetaData
{
public:
  MotorolaSkyDigital(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // MOTOROLA_H
