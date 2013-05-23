//
// pirpreferencesform.cpp
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

#include "pirpreferencesform.h"
#include "ui_pirpreferencesform.h"
#include "pirkeysetmanager.h"

#include "mainwindow.h"

#include <QSettings>
#include <QComboBox>

//#include <iostream>

PIRPreferencesForm::PIRPreferencesForm(
  QWidget *parent,
  const PIRKeysetManager *keysetManager)
  : QWidget(parent),
    ui(new Ui::PIRPreferencesForm),
    defaultKeyset(0),
    useDefaultForVolume(false)
{
  ui->setupUi(this);

  mainWindow = dynamic_cast<MainWindow *>(parent);

  setAttribute(Qt::WA_Maemo5StackedWindow);
  setWindowFlags(windowFlags() | Qt::Window);

  setupMacroComboBox(ui->macroKbdComboBox);
  setupMacroComboBox(ui->macroBtnComboBox);

  QSettings settings("pietrzak.org", "Pierogi");

  settings.beginGroup("Preferences");

  if (settings.contains("defaultKeysetName"))
  {
    keysetManager->findKeysetID(
      settings.value("defaultKeysetMake").toString(),
      settings.value("defaultKeysetName").toString(),
      defaultKeyset);

    QString displayName = settings.value("defaultKeysetMake").toString();
    displayName.append(" ");
    displayName.append(settings.value("defaultKeysetName").toString());

    ui->defaultKeysetNameLabel->setText(displayName);
    ui->useDefaultCheckBox->setEnabled(true);
  }

  if (settings.contains("useDefaultForVolume"))
  {
    useDefaultForVolume = settings.value("useDefaultForVolume").toBool();

    if (useDefaultForVolume)
    {
      ui->useDefaultCheckBox->setChecked(true);
    }
  }

  if (settings.contains("useAltMain"))
  {
    if (settings.value("useAltMain").toBool())
    {
      ui->altMainCheckBox->setChecked(true);
      mainWindow->useAltMainPanel();
    }
  }

  if (settings.contains("macroKbdFocus"))
  {
/*
    int index = mainWindow->findMacroPack(
      settings.value("macroKbdFocus").toString());
*/
    int index = settings.value("macroKbdFocus").toInt();

    ui->macroKbdComboBox->setCurrentIndex(index);
    mainWindow->setMacroKbdFocus(index);
  }
  else
  {
    mainWindow->setMacroKbdFocus(0);
  }

  if (settings.contains("macroBtnFocus"))
  {
/*
    int index = mainWindow->findMacroPack(
      settings.value("macroBtnFocus").toString());
*/
    int index = settings.value("macroBtnFocus").toInt();

    ui->macroBtnComboBox->setCurrentIndex(index);
    mainWindow->setMacroBtnFocus(index);
  }
  else
  {
    mainWindow->setMacroBtnFocus(0);
  }

  settings.endGroup();
}


PIRPreferencesForm::~PIRPreferencesForm()
{
  delete ui;
}


void PIRPreferencesForm::on_setDefaultButton_clicked()
{
  QString make = mainWindow->getCurrentMake();
  QString name = mainWindow->getCurrentName();
  defaultKeyset = mainWindow->getCurrentKeyset();
  ui->useDefaultCheckBox->setEnabled(true);

  QString displayName = make;
  displayName.append(" ");
  displayName.append(name);
  ui->defaultKeysetNameLabel->setText(displayName);

  QSettings settings("pietrzak.org", "Pierogi");
  settings.beginGroup("Preferences");
  settings.setValue("defaultKeysetMake", make);
  settings.setValue("defaultKeysetName", name);
  settings.endGroup();

  mainWindow->enableButtons();
}

void PIRPreferencesForm::on_clearDefaultButton_clicked()
{
  defaultKeyset = 0;
  ui->defaultKeysetNameLabel->setText("None");
  ui->useDefaultCheckBox->setEnabled(false);

  QSettings settings("pietrzak.org", "Pierogi");
  settings.beginGroup("Preferences");
  settings.remove("defaultKeysetMake");
  settings.remove("defaultKeysetName");
  settings.endGroup();

  mainWindow->enableButtons();
}


void PIRPreferencesForm::on_useDefaultCheckBox_stateChanged(int arg1)
{
  QSettings settings("pietrzak.org", "Pierogi");
  settings.beginGroup("Preferences");

  if (arg1 == Qt::Checked)
  {
    useDefaultForVolume = true;
    settings.setValue("useDefaultForVolume", true);
  }
  else
  {
    useDefaultForVolume = false;
    settings.setValue("useDefaultForVolume", false);
  }

  settings.endGroup();

  mainWindow->enableButtons();
}


void PIRPreferencesForm::on_altMainCheckBox_stateChanged(
  int arg1)
{
  QSettings settings("pietrzak.org", "Pierogi");

  settings.beginGroup("Preferences");

  if (arg1 == Qt::Checked)
  {
    settings.setValue("useAltMain", true);

    mainWindow->useAltMainPanel();
  }
  else
  {
    settings.setValue("useAltMain", false);

    mainWindow->useMainPanel();
  }

  settings.endGroup();
}


void PIRPreferencesForm::on_macroKbdComboBox_activated(int index)
{
  QSettings settings("pietrzak.org", "Pierogi");
  settings.beginGroup("Preferences");
  settings.setValue("macroKbdFocus", index);
  settings.endGroup();

  mainWindow->setMacroKbdFocus(index);
}


void PIRPreferencesForm::on_macroBtnComboBox_activated(int index)
{
  QSettings settings("pietrzak.org", "Pierogi");
  settings.beginGroup("Preferences");
  settings.setValue("macroBtnFocus", index);
  settings.endGroup();

  mainWindow->setMacroBtnFocus(index);
  mainWindow->updateUserButtons();
}


void PIRPreferencesForm::setupMacroComboBox(
  QComboBox *cb)
{
  // Crappy hardcoded list.  Need to replace this...
  cb->addItem("Standard Controls");
  cb->addItem("User Defined Keyboard Macros");
  cb->addItem("Reverse Multitap Keyboard Macros");
}

void PIRPreferencesForm::on_carrierFrequencySpinBox_valueChanged(int arg1)
{
  if (arg1 < 30000) arg1 = 30000;
  if (arg1 > 60000) arg1 = 60000;
  mainWindow->setCarrierFrequency((unsigned int) arg1);
}

void PIRPreferencesForm::on_dutyCycleSpinBox_valueChanged(int arg1)
{
  mainWindow->setDutyCycle((unsigned int) arg1);
}
