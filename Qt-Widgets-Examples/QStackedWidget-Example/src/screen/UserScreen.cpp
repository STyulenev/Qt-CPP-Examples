#include "UserScreen.h"
#include "ui_UserScreen.h"

namespace Screens {

UserScreen::UserScreen(QWidget* parent) :
    BaseScreen(parent),
    ui(new Ui::UserScreen)
{
    ui->setupUi(this);
}

UserScreen::~UserScreen()
{
    delete ui;
}

auto UserScreen::on_backButton_clicked() -> void
{
  back();
}

} // namespace Screens
