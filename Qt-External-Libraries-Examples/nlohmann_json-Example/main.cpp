#include <QCoreApplication>
#include <QDebug>

#include <nlohmann/json.hpp>

auto main(int argc, char *argv[]) -> int
{
    QCoreApplication app(argc, argv);

    using json = nlohmann::json;

    // Парсинг json
    {
        json j = json::parse(R"(
            {
                "first": 3.141,
                "second": true,
                "third": "some data",
                "data": {
                    "first": 3.142,
                    "second": false
                },
                "array": [ "1", "2", "3" ]
            }
            )");

        if (j.find("first") != j.end()) {
            qDebug() << "first = "  << j.find("first")->get<float>();
        }

        if (j.find("second") != j.end()) {
            qDebug() << "second = "  << j.find("second")->get<bool>();
        }

        if (j.find("third") != j.end()) {
            qDebug() << "third = "  << j.find("third")->get<std::string>();
        }

        if (j.find("data") != j.end()) {
            if (j.at("data").contains("first")) {
                qDebug() << "data.first = "  << j.at("data").at("first").get<float>();
            }

            if (j.at("data").contains("second")) {
                qDebug() << "data.second = "  << j.at("data").at("second").get<bool>();
            }
        }

        if (j.contains("array")) {
            auto &array = j["array"];

            for (auto& element : array) {
                qDebug() << element.get<std::string>() << "";
            }

            for (int index = 0; ; ++index) {
                if (!j["array"][index].is_null())
                    qDebug() << j["array"][index].get<std::string>();
                else
                    break;
            }
        }
    }

    return app.exec();
}
