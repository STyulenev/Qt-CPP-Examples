#include "DAO.h"

DAO::DAO()
{

}

auto DAO::getData() -> void
{
    std::shared_ptr<Connection> connection = std::make_shared<Connection>();

    if (connection->isOpen()) {
        qDebug() << "isOpen()";
    } else {
        qDebug() << "close()";
    }
}
