#pragma once

#include <QObject>

class QProcess;

namespace Controller {

class ConsoleProcess : public QObject
{
    Q_OBJECT
public:
    explicit ConsoleProcess(QObject* parent = nullptr);
    ~ConsoleProcess();

    auto getCurrentDirectoryPath() -> bool;
    // other command

private slots:
    void readyReadStandardOutput();
    void readyReadStandardError();

signals:
    void resultProcess(const QString& program, const QString& result);
    void errorProcess(const QString& program, const QString& error);

private:
    QProcess* consoleProcess;

};

} // namespace Controller
