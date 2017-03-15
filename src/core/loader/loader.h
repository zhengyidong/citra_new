// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <memory>

#include "common/common_types.h"
#include "common/file_util.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// Loader namespace

namespace Loader {

/// File types supported by CTR
enum class FileType {
  Error,
  Unknown,
  CCI,
  CXI,
  CIA,
  ELF,
  THREEDSX, // 3DSX
};

constexpr u32 MakeMagic(char a, char b, char c, char d) {
  return a | b << 8 | c << 16 | d << 24;
}

/// Interface for loading an application
class AppLoader : NonCopyable {
public:
  AppLoader(FileUtil::IOFile &&file) : file_(std::move(file)) {}
  virtual ~AppLoader() {}

  /**
   * Returns the type of this file
   * @return FileType corresponding to the loaded file
   */
  virtual FileType GetFileType() = 0;
protected:
  FileUtil::IOFile file_;
};
}
