#pragma once

#include "Model.h"

#include <hpdf.h>

namespace PDFCreators
{

class DataCreator
{
private:
    HPDF_Doc pdf;
    std::string fileName;

public:
    DataCreator() = delete;
    DataCreator(const std::string& fileName);
    ~DataCreator();

    void addPage(const std::string& title, const std::vector<Model::Data>& data);
};

} // namespace PDFCreators
