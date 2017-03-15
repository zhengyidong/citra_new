#pragma once

#include <QStandardItemModel>
#include <QTreeView>
#include <QWidget>

class GameList : public QWidget {

  Q_OBJECT

public:
  enum {
    COLUMN_NAME,
    COLUMN_FILE_TYPE,
    COLUMN_SIZE,
    COLUMN_COUNT, // Number of columns
  };
  GameList(QWidget *parent = nullptr);
  ~GameList() override;

private:
  QTreeView *tree_view_ = nullptr;
  QStandardItemModel *item_model_ = nullptr;
};
