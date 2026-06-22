#pragma once

#include <string>
#include <vector>

namespace Model
{

struct Data
{
    int         id;
    std::string name;
    int         count;
    int         price;

    // Названия столбцов
    static const std::vector<std::string> columns;
};

// Определение вне структуры
inline const std::vector<std::string> Data::columns = { "ID", "Наименование", "Количество", "Цена" };

} // namespace Model
