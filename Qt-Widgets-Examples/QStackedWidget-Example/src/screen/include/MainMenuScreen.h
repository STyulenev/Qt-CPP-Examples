#pragma once

#include "BaseScreen.h"

namespace Ui {
class MainMenuScreen;
}

namespace Screens {

class MainMenuScreen : public BaseScreen
{
    Q_OBJECT

private:
    Ui::MainMenuScreen* ui;

public:
    explicit MainMenuScreen();
    virtual ~MainMenuScreen();

private slots:
    void on_pushButton_clicked();

};

} // namespace Screens
