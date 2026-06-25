#include "PDFCreator.h"

#include <QDebug>

#include <stdexcept>

// Глобальные параметры страницы
struct PageSettings
{
    float pageHeight;
    float bottomMargin;
    float topMargin;
};

// Обработчик ошибок LibHaru
static void error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data)
{
    qDebug() << "HPDF Error: error_no=" << (unsigned int)error_no << "detail_no=\n" << (unsigned int)detail_no;
    throw std::runtime_error("HPDF Error");
}

// Функция для рисования заголовка
static void DrawReportTitle(HPDF_Page page, const std::string& title, float pageWidth, float pageHeight, float topMargin, float fontSize, HPDF_Font font)
{
    HPDF_Page_SetFontAndSize(page, font, fontSize);

    const float textWidth = HPDF_Page_TextWidth(page, title.c_str());
    const float x = (pageWidth - textWidth) / 2; // по центру
    const float y = pageHeight - topMargin;

    HPDF_Page_BeginText(page);
    HPDF_Page_TextOut(page, x, y, title.c_str());
    HPDF_Page_EndText(page);
}

// Функция для измерения текста (альтернатива HPDF_Font_MeasureText)
static HPDF_UINT MeasureText(HPDF_Font font, const char* text, HPDF_UINT len, float width, float fontSize, HPDF_UINT* char_count)
{
    HPDF_UINT chars = 0;
    float currentWidth = 0;

    for (HPDF_UINT i = 0; i < len; i++)
    {
        HPDF_TextWidth charWidth = HPDF_Font_TextWidth(font, (const HPDF_BYTE*)&text[i], 1);
        float charWidthPoints = charWidth.width * fontSize / 1000.0;

        if (currentWidth + charWidthPoints > width)
        {
            break;
        }

        currentWidth += charWidthPoints;
        chars++;
    }

    if (char_count)
    {
        *char_count = chars;
    }

    return chars;
}

// Функция для печати текста с переносом по словам
static void printWrappedText(HPDF_Page page, const std::string& text, float x, float y, float width, float lineHeight, HPDF_Font font, float fontSize)
{
    HPDF_Page_SetFontAndSize(page, font, fontSize);
    HPDF_Page_BeginText(page);

    std::string remaining = text;
    float currentY = y - 16;
    float minY = 0;

    while (!remaining.empty())
    {
        // Измеряем, сколько символов помещается
        HPDF_UINT len = MeasureText(font, remaining.c_str(), remaining.length(), width, fontSize, NULL);

        if (len == 0)
        {
            break;
        }

        // Находим последний пробел
        std::string line = remaining.substr(0, len);
        size_t lastSpace = line.find_last_of(' ');

        if (lastSpace != std::string::npos && lastSpace > 0)
        {
            line = line.substr(0, lastSpace);
        }

        // Выводим строку
        HPDF_Page_TextOut(page, x, currentY, line.c_str());

        // Переходим к остатку
        remaining = remaining.substr(line.length());
        if (!remaining.empty() && remaining[0] == ' ')
        {
            remaining = remaining.substr(1);
        }

        currentY -= lineHeight;
        if (currentY < minY)
        {
            break;
        }
    }

    HPDF_Page_EndText(page);
}

// Функция для вычисления количества строк
static int CountLines(const std::string& text, HPDF_Font font, float fontSize, float width)
{
    if (text.empty())
    {
        return 1;
    }

    std::string remaining = text;
    int lines = 1;

    while (!remaining.empty())
    {
        HPDF_UINT len = MeasureText(font, remaining.c_str(), remaining.length(), width, fontSize, NULL);

        if (len == 0)
        {
            break;
        }

        std::string line = remaining.substr(0, len);
        size_t lastSpace = line.find_last_of(' ');

        if (lastSpace != std::string::npos && lastSpace > 0)
        {
            line = line.substr(0, lastSpace);
        }

        remaining = remaining.substr(line.length());

        if (!remaining.empty() && remaining[0] == ' ')
        {
            remaining = remaining.substr(1);
        }

        if (!remaining.empty())
        {
            lines++;
        }
    }

    return lines;
}

