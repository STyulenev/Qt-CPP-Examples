#pragma once

#include "BaseScreen.h"

namespace Ui {
class UserScreen;
}

namespace Screens {

class UserScreen final : public BaseScreen
{
    Q_OBJECT

private:
    Ui::UserScreen* ui;

public:
    explicit UserScreen(QWidget* parent = nullptr);
    virtual ~UserScreen();

    virtual auto updateScreen() -> void override;

private slots:
    auto on_backButton_clicked() -> void;

};

} // namespace Screens
