#pragma once

#include <QObject>

namespace Controller {

class FutureController : public QObject
{
    Q_OBJECT

public:
    explicit FutureController(QObject* parent = nullptr);
    ~FutureController();

    void example(const QString& text);

};

} // namespace Controller
