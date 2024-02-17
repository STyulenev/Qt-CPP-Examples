#include "JsonFacade.h"

namespace JsonModel {

JsonFacade::JsonFacade(const QString& jsonString)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toUtf8());
    jsonObject = jsonDocument.object();
}

JsonFacade::~JsonFacade()
{

}

auto JsonFacade::getJsonValueByKey(const QString&& key) -> QJsonValue
{
    return jsonObject[key];
}

auto JsonFacade::getJsonArrayByKey(const QString&& key) -> QJsonArray
{
    return jsonObject[key].toArray();
}

auto JsonFacade::getUserList() -> UserListJson
{
    return UserListJson(jsonObject["users"].toArray());
}

} // namespace JsonModel
