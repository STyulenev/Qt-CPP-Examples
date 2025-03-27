#pragma once

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>

namespace Controllers {

class SingletonClass : public QObject
{
    Q_OBJECT

private:
    SingletonClass(QObject* parent = nullptr);
    ~SingletonClass() = default;
    SingletonClass(const SingletonClass&);
    SingletonClass& operator=(SingletonClass&);

public:
    static SingletonClass* instance();

    enum class Message {
        Info,
        Debug,
        Warning,
        Error
    };
    Q_ENUM(Message)

    Q_INVOKABLE QString getMessage(Message message);

signals:
    void newMessage(QString message);

public slots:

private:
    static SingletonClass* self;
};

static QObject *singletonProvider(QQmlEngine* engine, QJSEngine* scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return SingletonClass::instance();
}

} // namespace Controllers
