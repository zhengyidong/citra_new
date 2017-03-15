#ifndef CITRA_QT_BOOTMANAGER_H
#define CITRA_QT_BOOTMANAGER_H

#include <atomic>
#include <mutex>
#include <condition_variable>

#include <QGLWidget>
#include <QThread>

#include "common/emu_window.h"

class GGLWidgetInternal;

class EmuThread : public QThread {

  Q_OBJECT

public:

  /**
   * Sets whether the emulation thread is running or not
   * @param running Boolean value, set the emulation thread to running if true
   * @note This function is thread-safe
   */
  void SetRunning(bool running) {
    std::unique_lock<std::mutex> lock(running_mutex_);
    this->running_ = running;
    lock.unlock();
    running_cv_.notify_all();
  }

  /**
   * Check if the emulation thread is running or not
   * @return True if the emulation thread is running, otherwise false
   * @note This function is thread-safe
   */
  bool IsRunning() { return running_; }

  /**
   * Requests for the emulation thread to stop running
   */
  void RequestStop() {
    stop_run_ = true;
    SetRunning(false);
  }

private:
  bool running_;
  std::atomic<bool> stop_run_;
  std::mutex running_mutex_;
  std::condition_variable running_cv_;
};

class GRenderWindow : public QWidget, public EmuWindow {

  Q_OBJECT

public:
  GRenderWindow(QWidget *parent, EmuThread *emu_thread);

  // EmuWindow implementation
  void MakeCurrent() override;
private:
  GGLWidgetInternal *child_;

  EmuThread *emu_thread_;
};

#endif // CITRA_QT_BOOTMANAGER_H

