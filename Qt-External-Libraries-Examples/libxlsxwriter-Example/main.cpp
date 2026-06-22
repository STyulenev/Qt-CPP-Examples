#include <QCoreApplication>
#include <QDebug>

#include "ExcelCreator.h"

auto main(int argc, char *argv[]) -> int
{
    //QCoreApplication app(argc, argv);

    try
    {
        const std::vector<Model::Data> data = {
            { 1, "Товар А", 10, 100 },
            { 2, "Товар Б", 5, 200 },
            { 3, "Товар В", 8, 150 },
            { 4, "Товар Г", 12, 120 },
            { 5, "Товар Д", 7, 250 },
            { 6, "Товар Е", 3, 300 }
        };

        ExcelCreators::DataCreator dataCreator("warehouse_example.xlsx");
        dataCreator.addWorksheet("Данные", data);
    }
    catch (...)
    {

    }

    return 0; // app.exec();
}
