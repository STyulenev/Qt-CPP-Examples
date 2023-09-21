#pragma once

#include "BaseScreen.h"

namespace Ui {
    class SettingScreen;
}

namespace Screens {

class SettingScreen final : public BaseScreen
{
    Q_OBJECT

private:
    Ui::SettingScreen* ui;

public:
    explicit SettingScreen(QWidget* parent = nullptr);
    virtual ~SettingScreen();

protected:
    virtual auto updateScreen() -> void override;
    virtual auto updateScreen(QVariant data) -> void override;

private slots:
    auto on_logoutButton_clicked() -> void;
    auto on_toUserScreenButton_clicked() -> void;
    auto on_backButton_clicked() -> void;

};

} // namespace Screens
