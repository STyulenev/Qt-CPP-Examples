#pragma once

#include <UserListJson.h>

namespace JsonModel {

class JsonFacade
{
private:
    QJsonObject jsonObject;

public:
    JsonFacade() = delete;
    explicit JsonFacade(const QString& jsonString);

    ~JsonFacade();

    auto getJsonValueByKey(const QString&& key) -> QJsonValue;

    auto getJsonArrayByKey(const QString&& key) -> QJsonArray;

    auto getUserList() -> UserListJson;

};

} // namespace JsonModel
