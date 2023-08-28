#pragma once

#include <QMainWindow>

#include "Caretaker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
