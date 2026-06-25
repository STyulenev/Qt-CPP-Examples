#pragma once

#include <string>
#include <vector>

namespace Model
{

struct Data
{
    std::string name;
    std::string age;
    std::string desc;

    // Названия столбцов
    static const std::vector<std::string> columns;
};

// Определение вне структуры
inline const std::vector<std::string> Data::columns = { "ID", "Name", "Description" };

} // namespace Model
