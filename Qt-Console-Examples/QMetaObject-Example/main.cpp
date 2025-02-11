#include <QCoreApplication>
#include <QDebug>
#include <QVariant>

#include <SomeModel1.h>
#include <SomeModel2.h>

auto main(int argc, char* argv[]) -> int
{
    QCoreApplication app(argc, argv);

    { // QMetaType
        QVariant var = QVariant::fromValue(Models::SomeModel1());

        if (someClass1TypeId == var.typeId()) {
            qDebug() << qvariant_cast<Models::SomeModel1>(var);
        } else {
            switch (var.typeId()) {
            case QMetaType::QString:
                // ...
                break;
            default:
                break;
            }
        }
    }

    { // QMetaObject::invokeMethod
        auto someClass2 = Models::SomeModel2();

        bool status1 = QMetaObject::invokeMethod(&someClass2, "setData", Q_ARG(QString, "123"));

        if (status1) {
            qDebug() << "OK";
        }

        QString data;
        bool status2 = QMetaObject::invokeMethod(&someClass2, "getData", Q_RETURN_ARG(QString, data));

        if (status2) {
            qDebug() << data;
        }
    }

    return app.exec();
}
