#pragma once

#include <QWidget>

namespace Ui {
class WidgetWithTwoRadioButtons;
}

class WidgetWithTwoRadioButtons : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetWithTwoRadioButtons(QWidget* parent = nullptr);
    ~WidgetWithTwoRadioButtons();

    auto getStatus() -> bool;
    auto setStatus(bool status) -> void;

private:
    Ui::WidgetWithTwoRadioButtons* ui;
};

