#pragma once

#include "BaseScreen.h"

namespace Screens {

// Main screens
enum ScreenName {
    AUTHENTICATION_SCREEN = 0,
    MAIN_MENU_SCREEN,
    SETTING_SCREEN,
    SPLASH_SCREEN,
    USER_SCREEN
};

BaseScreen* getScreen(const ScreenName&& screen);

} // namespace Screens
