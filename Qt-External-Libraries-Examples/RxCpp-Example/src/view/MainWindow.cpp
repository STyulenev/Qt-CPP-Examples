#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <rxcpp/rx-includes.hpp>
#include <thread>
#include <exception>
#include <stdexcept>

#include <QDebug>

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_people = {
        { "Karl", Models::TestModel::Sex::MALE,   20 },
        { "Anna", Models::TestModel::Sex::FEMALE, 30 },
        { "John", Models::TestModel::Sex::MALE,   54 },
        { "Kent", Models::TestModel::Sex::MALE,   17 }
    };
}

MainWindow::~MainWindow()
{
    delete ui;
}

auto MainWindow::on_printAllButton_clicked() -> void
{
    ui->textEdit->clear();

    auto values = rxcpp::observable<>::iterate(m_people);

    values.subscribe(
        [this](const Models::TestModel& person) -> void {
            ui->textEdit->append(person.getName());
        },
        [this]() -> void {
            qDebug() << "on_printAllButton_clicked()";
        });
}

auto MainWindow::on_printOnlyMaleButton_clicked() -> void
{
    ui->textEdit->clear();

    auto values = rxcpp::observable<>::iterate(m_people).filter([](const Models::TestModel& person) -> bool {
        return person.getSex() == Models::TestModel::Sex::MALE;
    });

    values.subscribe(
        [this](const Models::TestModel& person) -> void {
            ui->textEdit->append(person.getName());
        },
        [this]() -> void {
            qDebug() << "on_printOnlyMaleButton_clicked()";
        });
}

auto MainWindow::on_printAdultsButton_clicked() -> void
{
    auto values = rxcpp::observable<>::iterate(m_people).filter([](const Models::TestModel& person) -> bool {
        return person.getAge() >= 18;
    });

    // показать дескриптор главного потока
    qDebug() << "Main thread =>" << std::hash<std::thread::id>{}(std::this_thread::get_id());

    // наблюдатель в другом потоке выполнения
    values.observe_on(rxcpp::synchronize_new_thread()).as_blocking().subscribe(
        [this](const Models::TestModel& person) {
            ui->textEdit->append(QString("%1 %2").arg(person.getName()).arg(person.getAge()));
        },
        [](std::exception_ptr error) -> void {
            error = std::current_exception();

            try {
                if (error)
                    std::rethrow_exception(error);
            } catch(const std::exception& e) {
                qDebug() << "error: '" << e.what();
            }
        },
        []() -> void {
            qDebug() << "Observer thread => " << std::hash<std::thread::id>{}(std::this_thread::get_id());
        });
}

} // namespace Views
