#pragma once

#include <QWidget>

namespace Ui {
    class ColorEditor;
}

class ColorEditor : public QWidget
{
    Q_OBJECT

private:
    Ui::ColorEditor* ui;
    QColor color;

public:
    explicit ColorEditor(QWidget* parent = nullptr);
    virtual ~ColorEditor();

    auto getColor() -> QString;
    auto setColor(QString& color) -> void;

private:
    auto updateColor() -> void;

private slots:
    auto on_pushButton_clicked() -> void;

};

