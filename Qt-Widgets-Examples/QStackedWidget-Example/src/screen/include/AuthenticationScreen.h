#pragma once

#include "BaseScreen.h"

namespace Ui {
class AuthenticationScreen;
}

namespace Screens {

class AuthenticationScreen final : public BaseScreen
{
    Q_OBJECT

private:
    Ui::AuthenticationScreen* ui;

public:
    explicit AuthenticationScreen(QWidget* parent = nullptr);
    virtual ~AuthenticationScreen();

    virtual auto updateScreen() -> void override;

private slots:
    auto on_enterButton_clicked() -> void;

};

} // namespace Screens
