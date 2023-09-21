#include "AuthenticationScreen.h"
#include "ui_AuthenticationScreen.h"

#include "ScreenFactory.h"

namespace Screens {

AuthenticationScreen::AuthenticationScreen(QWidget* parent) :
    BaseScreen(parent),
    ui(new Ui::AuthenticationScreen)
{
    ui->setupUi(this);
    setScreenName(this->objectName());
}

AuthenticationScreen::~AuthenticationScreen()
{
    delete ui;
}

auto AuthenticationScreen::updateScreen() -> void
{

}

auto AuthenticationScreen::updateScreen([[maybe_unused]] QVariant data) -> void
{

}

auto AuthenticationScreen::on_enterButton_clicked() -> void
{
    emit next(getScreen(ScreenName::MAIN_MENU_SCREEN));
}

} // namespace Screens
