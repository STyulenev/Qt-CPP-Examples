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

protected:
    virtual auto updateScreen() -> void override;
    virtual auto updateScreen(QVariant data) -> void override;

};

} // namespace Screens
