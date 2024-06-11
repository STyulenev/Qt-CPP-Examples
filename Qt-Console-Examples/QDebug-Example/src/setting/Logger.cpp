#include "Logger.h"

#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QTime>

namespace Settings {

Logger* Logger::self = 0;

Logger::Logger(QObject* parent) :
    QObject(parent)
{
    // Если требуется очищать файл
    //clearLogFile();
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
    FILE* logFile = fopen(qPrintable(m_logFileName), "w+");

    if (!logFile) {
        fclose(logFile);
    }
}

void Logger::printToLogFile(const QString& messageText)
{
    FILE* logFile = fopen(qPrintable(m_logFileName), "a+");

    if (!logFile) {
        printf("Log %s file not writable\n", qPrintable(m_logFileName));
        return;
    }

    fprintf(logFile, "%s", qPrintable(messageText));
    fclose(logFile);
}

void Logger::myMessageOutput(QtMsgType type, const QMessageLogContext& context, const QString& messageText)
{
    Q_UNUSED(context)

    QString logMessage;

    switch (type) {
    case QtMsgType::QtDebugMsg:
        logMessage = QString("[%1] [DEBUG] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    case QtMsgType::QtWarningMsg:
        logMessage = QString("[%1] [WARNING] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    case QtMsgType::QtCriticalMsg:
        logMessage = QString("[%1] [CRITICAL] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    case QtMsgType::QtFatalMsg:
        logMessage = QString("[%1] [FATAL ERROR] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    case QtMsgType::QtInfoMsg:
        logMessage = QString("[%1] [NFORMATION] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    }

#ifdef QT_DEBUG
    QTextStream(stdout) << logMessage;
#else
    self->printToLogFile(logMessage);
#endif

    if (type == QtMsgType::QtFatalMsg)
        exit(-1);
}

void Logger::setDebugMessageHandler()
{
    m_logFileName = qApp->applicationDirPath() + "/log.txt";

    qInstallMessageHandler(myMessageOutput);
}

} // namespace Settings
