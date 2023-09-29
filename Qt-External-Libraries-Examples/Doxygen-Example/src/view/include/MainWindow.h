/**
 * \file
 * \page MainWindow MainWindow
 * \brief Заголовочный файл главного окна приложения
 * \class MainWindow
 * \author Sergey Tyulenev
 * \date 27.09.2023
 * \see journalmeteo.h ...
 */
#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Views {

/*!
 * \brief Класс для главного окна приложения
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui; ///< UI поле, автогенерируемое из .ui файла Qt дизайнером

public:
    /*!
     * \brief Конструктор MainWindow
     * \param parent - родительский класс
     */
    explicit MainWindow(QWidget* parent = nullptr);

    /*!
     * \brief Деструктор ~MainWindow
     */
    virtual ~MainWindow();

};

} // namespace Views
