#ifndef PIRFAVORITESDIALOG_H
#define PIRFAVORITESDIALOG_H

#include <QDialog>

class QListWidget;
class PIRKeysetWidgetItem;
class QListWidgetItem;
class MainWindow;

namespace Ui {
class PIRFavoritesDialog;
}

class PIRFavoritesDialog : public QDialog
{
  Q_OBJECT
  
public:
//  explicit PIRFavoritesDialog(QWidget *parent = 0);

  PIRFavoritesDialog(
    MainWindow *mw);

  ~PIRFavoritesDialog();

  QListWidget *getFavoritesListWidget();

  void addItem(
    PIRKeysetWidgetItem *item);

  int getCount();

  PIRKeysetWidgetItem *getItem(
    int index);

  void removeItem(
    unsigned int keysetID);

  void selectPrevFavKeyset();
  void selectNextFavKeyset();

private slots:
  void on_favoritesListWidget_itemClicked();
  
private:
  Ui::PIRFavoritesDialog *ui;

  MainWindow *mainWindow;
};

#endif // PIRFAVORITESDIALOG_H