// Функция для создания новой страницы с заголовком
static HPDF_Page CreateNewPage(HPDF_Doc pdf,
                               HPDF_Page& page,
                               const std::vector<float>& colWidths,
                               float startX,
                               float headerHeight,
                               HPDF_Font font,
                               float fontSize,
                               const PageSettings& settings)
{

    HPDF_Page newPage = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(newPage, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);

    HPDF_Page_SetFontAndSize(newPage, font, fontSize);
    HPDF_Page_SetLineWidth(newPage, 1);

    float y = settings.pageHeight - settings.topMargin - 50;
    float x = startX;

    // Заголовок
    float tableWidth = 0;
    for (size_t i = 0; i < colWidths.size(); i++)
    {
        tableWidth += colWidths[i];
    }

    HPDF_Page_SetRGBFill(newPage, 0.8, 0.8, 0.8);
    HPDF_Page_Rectangle(newPage, x, y, tableWidth, headerHeight);
    HPDF_Page_Fill(newPage);

    HPDF_Page_SetRGBStroke(newPage, 0, 0, 0);
    float currentX = x;

    for (size_t i = 0; i < colWidths.size(); i++)
    {
        HPDF_Page_Rectangle(newPage, currentX, y, colWidths[i], headerHeight);
        HPDF_Page_Stroke(newPage);
        currentX += colWidths[i];
    }

    HPDF_Page_SetRGBFill(newPage, 0, 0, 0);
    currentX = x;

    for (size_t i = 0; i < Model::Data::columns.size(); i++)
    {
        float textWidth = HPDF_Page_TextWidth(newPage, Model::Data::columns[i].c_str());
        float textX = currentX + (colWidths[i] - textWidth) / 2;
        float textY = y + (headerHeight - fontSize) / 2 + fontSize * 0.3;
        HPDF_Page_BeginText(newPage);
        HPDF_Page_TextOut(newPage, textX, textY, Model::Data::columns[i].c_str());
        HPDF_Page_EndText(newPage);
        currentX += colWidths[i];
    }

    return newPage;
}

