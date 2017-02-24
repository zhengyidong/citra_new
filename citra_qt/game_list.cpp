#include <QVBoxLayout>

#include "citra_qt/game_list.h"

GameList::GameList(QWidget *parent) {
  QVBoxLayout *layout = new QVBoxLayout;

  tree_view_ = new QTreeView;
  item_model_ = new QStandardItemModel(tree_view_);
  tree_view_->setModel(item_model_);

  item_model_->insertColumns(0, COLUMN_COUNT);
  item_model_->setHeaderData(COLUMN_NAME, Qt::Horizontal, "Name");
  item_model_->setHeaderData(COLUMN_FILE_TYPE, Qt::Horizontal, "File type");
  item_model_->setHeaderData(COLUMN_SIZE, Qt::Horizontal, "Size");

  layout->addWidget(tree_view_);
  setLayout(layout);
}
GameList::~GameList() {}
