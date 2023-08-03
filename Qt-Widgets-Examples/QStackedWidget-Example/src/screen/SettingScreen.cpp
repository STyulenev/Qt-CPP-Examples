#include "SettingScreen.h"
#include "ui_SettingScreen.h"

#include "UserScreen.h"

namespace Screens {

SettingScreen::SettingScreen(QWidget* parent) :
    BaseScreen(parent),
    ui(new Ui::SettingScreen)
{
    ui->setupUi(this);
}

SettingScreen::~SettingScreen()
{
    delete ui;
}

auto SettingScreen::on_logoutButton_clicked() -> void
{
    backTo("AuthenticationScreen");
}

auto SettingScreen::on_toUserScreenButton_clicked() -> void
{
    backToAndNext("MainMenuScreen", new UserScreen());
}

} // namespace Screens
