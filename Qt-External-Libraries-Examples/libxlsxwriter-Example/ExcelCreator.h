#pragma once

#include "Model.h"

#include <xlsxwriter.h>

namespace ExcelCreators
{

class DataCreator
{
private:
    lxw_workbook* workbook;
    lxw_format*  title_format;
    lxw_format*  header_format;
    lxw_format*  data_format;

public:
    DataCreator() = delete;
    DataCreator(const std::string& fileName);
    ~DataCreator();

    void addWorksheet(const std::string& worksheetName, const std::vector<Model::Data>& data);
};

} // namespace ExcelCreators
