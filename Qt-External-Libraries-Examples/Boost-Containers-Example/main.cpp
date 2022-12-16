#include "containers-examples/include/BoostSequenceContainer.h"
#include "containers-examples/include/BoostAssociativeContainer.h"

auto main(int argc, char* argv[]) -> int
{
    /// Последовательные контейнеры
    //BoostSequenceContainer::exampleBoostArray();
    //BoostSequenceContainer::exampleBoostVector();
    //BoostSequenceContainer::exampleBoostList();
    //BoostSequenceContainer::exampleBoostDeque();

    /// Ассоциативные контейнеры
    //BoostAssociativeContainer::exampleBoostSet();
    //BoostAssociativeContainer::exampleBoostMultiSet();
    BoostAssociativeContainer::exampleBoostMap();
    //BoostAssociativeContainer::exampleBoostMultiMap();

    //BoostAssociativeContainer::exampleBoostUnorderedSet();
    //BoostAssociativeContainer::exampleBoostUnorderedMultiSet();
    //BoostAssociativeContainer::exampleBoostUnorderedMap();
    //BoostAssociativeContainer::exampleBoostUnorderedMultiMap();

    return 0;
}
