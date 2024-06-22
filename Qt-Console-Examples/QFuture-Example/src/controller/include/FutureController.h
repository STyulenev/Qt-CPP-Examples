#pragma once

#include <QObject>
#include <QtConcurrent>

namespace Controller {

class FutureController : public QObject
{
    Q_OBJECT

public:
    explicit FutureController(QObject* parent = nullptr);
    ~FutureController();

    void example(const QString& text);
    void example2(const QString& text);

};

} // namespace Controller
