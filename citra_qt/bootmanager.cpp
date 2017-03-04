#include "citra_qt/bootmanager.h"

class GGLWidgetInternal : public QGLWidget {
};

GRenderWindow::GRenderWindow(QWidget *parent, EmuThread *emu_thread) {}

void GRenderWindow::MakeCurrent() {
  child_->makeCurrent();
}
