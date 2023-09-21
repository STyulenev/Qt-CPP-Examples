#include "MainMenuScreen.h"
#include "ui_MainMenuScreen.h"

#include "ScreenFactory.h"

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

auto MainMenuScreen::updateScreen(QVariant data) -> void
{
    qDebug() << data;
}

auto MainMenuScreen::on_userScreenButton_clicked() -> void
{
    emit next(getScreen(ScreenName::USER_SCREEN));
}

auto MainMenuScreen::on_settingScreenButton_clicked() -> void
{
    emit next(getScreen(ScreenName::SETTING_SCREEN));
}

auto MainMenuScreen::on_closeButton_clicked() -> void
{
    exit(0);
}

} // namespace Screens
