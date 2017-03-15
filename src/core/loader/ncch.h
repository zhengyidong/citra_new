#pragma once

#include <memory>

#include "common/common_types.h"
#include "common/swap.h"

#include "core/loader/loader.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// NCCH header (Note: "NCCH" appears to be a publically unknown acronym)

struct NCCH_Header {
  u8 signature[0x100];
  u32_le magic;
  u32_le content_size;
  u8 partition_id[8];
  u16_le maker_code;
  u16_le version;
  u8 reserved_0[4];
  u64_le program_id;
  u8 reserved_1[16];
  u8 logo_region_hash[0x20];
  u8 product_code[0x10];
  u8 extended_header_hash[0x20];
  u32_le extended_header_size;
  u8 reserved_2[4];
  u8 flags[8];
  u32_le plain_region_offset;
  u32_le plain_region_size;
  u32_le logo_region_offset;
  u32_le logo_region_size;
  u32_le exefs_offset;
  u32_le exefs_size;
  u32_le exefs_hash_region_size;
  u8 reserved_3[4];
  u32_le romfs_offset;
  u32_le romfs_size;
  u32_le romfs_hash_region_size;
  u8 reserved_4[4];
  u8 exefs_super_block_hash[0x20];
  u8 romfs_super_block_hash[0x20];
};

static_assert(sizeof(NCCH_Header) == 0x200, "NCCH header structure size is wrong");

namespace Loader {

/// Loads an NCCG file (e.g. from a CCI, or the first NCCH in a CXI)
class AppLoader_NCCH final : public AppLoader {
public:
  AppLoader_NCCH(FileUtil::IOFile &&file, const std::string &filepath)
    : AppLoader(std::move(file)), filepath_(filepath) {}

  /**
   * Returns the type of the file
   * @param file FileUtil::IOFile open file
   * @return FileType found, or FileType::Error if this loader doesn't know it
   */
  static FileType IdentifyType(FileUtil::IOFile &file);

  /**
   * Returns the type of this file
   * @return FileType corresponding to the loaded file
   */
  FileType GetFileType() override {
    return IdentifyType(file_);
  }

private:
  std::string filepath_;
};
}

