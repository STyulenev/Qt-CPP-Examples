#include "SplashScreen.h"
#include "ui_SplashScreen.h"

#include <QTimer>

#include "AuthenticationScreen.h"

namespace Screens {

SplashScreen::SplashScreen(QWidget* parent) :
    BaseScreen(parent),
    ui(new Ui::SplashScreen)
{
    ui->setupUi(this);
    setScreenName(this->objectName());

    QTimer::singleShot(3000, this, [this]() -> void {
        emit replace(new AuthenticationScreen());
    });
}

SplashScreen::~SplashScreen()
{
    delete ui;
}

auto SplashScreen::updateScreen() -> void
{

}

} // namespace Screens
