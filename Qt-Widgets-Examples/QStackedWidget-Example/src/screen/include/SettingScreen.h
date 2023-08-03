#pragma once

#include "BaseScreen.h"

namespace Ui {
class SettingScreen;
}

namespace Screens {

class SettingScreen : public BaseScreen
{
    Q_OBJECT

public:
    explicit SettingScreen(QWidget* parent = nullptr);
    virtual ~SettingScreen();

private slots:
    auto on_logoutButton_clicked() -> void;

    void on_toUserScreenButton_clicked();

private:
    Ui::SettingScreen* ui;
};

} // namespace Screens
