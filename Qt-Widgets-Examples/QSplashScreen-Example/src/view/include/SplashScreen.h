#pragma once

#include <QSplashScreen>

namespace Ui {
    class SplashScreen;
}

namespace Views {

class SplashScreen : public QSplashScreen
{
    Q_OBJECT

private:
    Ui::SplashScreen* ui;

public:
    explicit SplashScreen(QWidget* parent = nullptr);
    virtual ~SplashScreen();

};

} // namespace Views
