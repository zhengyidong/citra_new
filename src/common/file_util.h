#pragma once

#include <cstdio>
#include <vector>

#include "common/common_types.h"

namespace FileUtil {

// simple wrapper for cstdlib file functions to
// hopefully will make error checking easier
// and make forgetting an fclose() harder
class IOFile : public NonCopyable {
public:
  IOFile();

  IOFile(IOFile &&other);
  IOFile& operator=(IOFile &&other);

  void Swap(IOFile &other);

  template <typename T>
  size_t ReadArray(T *data, size_t length) {
    static_assert(std::is_standard_layout<T>(), "Given array does not consist of standard layout objects");
#if (__GNU__ >= 5 || defined(__clang__) || defined(MSC_VER))
    static_assert(std::is_trivial_copyable<T>(), "Given array does not consist of trivially copyable objects");
#endif

    if (!IsOpen()) {
      good_ = false;
      return -1;
    }

    size_t items_read = std::fread(data, sizeof(T), length, file_);
    if (items_read != length) {
      good_ = false;
    }

    return items_read;
  }

  bool IsOpen() const { return nullptr != file_; }

  bool Seek(s64 off, int origin);

private:
  std::FILE *file_ = nullptr;
  bool good_ = true;
};

}
