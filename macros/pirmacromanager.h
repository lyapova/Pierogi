//
// pirmacromanager.h
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

#ifndef PIRMACROMANAGER_H
#define PIRMACROMANAGER_H

class PIRMacroPack;
class PIRReverseMultitap;
class MainWindow;
class QString;
class QComboBox;
class PIRRunMacroDialog;

class PIRMacroManager
{
public:
  PIRMacroManager(
    MainWindow *mw);

  ~PIRMacroManager();

//  PIRMacroPack *getUserPack();
//  PIRMacroPack *getMultitapPack();

/*
  void setKeyboardMacros(
    PIRMacroPack *pack);

  void setButtonMacros(
    PIRMacroPack *pack);
*/

  void runMacro(
    QString macroName);

  void abortMacro();

  void handleKeypress(
    char key);

  bool hasMacroButton(
    unsigned int buttonID);

  QString getMacroButtonText(
    unsigned int buttonID);

  void executeMacroButton(
    unsigned int buttonID);

//  void storeSettings();

/*
  void setKbdFocus(
    int index);

  void setBtnFocus(
    int index);
*/

  bool parseMacroFile(
    QString filename);

  void populateMacroComboBox(
    QComboBox *cb);

private:
//  void retrieveSettings();

  void executeStandardKey(
    char key);

//  PIRMacroPack *userPack;
//  PIRReverseMultitap *multitapPack;

  PIRMacroPack *macroPack;
//  PIRMacroPack *keyboardMacros;
//  PIRMacroPack *buttonMacros;

  PIRRunMacroDialog *macroDialog;

  MainWindow *mainWindow;
};

#endif // PIRMACROMANAGER_H
