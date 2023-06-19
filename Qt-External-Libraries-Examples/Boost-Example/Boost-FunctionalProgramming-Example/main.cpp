#include "BoostPhoenix.h"
#include "BoostFunction.h"
#include "BoostBindAndRef.h"

auto main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) -> int
{
    // Феникс функции
    //BoostPhoenix::exampleBoostPhoenix();
    //BoostPhoenix::exampleBoostPhoenixLazyStatements();

    // Функции
    //BoostFunction::exampleBoostFunction();
    //BoostFunction::exampleBoostFunctionBinding();

    // Биндинг функций
    //BoostBind::exampleBoostBind();
    //BoostBindAndRef::exampleBoostBindFunctions();
    BoostBindAndRef::exampleBoostRef();

    return 0;
}
