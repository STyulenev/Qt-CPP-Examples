#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QGraphicsItem;
class QGraphicsVideoItem;
class QGraphicsScene;
class QGraphicsTextItem;
class QMediaPlayer;

namespace Views {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private slots:
    auto on_pauseButton_clicked() -> void;
    auto on_playButton_clicked() -> void;
    auto on_openFileAction_triggered() -> void;

private:
    Ui::MainWindow* ui;

    QGraphicsScene* m_scene;
    QGraphicsVideoItem* m_videoItem;
    QMediaPlayer* m_mediaPlayer;
    QGraphicsItem* m_selectedItem;
    QGraphicsTextItem* m_textItem;

};

} // namespace Views
