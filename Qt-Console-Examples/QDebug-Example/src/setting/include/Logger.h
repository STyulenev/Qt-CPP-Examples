#pragma once

#include <QObject>

namespace Settings {

class Logger : public QObject
{
    Q_OBJECT

private:
    static Logger* self;

    explicit Logger(QObject* parent = nullptr);
    ~Logger();

public:
    Logger(const Logger&) = delete;
    Logger& operator=(Logger&) = delete;
    Logger(const Logger&&) = delete;
    Logger&& operator=(Logger&&) = delete;

    static Logger* instance();
    static void myMessageOutput(QtMsgType type, const QMessageLogContext& context, const QString& messageText);

    void setDebugMessageHandler();

protected:
    void printToLogFile(const QString& text);
    void clearLogFile();

    QString m_logFileName;

};

} // namespace Settings
