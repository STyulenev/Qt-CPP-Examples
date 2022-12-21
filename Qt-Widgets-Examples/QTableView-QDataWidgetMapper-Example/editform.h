#pragma once

#include <QWidget>
#include <QAbstractTableModel>
#include <QDataWidgetMapper>
#include <mutex>

namespace Ui {
class EditForm;
}

class EditForm : public QWidget
{
    Q_OBJECT

public:
    explicit EditForm(QWidget *parent = nullptr);
    ~EditForm();

    auto setModel(QAbstractTableModel* model) -> void;

    auto editCurrentRow(int row) -> void;

private:
    Ui::EditForm *ui;
    std::shared_ptr<QDataWidgetMapper> mapper;

    //std::once_flag flag;

    //auto setMMMM(QAbstractTableModel* model) -> void;

private slots:
    auto updateButtons(int row) -> void;
};

