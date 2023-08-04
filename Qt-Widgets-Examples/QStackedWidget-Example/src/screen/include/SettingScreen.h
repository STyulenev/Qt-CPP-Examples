#pragma once

#include "BaseScreen.h"

namespace Ui {
class SettingScreen;
}

namespace Screens {

class SettingScreen final : public BaseScreen
{
    Q_OBJECT

public:
    explicit SettingScreen(QWidget* parent = nullptr);
    virtual ~SettingScreen();

    virtual auto updateScreen() -> void override;

private slots:
    auto on_logoutButton_clicked() -> void;
    auto on_toUserScreenButton_clicked() -> void;
    auto on_backButton_clicked() -> void;

private:
    Ui::SettingScreen* ui;
};

} // namespace Screens
