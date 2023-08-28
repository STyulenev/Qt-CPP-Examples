#pragma once

#include "BaseScreen.h"

namespace Ui {
class SplashScreen;
}

namespace Screens {

class SplashScreen final : public BaseScreen
{
    Q_OBJECT

private:
    Ui::SplashScreen* ui;

public:
    explicit SplashScreen(QWidget* parent = nullptr);
    virtual ~SplashScreen();

    virtual auto updateScreen() -> void override;

};

} // namespace Screens
