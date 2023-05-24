#pragma once

class ScopeExit
{
private:
    ScopeExit() = default;
    ~ScopeExit() = default;

public:
    /*!
     * \brief Пример RAII макроса BOOST_SCOPE_EXIT
     * \details
     * BOOST_SCOPE_EXIT — это макрос, объявляющий выход из области видимости. Выполнение тела выхода из области видимости происходит
     * на выходе из включающей области, которая должна быть локальной. BOOST_SCOPE_EXIT должен иметь список параметров в круглых скобках
     * и блок в фигурных скобках. Если выходы из нескольких областей объявлены в одной и той же объемлющей области, тела выхода области
     * выполняются в порядке, обратном их объявлениям.
     *
     * Заголовочный файл - #include <boost/scope_exit.hpp>
     */
    static auto ScopeExitExample() -> void;

};
