#pragma once

#include <QWidget>

namespace Ui {
class ColorEditor;
}

class ColorEditor : public QWidget
{
    Q_OBJECT

public:
    explicit ColorEditor(QWidget* parent = nullptr);
    ~ColorEditor();

    auto getColor() -> QString;
    auto setColor(QString& color) -> void;

private slots:
    auto on_pushButton_clicked() -> void;

private:
    Ui::ColorEditor* ui;
    QColor color;

    auto updateColor() -> void;
};

