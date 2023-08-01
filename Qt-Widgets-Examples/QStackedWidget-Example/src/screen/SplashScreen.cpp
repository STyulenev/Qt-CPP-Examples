#include "SplashScreen.h"
#include "ui_SplashScreen.h"

#include <QTimer>

#include "AuthenticationScreen.h"

namespace Screens {

SplashScreen::SplashScreen() :
    ui(new Ui::SplashScreen)
{
    ui->setupUi(this);

    QTimer::singleShot(3000, this, [this]() -> void {
        replace(new AuthenticationScreen());
    });
}

SplashScreen::~SplashScreen()
{
    delete ui;
}

} // namespace Screens
