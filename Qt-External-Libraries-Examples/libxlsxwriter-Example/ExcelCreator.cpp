#include "ExcelCreator.h"

#include <QDebug>

#include <stdexcept>

namespace ExcelCreators
{

DataCreator::DataCreator(const std::string& fileName)
{
    workbook = workbook_new(fileName.c_str());

    if (!workbook)
    {
        qDebug() << "Не удалось создать файл";
        throw std::runtime_error("Не удалось создать файл");
    }

    // Настройки формата для общего названия (большой шрифт, центрирование)
    title_format = workbook_add_format(workbook);
    format_set_bold(title_format);
    format_set_font_size(title_format, 14);
    format_set_align(title_format, LXW_ALIGN_CENTER);

    // Настройки с фоном для названий столбцов
    header_format = workbook_add_format(workbook);
    format_set_bold(header_format);
    format_set_bg_color(header_format, LXW_COLOR_LIME);
    format_set_align(header_format, LXW_ALIGN_CENTER);
    format_set_border(header_format, LXW_BORDER_THIN);

    // Настройки для данных
    data_format = workbook_add_format(workbook);
    format_set_border(data_format, LXW_BORDER_THIN);
}

DataCreator::~DataCreator()
{
    // Закрываем книгу
    workbook_close(workbook);

    qDebug() << "Файл создан: example.xlsx";
}

void DataCreator::addWorksheet(const std::string& worksheetName, const std::vector<Model::Data>& data)
{
    // Создаем лист с названием
    lxw_worksheet* worksheet = workbook_add_worksheet(workbook, worksheetName.c_str());

    // Создаем объединенную ячейку для общего названия
    worksheet_merge_range(worksheet, 0, 0, 0, 3, "Отчет по товарам", title_format);

    worksheet_set_column(worksheet, 0, 3, Model::Data::columns[1].length() + 4, nullptr);

    // Записываем названия столбцов с применением формата
    for (long long unsigned int i = 0; i < Model::Data::columns.size(); ++i)
    {
        worksheet_write_string(worksheet, 1, i, Model::Data::columns[i].c_str(), header_format);
    }

    const int row = 2; // Начинаем с 2-й строки (индекс 2)

    for (long long unsigned int i = 0; i < data.size(); ++i)
    {
        const long long unsigned int current_row = row + i;

        worksheet_write_number(worksheet, current_row, 0, data[i].id, data_format);
        worksheet_write_string(worksheet, current_row, 1, data[i].name.c_str(), data_format);
        worksheet_write_number(worksheet, current_row, 2, data[i].count, data_format);
        worksheet_write_number(worksheet, current_row, 3, data[i].price, data_format);
    }
}

} // namespace ExcelCreators
