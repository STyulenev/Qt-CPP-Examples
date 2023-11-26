#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#include <QDebug>

#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

#include <bsoncxx\builder\stream\document.hpp>
#include <mongocxx\instance.hpp>

namespace Views {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*{
          "first_name": "Tom",
          "last_name": "Smith",
          "age": 28,
          "languages": [
            "english",
            "spanish"
          ]
    }*/

    try {
        mongocxx::instance instance{}; // This should be done only once.
        mongocxx::uri uri("mongodb://localhost:27017");
        mongocxx::client client(uri);

        mongocxx::database db = client["test_db"];
        mongocxx::collection collection = db["users"];

        auto cursor_all = collection.find({});
        std::cout << "collection " << collection.name() << " contains these documents:" << std::endl;
        for (auto doc : cursor_all) {
            std::cout << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed) << std::endl;
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        // Handle errors.
        std::cout<< "Exception: " << e.what() << std::endl;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace Views
