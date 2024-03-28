#include "ConsoleProcess.h"

#include <QProcess>

#ifdef __linux
// ...
#elif __APPLE__
#elif defined _WIN32 || defined _WIN64
#include "Windows.h"
#else
// ...
#endif

namespace Controller {

ConsoleProcess::ConsoleProcess(QObject* parent) :
    QObject(parent)
{
    consoleProcess = new QProcess(this);

    connect(consoleProcess, &QProcess::readyReadStandardOutput, this, &ConsoleProcess::readyReadStandardOutput);
    connect(consoleProcess, &QProcess::readyReadStandardError, this, &ConsoleProcess::readyReadStandardError);

    consoleProcess->setProcessChannelMode(QProcess::SeparateChannels);
}

ConsoleProcess::~ConsoleProcess()
{

}

bool ConsoleProcess::getCurrentDirectoryPath()
{
#ifdef __linux
    consoleProcess->start("pwd");
#elif __APPLE__
    // ...
#elif defined _WIN32 || defined _WIN64
    consoleProcess->setProgram("cmd.exe");
    consoleProcess->setArguments({"", "cd", ""});
    consoleProcess->setCreateProcessArgumentsModifier([](QProcess::CreateProcessArguments* args) -> void {
        args->flags &= ~CREATE_NO_WINDOW;
    });
    consoleProcess->start();
#else
    // Unknown OS
#endif
    return consoleProcess->waitForFinished();
}

void ConsoleProcess::readyReadStandardOutput()
{
    QString output = consoleProcess->readAllStandardOutput();

#ifdef __linux
    output = output.trimmed();
#elif __APPLE__
    // ...
#elif defined _WIN32 || defined _WIN64
    output = output.split("\n").last();
#else
    // Unknown OS
#endif

    emit resultProcess(consoleProcess->program(), output);
}

void ConsoleProcess::readyReadStandardError()
{
    QString error = consoleProcess->readAllStandardError();

#ifdef __linux
    error = error.trimmed();
#elif __APPLE__
    // ...
#elif defined _WIN32 || defined _WIN64

#else
    // Unknown OS
#endif

    emit errorProcess(consoleProcess->program(), error);
}

} // namespace Controller
