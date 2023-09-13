#include "SettingScreen.h"
#include "ui_SettingScreen.h"

#include "ScreenFactory.h"

namespace Screens {

SettingScreen::SettingScreen(QWidget* parent) :
    BaseScreen(parent),
    ui(new Ui::SettingScreen)
{
    ui->setupUi(this);
    setScreenName(this->objectName());
}

SettingScreen::~SettingScreen()
{
    delete ui;
}

auto SettingScreen::updateScreen() -> void
{

}

auto SettingScreen::updateScreen([[maybe_unused]] QVariant data) -> void
{

}

auto SettingScreen::on_logoutButton_clicked() -> void
{
    emit backTo("AuthenticationScreen");
}

auto SettingScreen::on_toUserScreenButton_clicked() -> void
{
    emit backToAndNext("MainMenuScreen", getScreen(ScreenName::USER_SCREEN));
}

auto SettingScreen::on_backButton_clicked() -> void
{
    emit back(QString("data"));
}

} // namespace Screens
