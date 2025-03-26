#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QLockFile>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QLockFile lockFile(QDir::temp().absoluteFilePath("test.lock"));

    // Проверка блокировки главным потоком QLockFile файла,
    // если уже заблокирован, то приложение уже запущено.
    if (lockFile.tryLock(100)) {
        // ...
        // Основной код
        // ...

        return app.exec();
    } else {
        qDebug() << "Приложение уже запущено. Отмена текущего процесса.";
        return 1;
    }
}
