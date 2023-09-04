#pragma once

#include "BaseScreen.h"

namespace Ui {
    class MainMenuScreen;
}

namespace Screens {

class MainMenuScreen final : public BaseScreen
{
    Q_OBJECT

private:
    Ui::MainMenuScreen* ui;

public:
    explicit MainMenuScreen(QWidget* parent = nullptr);
    virtual ~MainMenuScreen();

protected:
    virtual auto updateScreen() -> void override;
    virtual auto updateScreen(QVariant data) -> void override;

private slots:
    auto on_userScreenButton_clicked() -> void;
    auto on_settingScreenButton_clicked() -> void;
    auto on_closeButton_clicked() -> void;

};

} // namespace Screens
