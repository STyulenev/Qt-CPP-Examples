#pragma once

#include <QQuickImageProvider>

class ImageProvider : public QQuickImageProvider
{
public:
    explicit ImageProvider();
    virtual ~ImageProvider();

    virtual QPixmap requestPixmap(const QString& id, QSize* size, const QSize& requestedSize) override;
};
