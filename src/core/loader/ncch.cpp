
#include "core/loader/ncch.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// Loader namespace

namespace Loader {

////////////////////////////////////////////////////////////////////////////////////////////////////
// AppLoader_NCCH class
FileType AppLoader_NCCH::IdentifyType(FileUtil::IOFile &file) {
  u32 magic;
  file.Seek(0x100, SEEK_SET);
  if (1 != file.ReadArray<u32>(&magic, 1)) {
    return FileType::Error;
  }

  if (MakeMagic('N', 'C', 'S', 'D') == magic) {
    return FileType::CCI;
  }

  if (MakeMagic('N', 'C', 'C', 'H') == magic) {
    return FileType::CXI;
  }

  return FileType::Error;
}

}
