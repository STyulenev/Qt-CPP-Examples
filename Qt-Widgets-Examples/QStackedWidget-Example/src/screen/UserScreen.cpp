#include "UserScreen.h"
#include "ui_UserScreen.h"

namespace Screens {

UserScreen::UserScreen(QWidget* parent) :
    BaseScreen(parent),
    ui(new Ui::UserScreen)
{
    ui->setupUi(this);
    setScreenName(this->objectName());
}

UserScreen::~UserScreen()
{
    delete ui;
}

auto UserScreen::updateScreen() -> void
{

}

auto UserScreen::updateScreen([[maybe_unused]] QVariant data) -> void
{

}

auto UserScreen::on_backButton_clicked() -> void
{
    emit back();
}

} // namespace Screens
