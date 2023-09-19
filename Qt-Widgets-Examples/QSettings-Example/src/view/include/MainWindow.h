#pragma once

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

namespace Settings {
    class Originator;
    class Caretaker;
}

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui;

    Settings::Originator* originator;
    Settings::Caretaker* caretaker;

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private:
    auto setSetting() -> void;

private slots:
    auto on_saveButton_clicked() -> void;
    auto on_undoButton_clicked() -> void;
    auto on_redoButton_clicked() -> void;

};

} // namespace Views
