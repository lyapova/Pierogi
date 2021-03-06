//
// manta.h
//
// Copyright 2014 by John Pietrzak (jpietrzak8@gmail.com)
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
// along with Pierogi; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#ifndef MANTA_H
#define MANTA_H

#include "pirkeysetmetadata.h"

class QObject;

class MantaDVB1: public PIRKeysetMetaData
{
public:
  MantaDVB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class MantaDVB2: public PIRKeysetMetaData
{
public:
  MantaDVB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class MantaDVD1: public PIRKeysetMetaData
{
public:
  MantaDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class MantaDVD2: public PIRKeysetMetaData
{ 
public:
  MantaDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // MANTA_H
