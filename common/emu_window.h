// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

class EmuWindow {
public:
  /// Makes the graphics context current for the caller thread
  virtual void MakeCurrent() = 0;
};
