#pragma once

#include <QObject>
#include <QJSValue>

namespace Controllers {

class AssyncController : public QObject
{
    Q_OBJECT
public:
    explicit AssyncController(QObject* parent = nullptr);
    ~AssyncController();

public slots:
    AssyncController* run(const QJSValue& callback);

};

} // namespace Controllers
