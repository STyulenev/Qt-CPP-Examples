#include <QCoreApplication>
#include <QDebug>

#include "PDFCreator.h"

int main()
{
    //QCoreApplication app(argc, argv);

    try
    {
        std::vector<Model::Data> data;

        for (int i = 0; i < 30; i++)
        {
            std::string name = "User" + std::to_string(i + 1);
            std::string age = std::to_string(20 + (i % 20));
            std::string desc = "This is a detailed description for user " +
                               std::to_string(i + 1) +
                               " with some additional text to demonstrate text wrapping";
            data.push_back({name, age, desc});
        }

        PDFCreators::DataCreator dataCreator("example.pdf");
        dataCreator.addPage("Report", data);
    }
    catch (...)
    {

    }

    return 0; // app.exec();
}
