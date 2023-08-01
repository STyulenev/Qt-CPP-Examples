#include "MainMenuScreen.h"
#include "ui_MainMenuScreen.h"

namespace Screens {

MainMenuScreen::MainMenuScreen() :
    ui(new Ui::MainMenuScreen)
{
    ui->setupUi(this);
    setScreenName(this->objectName());
}

MainMenuScreen::~MainMenuScreen()
{
    delete ui;
}

void MainMenuScreen::on_pushButton_clicked()
{
    //back();
    backTo("AuthenticationScreen");
}

} // namespace Screens
