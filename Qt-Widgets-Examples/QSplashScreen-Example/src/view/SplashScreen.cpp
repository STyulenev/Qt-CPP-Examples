#include "SplashScreen.h"
#include "ui_SplashScreen.h"

#include <QScreen>

namespace Views {

SplashScreen::SplashScreen(QWidget* parent) :
    QSplashScreen(QGuiApplication::screens().at(0)),
    ui(new Ui::SplashScreen)
{
    ui->setupUi(this);

    QScreen* screen = QApplication::screens().at(0);
    QSize size = screen->availableSize();

    resize(size.width() / 2, size.height() / 2);
    move((screen->geometry().width() - this->width()) / 2, (screen->geometry().height() - this->height()) / 2);
}

SplashScreen::~SplashScreen()
{
    delete ui;
}

} // namespace Views
