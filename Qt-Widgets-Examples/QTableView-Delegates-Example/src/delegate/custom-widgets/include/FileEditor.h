#pragma once

#include <QWidget>

namespace Ui {
class FileEditor;
}

class FileEditor : public QWidget
{
    Q_OBJECT

public:
    explicit FileEditor(QWidget* parent = nullptr);
    ~FileEditor();

    auto getImage() -> QByteArray&;
    auto setImage(QByteArray& newImage) -> void;

private slots:
    auto on_pushButton_clicked() -> void;

private:
    Ui::FileEditor* ui;
    QByteArray image;

    auto updateImage() -> void;
};

