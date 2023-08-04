#pragma once

#include "BaseScreen.h"

namespace Ui {
class SplashScreen;
}

namespace Screens {

class SplashScreen final : public BaseScreen
{
    Q_OBJECT

public:
    explicit SplashScreen(QWidget* parent = nullptr);
    virtual ~SplashScreen();

    virtual auto updateScreen() -> void override;

private:
    Ui::SplashScreen* ui;

};

} // namespace Screens
