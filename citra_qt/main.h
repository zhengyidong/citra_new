#ifndef CITRA_QT_MAIN_H
#define CITRA_QT_MAIN_H

#include <memory>
#include <QMainWindow>

#include "ui_main.h"

class GameList;
class GRenderWindow;
class EmuThread;

namespace Ui {
class MainWindow;
}

class GMainWindow : public QMainWindow
{

  Q_OBJECT

public:
  GMainWindow();
  ~GMainWindow();

private slots:
  void OnMenuLoadFile();

private:
  Ui::MainWindow ui_;

  GRenderWindow *render_window_;
  GameList *game_list_;

  std::unique_ptr<EmuThread> emu_thread_;

};

#endif // CITRA_QT_MAIN_H
