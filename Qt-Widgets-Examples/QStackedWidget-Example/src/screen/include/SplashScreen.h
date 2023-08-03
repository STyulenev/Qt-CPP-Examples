#pragma once

#include "BaseScreen.h"

namespace Ui {
class SplashScreen;
}

namespace Screens {

class SplashScreen : public BaseScreen
{
    Q_OBJECT

public:
    explicit SplashScreen(QWidget* parent = nullptr);
    virtual ~SplashScreen();

private:
    Ui::SplashScreen* ui;

};

} // namespace Screens
