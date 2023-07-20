#pragma once

#include <QDialog>

class QWebView;

namespace Print {



class ReportView final : public QDialog
{
    Q_OBJECT

private:
    QWebView* webView;

    QString title;
    QString from;
    QString to;
    QString mainText;
    QPixmap logo;

public:
    explicit ReportView(QWidget* parent = nullptr);
    virtual ~ReportView() = default;

    void setTitle(const QString& value);
    void setFrom(const QString& value);
    void setTo(const QString& value);
    void setLogo(const QPixmap& value);
    void setMainText(const QString& value);

private:
    const QString pixmapToString(const QPixmap& pixmap) const;

private slots:
    void close();
    void apply();
    void addJSObject();

public slots:
    QString getTitle() const;
    QString getFrom() const;
    QString getTo() const;
    QString getLogo() const;
    QString getMainText() const;
    QString getDateTime() const;

};

} // namespace Print
