#pragma once

#include <QWidget>

namespace Ui {
    class FileEditor;
}

class FileEditor : public QWidget
{
    Q_OBJECT

private:
    Ui::FileEditor* ui;
    QByteArray image;

public:
    explicit FileEditor(QWidget* parent = nullptr);
    virtual ~FileEditor();

    auto getImage() -> QByteArray&;
    auto setImage(QByteArray& newImage) -> void;

private:
    auto updateImage() -> void;

private slots:
    auto on_pushButton_clicked() -> void;

};

