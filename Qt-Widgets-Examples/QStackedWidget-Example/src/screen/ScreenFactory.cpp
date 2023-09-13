#include "ScreenFactory.h"

#include "assert.h"

#include "AuthenticationScreen.h"
#include "MainMenuScreen.h"
#include "SettingScreen.h"
#include "SplashScreen.h"
#include "UserScreen.h"

namespace Screens {

BaseScreen* getScreen(const ScreenName&& screen)
{
    switch(screen) {
    case ScreenName::AUTHENTICATION_SCREEN:
        return new AuthenticationScreen();
    case ScreenName::MAIN_MENU_SCREEN:
        return new MainMenuScreen();
    case ScreenName::SETTING_SCREEN:
        return new SettingScreen();
    case ScreenName::SPLASH_SCREEN:
        return new SplashScreen();
    case ScreenName::USER_SCREEN:
        return new UserScreen();
    default:
        assert("ScreenFactory - unknown screen");
    }

    throw std::bad_function_call();
}

} // namespace Screens
