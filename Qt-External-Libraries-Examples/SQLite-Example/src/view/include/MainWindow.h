#pragma once

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

namespace ViewModels {
    class PersonsViewModel;
}

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private:
    Ui::MainWindow* ui;
    ViewModels::PersonsViewModel* personsViewModel;

};

} // namespace Views
