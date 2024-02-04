#pragma once

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;

class NetworkManager : public QObject
{
    Q_OBJECT

public:
    NetworkManager(QObject* parent = nullptr);
    ~NetworkManager();

    void getTime();
    void getUsers();
    void postUsers();

    QByteArray getReply(QNetworkReply* reply);

private:
    QNetworkAccessManager* networkManager;

};
