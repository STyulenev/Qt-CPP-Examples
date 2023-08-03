#pragma once

#include "BaseScreen.h"

namespace Ui {
class AuthenticationScreen;
}

namespace Screens {

class AuthenticationScreen : public BaseScreen
{
    Q_OBJECT

public:
    explicit AuthenticationScreen(QWidget* parent = nullptr);
    virtual ~AuthenticationScreen();

private slots:
    void on_enterButton_clicked();

private:
    Ui::AuthenticationScreen* ui;

};

} // namespace Screens
