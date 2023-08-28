#include "AuthenticationScreen.h"
#include "ui_AuthenticationScreen.h"

#include "MainMenuScreen.h"

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

auto AuthenticationScreen::on_enterButton_clicked() -> void
{
    emit next(new MainMenuScreen());
}

} // namespace Screens
