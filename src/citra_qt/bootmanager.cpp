#include "citra_qt/bootmanager.h"

class GGLWidgetInternal : public QGLWidget {
public:
  GGLWidgetInternal(QGLFormat fmt, GRenderWindow *parent)
    : QGLWidget(fmt, parent), parent_(parent) {
  }
private:
  GRenderWindow *parent_;
};

GRenderWindow::GRenderWindow(QWidget *parent, EmuThread *emu_thread) :
  QWidget(parent), emu_thread_(emu_thread) {
  QGLFormat fmt;
  fmt.setVersion(3, 3);
  fmt.setProfile(QGLFormat::CoreProfile);
  fmt.setOption(QGL::NoDeprecatedFunctions);

  child_ = new GGLWidgetInternal(fmt, this);
}

void GRenderWindow::MakeCurrent() {
  child_->makeCurrent();
}
