#pragma once

#include <QDialog>

namespace Dialogs {

enum ExitCode {
    YES = 0,
    NO,
    CANCEL
};

enum DialogButtons {
    OK_BUTTON     = 0, // 1 << 0 == 001
    NO_BUTTON     = 1, // 1 << 1 == 010
    CANCEL_BUTTON = 2  // 1 << 2 == 100
};

enum IconType {
    ERROR= 0,
    INFORMATION,
    NONE,
    WARNING
};

inline DialogButtons operator|(const DialogButtons& lhs, const DialogButtons& rhs)
{
    return static_cast<DialogButtons>(static_cast<int>(lhs) | static_cast<int>(rhs));
}

inline DialogButtons operator&(const DialogButtons& lhs, const DialogButtons& rhs)
{
    return static_cast<DialogButtons>(static_cast<int>(lhs) & static_cast<int>(rhs));
}

} // namespace Dialogs
