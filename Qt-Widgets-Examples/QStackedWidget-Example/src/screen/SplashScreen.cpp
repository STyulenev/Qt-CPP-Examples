#include "SplashScreen.h"
#include "ui_SplashScreen.h"

#include <QTimer>

#include "ScreenFactory.h"

namespace Screens {

SplashScreen::SplashScreen(QWidget* parent) :
    BaseScreen(parent),
    ui(new Ui::SplashScreen)
{
    ui->setupUi(this);
    setScreenName(this->objectName());

    QTimer::singleShot(3000, this, [this]() -> void {
        emit replace(getScreen(ScreenName::AUTHENTICATION_SCREEN));
    });
}

SplashScreen::~SplashScreen()
{
    delete ui;
}

auto SplashScreen::updateScreen() -> void
{

}

auto SplashScreen::updateScreen([[maybe_unused]] QVariant data) -> void
{

}

} // namespace Screens
