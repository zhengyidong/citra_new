// Copyright 2013 Dolphin Emulator Project / 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/file_util.h"

#ifdef _WIN32
// TODO
#else
  #ifdef __APPLE__
    #include <sys/param.h>
  #endif
  #include <unistd.h>
#endif

namespace FileUtil {

IOFile::IOFile() {
}

IOFile::IOFile(IOFile &&other) {
  Swap(other);
}

IOFile& IOFile::operator=(IOFile &&other) {
  Swap(other);
  return *this;
}

void IOFile::Swap(IOFile &other) {
  std::swap(file_, other.file_);
  std::swap(good_, other.good_);
}

bool IOFile::Seek(s64 off, int origin) {
  if (!IsOpen() || 0 != fseeko(file_, off, origin))
    good_ = false;

  return good_;
}


}

