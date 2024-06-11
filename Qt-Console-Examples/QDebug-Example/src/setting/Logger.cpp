#include "Logger.h"

#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QTime>

namespace Settings {

Logger* Logger::self = 0;

Logger::Logger(QObject* parent) :
    QObject(parent)
{

}

Logger::~Logger()
{

}

Logger* Logger::instance()
{
    if (!self) {
        self = new Logger();
    }

    return self;
}

void Logger::clearLogFile()
{
    FILE* pFile = fopen(qPrintable(m_logFileName), "w+");

    if (!pFile) {
        fclose(pFile);
    }
}

void Logger::printToLogFile(const QString &text)
{
    FILE* pFile = fopen(qPrintable(m_logFileName), "a+");

    if (!pFile) {
        printf("Log %s file not writable\n", qPrintable(m_logFileName));
        return;
    }

    fprintf(pFile, "%s", qPrintable(text));
    fclose(pFile);
}

void Logger::myMessageOutput(QtMsgType type, const QMessageLogContext& context, const QString& messageText)
{
    Q_UNUSED(context)

    QString logMessage;

    switch (type) {
    case QtDebugMsg:
        logMessage = QString("[%1] [DEBUG] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    case QtWarningMsg:
        logMessage = QString("[%1] [WARNING] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    case QtCriticalMsg:
        logMessage = QString("[%1] [CRITICAL] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    case QtFatalMsg:
        logMessage = QString("[%1] [FATAL ERROR] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    case QtInfoMsg:
        logMessage = QString("[%1] [NFORMATION] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    }

#ifdef QT_DEBUG
    QTextStream(stdout) << logMessage;
#else
    self->printToLogFile(logMessage);
#endif
}

void Logger::setDebugMessageHandler()
{
    m_logFileName = qApp->applicationDirPath() + "/log.txt";

    clearLogFile();

    qInstallMessageHandler(myMessageOutput);
}

} // namespace Settings
