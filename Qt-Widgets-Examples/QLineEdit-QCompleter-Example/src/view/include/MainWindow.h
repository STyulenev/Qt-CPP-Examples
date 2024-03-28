#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace ViewModels {
    class ListViewModel;
}

class QCompleter;

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private slots:
    auto on_okButton_clicked() -> void;

private:
    Ui::MainWindow* ui;
    ViewModels::ListViewModel* listViewModel;
    QCompleter* completer;

};

} // namespace Views
