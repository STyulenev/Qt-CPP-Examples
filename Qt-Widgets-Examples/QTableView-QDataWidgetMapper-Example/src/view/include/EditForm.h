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
    virtual ~EditForm();

    auto setModel(QAbstractTableModel* model) -> void;
    auto editCurrentRow(int row) -> void;

private:
    Ui::EditForm* ui;
    std::shared_ptr<QDataWidgetMapper> mapper;

private slots:
    auto updateButtons(int row) -> void;

};

} // namespace View
