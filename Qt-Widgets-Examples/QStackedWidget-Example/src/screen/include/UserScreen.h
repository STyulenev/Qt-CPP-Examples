#pragma once

#include "BaseScreen.h"

namespace Ui {
class UserScreen;
}

namespace Screens {

class UserScreen final : public BaseScreen
{
    Q_OBJECT

public:
    explicit UserScreen(QWidget* parent = nullptr);
    virtual ~UserScreen();

    virtual auto updateScreen() -> void override;

private slots:
    auto on_backButton_clicked() -> void;

private:
    Ui::UserScreen* ui;

};

} // namespace Screens
