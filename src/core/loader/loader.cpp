#include <memory>

#include "core/loader/ncch.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Loader {

static std::unique_ptr<AppLoader> GetFileLoader(FileUtil::IOFile &&file, FileType type,
    const std::string &filename, const std::string &filepath) {
  switch (type) {

  // NCCH/NCSD container formats.
  case FileType::CXI:
  case FileType::CCI:
    return std::make_unique<AppLoader_NCCH>(std::move(file), filepath);
    break;

  default:
    return nullptr;
  }
}

}
