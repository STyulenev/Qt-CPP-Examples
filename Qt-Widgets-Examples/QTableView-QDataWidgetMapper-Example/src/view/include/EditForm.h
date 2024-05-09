#pragma once

#include <QWidget>
#include <QAbstractTableModel>
#include <QDataWidgetMapper>

namespace Ui {
    class EditForm;
}

namespace View {

class EditForm : public QWidget
{
    Q_OBJECT

public:
    explicit EditForm(QWidget* parent = nullptr);
    ~EditForm();

    auto setModel(QAbstractTableModel* model) -> void;
    auto editCurrentRow(const int row) -> void;

private slots:
    auto updateButtons(const int row) -> void;

private:
    Ui::EditForm* ui;
    QDataWidgetMapper* mapper;

};

} // namespace View
