//
// pirplaystationform.h
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

#ifndef PIRPLAYSTATIONFORM_H
#define PIRPLAYSTATIONFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRPlaystationForm;
}

class PIRPlaystationForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRPlaystationForm(QWidget *parent = 0);
  PIRPlaystationForm(MainWindow *mw);
  ~PIRPlaystationForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void selectEnabled(bool);
  void startEnabled(bool);
  void l1Enabled(bool);
  void l2Enabled(bool);
  void l3Enabled(bool);
  void r1Enabled(bool);
  void r2Enabled(bool);
  void r3Enabled(bool);
  void upEnabled(bool);
  void downEnabled(bool);
  void leftEnabled(bool);
  void rightEnabled(bool);
  void triangleEnabled(bool);
  void crossEnabled(bool);
  void squareEnabled(bool);
  void circleEnabled(bool);

private slots:
  void on_selectButton_pressed();
  void on_selectButton_released();
  void on_startButton_pressed();
  void on_startButton_released();
  void on_l1Button_pressed();
  void on_l1Button_released();
  void on_l2Button_pressed();
  void on_l2Button_released();
  void on_l3Button_pressed();
  void on_l3Button_released();
  void on_r1Button_pressed();
  void on_r1Button_released();
  void on_r2Button_pressed();
  void on_r2Button_released();
  void on_r3Button_pressed();
  void on_r3Button_released();
  void on_upButton_pressed();
  void on_upButton_released();
  void on_downButton_pressed();
  void on_downButton_released();
  void on_leftButton_pressed();
  void on_leftButton_released();
  void on_rightButton_pressed();
  void on_rightButton_released();
  void on_triangleButton_pressed();
  void on_triangleButton_released();
  void on_crossButton_pressed();
  void on_crossButton_released();
  void on_squareButton_pressed();
  void on_squareButton_released();
  void on_circleButton_pressed();
  void on_circleButton_released();

private:
  Ui::PIRPlaystationForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRPLAYSTATIONFORM_H
