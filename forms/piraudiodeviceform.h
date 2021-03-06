//
// piraudiodeviceform.h
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

#ifndef PIRAUDIODEVICEFORM_H
#define PIRAUDIODEVICEFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRAudioDeviceForm;
}

class PIRAudioDeviceForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRAudioDeviceForm(QWidget *parent = 0);

  PIRAudioDeviceForm(
    MainWindow *mw);

  ~PIRAudioDeviceForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void fmModeEnabled(bool);
  void repeatEnabled(bool);
  void repeatABEnabled(bool);
  void randomEnabled(bool);
  void nextDiscEnabled(bool);
  void prevDiscEnabled(bool);
  void sleepEnabled(bool);
  void infoEnabled(bool);
  void rdsEnabled(bool);
  
private slots:
  void on_fmModeButton_pressed();
  void on_fmModeButton_released();
  void on_repeatButton_pressed();
  void on_repeatButton_released();
  void on_repeatABButton_pressed();
  void on_repeatABButton_released();
  void on_randomButton_pressed();
  void on_randomButton_released();
  void on_nextDiscButton_pressed();
  void on_nextDiscButton_released();
  void on_prevDiscButton_pressed();
  void on_prevDiscButton_released();
  void on_sleepButton_pressed();
  void on_sleepButton_released();
  void on_infoButton_pressed();
  void on_infoButton_released();
  void on_rdsButton_pressed();
  void on_rdsButton_released();

private:
  Ui::PIRAudioDeviceForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRAUDIODEVICEFORM_H
