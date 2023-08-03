#pragma once

#include "BaseScreen.h"

namespace Ui {
class UserScreen;
}

namespace Screens {

class UserScreen : public BaseScreen
{
    Q_OBJECT

public:
    explicit UserScreen(QWidget* parent = nullptr);
    virtual ~UserScreen();

private slots:
    auto on_backButton_clicked() -> void;

private:
    Ui::UserScreen* ui;

};

} // namespace Screens
