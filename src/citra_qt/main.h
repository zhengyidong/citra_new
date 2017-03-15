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

  static const int max_recent_files_item = 10; ///< Max number of recently loaded items to keep track

public:
  GMainWindow();
  ~GMainWindow();

private:
  bool InitializeSystem();
  bool LoadROM(const std::string &filename);
  void BootGame(const std::string &filename);
  void ShutdownGame();

  /**
   * Stores the filename in the recently loaded files list.
   * The new filename is stored at the beginning of the recently loaded files list.
   * After inserting the new entry, duplicates are removed meaning that if
   * this was inserted from \a OnMenuRecentFile(), the entry will be put on top
   * and remove from its previous position.
   *
   * Finally, this function calls \a UpdateRecentFiles() to update the UI.
   *
   * @param filename the filename to store
   */
  void StoreRecentFile(const std::string &name);

  /**
   * Updates the recent files menu.
   * Menu entries are rebuilt from the configuration file.
   * If there is no entry in the menu, the menu is greyed out.
   */
  void UpdateRecentFiles();


private slots:
  void OnMenuLoadFile();
  /// Called whenever a user selects the "File->Select Game List Root" menu item.
  void OnMenuRecentFile();

private:
  Ui::MainWindow ui_;

  GRenderWindow *render_window_;
  GameList *game_list_;

  std::unique_ptr<EmuThread> emu_thread_;

  QAction *actions_recent_files[max_recent_files_item];
};

#endif // CITRA_QT_MAIN_H
