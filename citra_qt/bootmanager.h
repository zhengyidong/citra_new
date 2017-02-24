#ifndef CITRA_QT_BOOTMANAGER_H
#define CITRA_QT_BOOTMANAGER_H

#include <QGLWidget>
#include <QThread>

class EmuThread : public QThread {

  Q_OBJECT

};

class GRenderWindow : public QWidget {

  Q_OBJECT

public:
  GRenderWindow(QWidget *parent, EmuThread *emu_thread);
};

#endif // CITRA_QT_BOOTMANAGER_H

