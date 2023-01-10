#include <QtCore>
#include <QCoreApplication>
#include <QtHttpServer/QtHttpServer>
#include <QtHttpServer/QHttpServerResponder>

auto main(int argc, char* argv[]) -> int
{
    QCoreApplication a(argc, argv);

    QHttpServer httpServer;

    const auto port = httpServer.listen(QHostAddress::Any, 8000);

    if (!port)
        return 0;

    qDebug() << QCoreApplication::translate("QHttpServerExample",
                "Running on http://127.0.0.1:%1/ (Press CTRL+C to quit)").arg(port);

    QJsonArray myData = { 1, 2.2, QString() };

    httpServer.route("/myApi", QHttpServerRequest::Method::Get, [&myData](const QHttpServerRequest &request) {
        QJsonArray array = myData;
        return QHttpServerResponse(array);
    });

    httpServer.route("/myApi", QHttpServerRequest::Method::Post, [&myData](const QHttpServerRequest &request) {
        qDebug() << request.value("text");
        qDebug() << request.value("_id");

        QJsonArray array = myData;
        return QHttpServerResponse(array);
    });

    /*httpServer.route("/blog/<arg>", QHttpServerRequest::Method::Post, [] (const QHttpServerRequest &req) {
        qDebug() << "blog";

        qDebug() << req.value("_id");
        return "error 404";
    });*/

    httpServer.route("/myApi/<arg>", QHttpServerRequest::Method::Get,
                     [&myData](int arg, const QHttpServerRequest &request) {

        auto query = request.query();
        qDebug() << "query =" << query.toString();
        qDebug() << "id =" << query.queryItemValue("id");
        qDebug() << "text =" << query.queryItemValue("text");

        qDebug() << "arg = " << arg;

        QJsonArray myApiObject = myData;
        return QHttpServerResponse(myApiObject);
    }
    );

    return a.exec();
}


/*if (req.method() == QHttpServerRequest::Method::Get)
            return "12";

        if (req.method() == QHttpServerRequest::Method::Post) {
            //qDebug() << req.value("text");*/