// Основная функция рисования таблицы
static void drawTableWithPagination(HPDF_Doc pdf,
                                    HPDF_Page& page,
                                    const std::vector<Model::Data>& data,
                                    std::vector<float>& colWidths,
                                    float rowHeight,
                                    HPDF_Font font,
                                    float fontSize,
                                    float tableWidth,
                                    const PageSettings& settings,
                                    const std::string& title)
{

    int numCols = Model::Data::columns.size();

    if (numCols == 0)
    {
        return;
    }

    float headerFontSize = 20; // размер шрифта для заголовка
    float titleHeight = headerFontSize + 10; // высота заголовка

    DrawReportTitle(page, title, HPDF_Page_GetWidth(page), settings.pageHeight, settings.topMargin, headerFontSize, font);

    // Вычисляем ширину последнего столбца

    // Вычисляем ширину последнего столбца
    float sumPrevWidths = 0;
    for (int i = 0; i < numCols - 1; ++i)
    {
        sumPrevWidths += colWidths[i];
    }
    colWidths[numCols - 1] = tableWidth - sumPrevWidths;

    const float startX = 50;
    const float startY = settings.pageHeight - settings.topMargin - 50;
    float currentY = startY;
    float headerHeight = rowHeight;

    // Рисуем заголовок на первой странице
    float x = startX;
    float y = currentY - titleHeight;

    HPDF_Page_SetRGBFill(page, 0.8, 0.8, 0.8);
    HPDF_Page_Rectangle(page, x, y, tableWidth, headerHeight);
    HPDF_Page_Fill(page);

    HPDF_Page_SetLineWidth(page, 1);
    HPDF_Page_SetRGBStroke(page, 0, 0, 0);

    float currentX = x;
    for (int i = 0; i < numCols; i++)
    {
        HPDF_Page_Rectangle(page, currentX, y, colWidths[i], headerHeight);
        HPDF_Page_Stroke(page);
        currentX += colWidths[i];
    }

    HPDF_Page_SetFontAndSize(page, font, fontSize);
    HPDF_Page_SetRGBFill(page, 0, 0, 0);
    currentX = x;

    for (int i = 0; i < numCols; i++)
    {
        float textWidth = HPDF_Page_TextWidth(page, Model::Data::columns[i].c_str());
        float textX = currentX + (colWidths[i] - textWidth) / 2;
        float textY = y + (headerHeight - fontSize) / 2 + fontSize * 0.3;
        HPDF_Page_BeginText(page);
        HPDF_Page_TextOut(page, textX, textY, Model::Data::columns[i].c_str());
        HPDF_Page_EndText(page);
        currentX += colWidths[i];
    }

    currentY -= headerHeight + 16 + titleHeight;

    // Обрабатываем строки
    for (size_t rowIdx = 0; rowIdx < data.size(); rowIdx++)
    {
        const auto& row = data[rowIdx];

        // Определяем количество строк для последнего столбца
        int numLines = CountLines(row.desc, font, fontSize, colWidths[numCols - 1] - 10);

        // Высота строки с учётом переноса
        float currentRowHeight = rowHeight;
        float calculatedHeight = numLines * (fontSize * 1.5f + 4.0f);
        if (calculatedHeight > currentRowHeight)
        {
            currentRowHeight = calculatedHeight;
        }

        // Проверяем место на странице
        if (currentY - currentRowHeight < settings.bottomMargin)
        {
            page = CreateNewPage(pdf, page, colWidths, startX, headerHeight, font, fontSize, settings);
            currentY = startY - headerHeight - 16;
        }

        y = currentY;
        x = startX;

        // Рисуем границы строки
        currentX = x;
        for (int i = 0; i < numCols; i++)
        {
            HPDF_Page_Rectangle(page, currentX, y, colWidths[i], currentRowHeight);
            HPDF_Page_Stroke(page);
            currentX += colWidths[i];
        }

        // Заполняем ячейки
        currentX = x;

        // Столбец 0: Name
        {
            float textWidth = HPDF_Page_TextWidth(page, row.name.c_str());
            float textX = currentX + (colWidths[0] - textWidth) / 2;
            float textY = y + (currentRowHeight - fontSize) / 2 + fontSize * 0.3f;
            HPDF_Page_BeginText(page);
            HPDF_Page_SetFontAndSize(page, font, fontSize);
            HPDF_Page_TextOut(page, textX, textY, row.name.c_str());
            HPDF_Page_EndText(page);
        }
        currentX += colWidths[0];

        // Столбец 1: Age
        {
            float textWidth = HPDF_Page_TextWidth(page, row.age.c_str());
            float textX = currentX + (colWidths[1] - textWidth) / 2;
            float textY = y + (currentRowHeight - fontSize) / 2 + fontSize * 0.3f;
            HPDF_Page_BeginText(page);
            HPDF_Page_SetFontAndSize(page, font, fontSize);
            HPDF_Page_TextOut(page, textX, textY, row.age.c_str());
            HPDF_Page_EndText(page);
        }
        currentX += colWidths[1];

        // Столбец 2: Description (с переносом)
        {
            float cellTop = y + currentRowHeight - 5;
            float cellLeft = currentX + 5;
            float cellWidth = colWidths[2] - 10;
            float lineHeight = fontSize * 1.5f;
            printWrappedText(page, row.desc, cellLeft, cellTop, cellWidth, lineHeight, font, fontSize);
        }
        // currentX += colWidths[2]; // не обязательно

        currentY -= currentRowHeight;
    }
}

namespace PDFCreators
{

DataCreator::DataCreator(const std::string& fileName) : fileName(fileName)
{
    pdf = HPDF_New(error_handler, NULL);

    if (!pdf)
    {
        qDebug() << "Не удалось создать файл";
        throw std::runtime_error("Не удалось создать файл");
    }
}

DataCreator::~DataCreator()
{
    HPDF_SaveToFile(pdf, fileName.c_str());
    HPDF_Free(pdf);

    qDebug() << "Файл создан: " << fileName;
}

void DataCreator::addPage(const std::string& title, const std::vector<Model::Data>& data)
{
    HPDF_Page page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);

    PageSettings settings;
    settings.pageHeight = HPDF_Page_GetHeight(page);
    settings.topMargin = 50;
    settings.bottomMargin = 50;

    HPDF_Font font = HPDF_GetFont(pdf, "Helvetica", NULL);

    float pageWidth = HPDF_Page_GetWidth(page);
    float leftMargin = 50;
    float rightMargin = 50;
    float tableWidth = pageWidth - leftMargin - rightMargin;

    std::vector<float> colWidths = {100, 70, 0};
    float rowHeight = 50;
    float fontSize = 12;

    drawTableWithPagination(pdf, page, data, colWidths, rowHeight, font, fontSize, tableWidth, settings, title);
}

} // namespace PDFCreators
