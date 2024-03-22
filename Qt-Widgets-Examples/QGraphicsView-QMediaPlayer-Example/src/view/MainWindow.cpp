#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QGraphicsItem>
#include <QGraphicsVideoItem>
#include <QGraphicsScene>
#include <QMediaPlayer>

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_scene(new QGraphicsScene(this)),
    m_videoItem(new QGraphicsVideoItem()),
    m_mediaPlayer(new QMediaPlayer(this))
{
    ui->setupUi(this);

    m_textItem = new QGraphicsTextItem("Ошибка видеопотока!");
    m_textItem->setDefaultTextColor(Qt::red);
    m_textItem->setFont(QFont("Arial", 24));
    m_textItem->setPos(m_scene->width() / 2 - m_textItem->boundingRect().width() / 2, m_scene->height() / 2 - m_textItem->boundingRect().height() / 2);
    m_textItem->setFlag(QGraphicsItem::ItemIsSelectable, false);
}

MainWindow::~MainWindow()
{
    delete m_textItem;
    delete m_videoItem;
    delete ui;
}

auto MainWindow::on_pauseButton_clicked() -> void
{
    m_mediaPlayer->pause();
}

auto MainWindow::on_playButton_clicked() -> void
{
    m_mediaPlayer->play();
}

auto MainWindow::on_openFileAction_triggered() -> void
{
    const QString videoPath = QFileDialog::getOpenFileName(this, tr("Open video/movie"), "C:/", tr("Video files (*.mp4)"));

    if (!videoPath.isEmpty()) {
        ui->graphicsView->setScene(m_scene);

        m_videoItem->setSize(QSize(ui->graphicsView->width(), ui->graphicsView->height()));
        m_mediaPlayer->setVideoOutput(m_videoItem);
        m_mediaPlayer->setSource(QUrl(videoPath));

        m_scene->addItem(m_videoItem);
        m_videoItem->setPos(0, 0);

        m_mediaPlayer->play();

        connect(m_mediaPlayer, &QMediaPlayer::errorOccurred, this, [this](QMediaPlayer::Error error, const QString& errorText) -> void {
            Q_UNUSED(error)

            qDebug() << errorText;
            m_scene->addItem(m_textItem);
        });
    } else {
        // ошибка
    }
}

} // namespace Views
