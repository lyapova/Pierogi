//
// piraudiodeviceform.cpp
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

#include "piraudiodeviceform.h"
#include "ui_piraudiodeviceform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRAudioDeviceForm::PIRAudioDeviceForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRAudioDeviceForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRAudioDeviceForm::~PIRAudioDeviceForm()
{
  delete ui;
}


void PIRAudioDeviceForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  emit fmModeEnabled(keyset->hasKey(id, FMMode_Key));
  emit repeatEnabled(keyset->hasKey(id, Repeat_Key));
  emit repeatABEnabled(keyset->hasKey(id, RepeatAB_Key));
  emit randomEnabled(keyset->hasKey(id, Random_Key));
  emit nextDiscEnabled(keyset->hasKey(id, NextDisc_Key));
  emit prevDiscEnabled(keyset->hasKey(id, PrevDisc_Key));
  emit sleepEnabled(keyset->hasKey(id, Sleep_Key));
  emit infoEnabled(keyset->hasKey(id, Info_Key));
  emit rdsEnabled(keyset->hasKey(id, RDS_Key));
}

void PIRAudioDeviceForm::on_fmModeButton_pressed()
{
  mainWindow->startRepeating(FMMode_Key);
}

void PIRAudioDeviceForm::on_fmModeButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_repeatButton_pressed()
{
  mainWindow->startRepeating(Repeat_Key);
}

void PIRAudioDeviceForm::on_repeatButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_repeatABButton_pressed()
{
  mainWindow->startRepeating(RepeatAB_Key);
}

void PIRAudioDeviceForm::on_repeatABButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_randomButton_pressed()
{
  mainWindow->startRepeating(Random_Key);
}

void PIRAudioDeviceForm::on_randomButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_nextDiscButton_pressed()
{
  mainWindow->startRepeating(NextDisc_Key);
}

void PIRAudioDeviceForm::on_nextDiscButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_prevDiscButton_pressed()
{
  mainWindow->startRepeating(PrevDisc_Key);
}

void PIRAudioDeviceForm::on_prevDiscButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_sleepButton_pressed()
{
  mainWindow->startRepeating(Sleep_Key);
}

void PIRAudioDeviceForm::on_sleepButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_infoButton_pressed()
{
  mainWindow->startRepeating(Info_Key);
}

void PIRAudioDeviceForm::on_infoButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_rdsButton_pressed()
{
  mainWindow->startRepeating(RDS_Key);
}

void PIRAudioDeviceForm::on_rdsButton_released()
{
  mainWindow->stopRepeating();
}
