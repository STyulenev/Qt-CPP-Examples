#pragma once

#include <QWidget>

namespace Ui {
    class WidgetWithTwoRadioButtons;
}

class WidgetWithTwoRadioButtons : public QWidget
{
    Q_OBJECT

private:
    Ui::WidgetWithTwoRadioButtons* ui;

public:
    explicit WidgetWithTwoRadioButtons(QWidget* parent = nullptr);
    virtual ~WidgetWithTwoRadioButtons();

    auto getStatus() const -> bool;
    auto setStatus(bool status) -> void;

};

