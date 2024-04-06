#pragma once

#include <QMainWindow>

#include <vector>

#include "TestModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    auto on_printAllButton_clicked() -> void;
    auto on_printOnlyMaleButton_clicked() -> void;
    auto on_printAdultsButton_clicked() -> void;
    auto on_printMaleAndFemaleCountButton_clicked() -> void;

private:
    Ui::MainWindow* ui;
    std::vector<Models::TestModel> m_people;

};

} // namespace Views
