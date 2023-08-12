#include "MainMenuScreen.h"
#include "ui_MainMenuScreen.h"

#include "UserScreen.h"
#include "SettingScreen.h"

namespace Screens {

MainMenuScreen::MainMenuScreen(QWidget* parent) :
    BaseScreen(parent),
    ui(new Ui::MainMenuScreen)
{
    ui->setupUi(this);
    setScreenName(this->objectName());
}

MainMenuScreen::~MainMenuScreen()
{
    delete ui;
}

auto MainMenuScreen::updateScreen() -> void
{

}

auto MainMenuScreen::on_userScreenButton_clicked() -> void
{
    emit next(new UserScreen());
}

auto MainMenuScreen::on_settingScreenButton_clicked() -> void
{
    emit next(new SettingScreen());
}

} // namespace Screens
