// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <QStringList>
#include <QString>

namespace UISettings {

struct Values {
  QString rom_path;
  QStringList recent_files;
};

extern Values values;

}
