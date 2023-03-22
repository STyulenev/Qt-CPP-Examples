#pragma once

#include <QWidget>

namespace Ui {
class CustomWidget;
}

namespace View {

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomWidget(QWidget* parent = nullptr);
    virtual ~CustomWidget();

    auto setImage(const QString&& icon) -> void;
    auto setTitle(const QString&& title) -> void;
    auto setDescription(const QString&& description) -> void;

private:
    Ui::CustomWidget* ui;
};

} // namespace View
