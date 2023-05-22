#pragma once

#include <QString>

namespace Network {

class HTTPClient
{
private:
    static HTTPClient* self;

    HTTPClient();
    ~HTTPClient();

    HTTPClient(const HTTPClient&);
    auto operator=(HTTPClient&) -> HTTPClient&;

public:
    static auto getClient() -> HTTPClient*;

    /*!
     * \brief getServerCurrentTime
     * \details
     * \code
     * // If there is json complex
     * if (!doc.isObject()) {
     *     // handle parse error...
     * }
     *
     * QJsonValue &users = doc["users"];
     *
     * if (users.isUndefined()) {
     *    // key "users" does not exist...
     * }
     * QJsonArray array = {
     *     users["name"],
     *     users["sex"],
     *     users["age"]
     * };
     *
     * // if only one array:
     *
     * QJsonDocument doc = QJsonDocument::fromJson(QString(response.c_str()).toUtf8());
     * QJsonArray array = doc.array();
     *
     * for (int i = 0; i < array.size(); i++) {
     *   qDebug() << array.at(i).toObject()["name"].toString() << array.at(i).toObject()["sex"].toString() << array.at(i).toObject()["age"].toString();
     * }
     *
     * \endcode
     * \return json as QString
     */
    auto getServerCurrentTime() -> QString;

    auto getServerUserList() -> QString;

    auto postServerSendNewUser() -> QString;

    auto deleteServerFirstUser() -> QString;

};

} // namespace Network
