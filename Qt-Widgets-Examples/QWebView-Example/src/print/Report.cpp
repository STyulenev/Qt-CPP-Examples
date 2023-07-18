#include "Report.h"

#include <QWebView>
#include <QWebFrame>
#include <QPushButton>
#include <QPushButton>
#include <QGridLayout>
#include <QApplication>
#include <QScreen>
#include <QPrinter>
#include <QWebSettings>
#include <QDateTime>
#include <QBuffer>

namespace Print {

ReportView::ReportView(QWidget* parent) :
    QDialog(parent),
    logo(QPixmap(":/res/image/Logo.png"))
{
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);

    webView = new QWebView(this);

    QGridLayout* grid = new QGridLayout(this);

    QPushButton* closeButton = new QPushButton("Отмена", this);
    QPushButton* applyButton = new QPushButton("Сохранить", this);

    connect(closeButton, &QPushButton::clicked, this, &ReportView::close);
    connect(applyButton, &QPushButton::clicked, this, &ReportView::apply);
    connect(webView->page()->mainFrame(), &QWebFrame::javaScriptWindowObjectCleared, this, &ReportView::addJSObject);

    webView->load(QUrl::fromUserInput("qrc:/res/html/report.html"));

    grid->addWidget(webView,      1, 0, 2, 4);
    grid->addWidget(closeButton,  3, 2, 1, 1);
    grid->addWidget(applyButton,  3, 3, 1, 1);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setLayout(grid);

    QScreen* screen = QApplication::screens().at(0);
    QSize size = screen->availableSize();

    resize(size.width() / 2, size.height() / 2);
}

void ReportView::addJSObject()
{
    webView->page()->mainFrame()->addToJavaScriptWindowObject(QString("report"), this);
}

void ReportView::close()
{
    reject();
}

void ReportView::apply()
{
    const QString saveLocation = "Report.pdf";

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(saveLocation);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    webView->print(&printer);
    //webView->render(&printer);

    accept();
}

QString ReportView::getMainText() const
{
    return mainText;
}

void ReportView::setMainText(const QString& value)
{
    mainText = value;
}

const QString ReportView::pixmapToString(const QPixmap& pixmap) const
{
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    pixmap.save(&buffer, "png");

    return QString("<img src=\"data:image/png;base64,") + byteArray.toBase64() + "\"/>";
}

QString ReportView::getDateTime() const
{
    // todo: UTC
    return QString("%1 (UTC %2)")
            .arg(QDateTime::currentDateTime().toString("dd.MM.yyyy hh.mm"))
            .arg("+ 03.00");
}

QString ReportView::getTitle() const
{
    return title;
}

void ReportView::setTitle(const QString& value)
{
    title = value;
}

QString ReportView::getFrom() const
{
    return from;
}

void ReportView::setFrom(const QString& value)
{
    from = value;
}

QString ReportView::getTo() const
{
    return to;
}

void ReportView::setTo(const QString& value)
{
    to = value;
}

QString ReportView::getLogo() const
{
    return pixmapToString(this->logo);
}

void ReportView::setLogo(const QPixmap& value)
{
    logo = value;
}

} // namespace Print
