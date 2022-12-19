#include "containers-examples/include/BoostSequenceContainer.h"
#include "containers-examples/include/BoostAssociativeContainer.h"
#include "containers-examples/include/BoostAdaptorContainer.h"

auto main(int argc, char* argv[]) -> int
{
    /// Последовательные контейнеры
    //BoostSequenceContainer::exampleBoostArray();
    //BoostSequenceContainer::exampleBoostVector();
    //BoostSequenceContainer::exampleBoostList();
    //BoostSequenceContainer::exampleBoostDeque();
    //BoostSequenceContainer::exampleBoostSmallVector();
    BoostSequenceContainer::exampleBoostDeVector();
    //BoostSequenceContainer::exampleBoostStableVector();
    //BoostSequenceContainer::exampleBoostCircularBuffer();

    /// Ассоциативные контейнеры
    //BoostAssociativeContainer::exampleBoostSet();
    //BoostAssociativeContainer::exampleBoostMultiSet();
    //BoostAssociativeContainer::exampleBoostMap();
    //BoostAssociativeContainer::exampleBoostMultiMap();

    //BoostAssociativeContainer::exampleBoostUnorderedSet();
    //BoostAssociativeContainer::exampleBoostUnorderedMultiSet();
    //BoostAssociativeContainer::exampleBoostUnorderedMap();
    //BoostAssociativeContainer::exampleBoostUnorderedMultiMap();

    /// Адапторы
    //BoostAdaptorContainer::exampleBoostFlatSet();
    //BoostAdaptorContainer::exampleBoostFlatMultiSet();
    //BoostAdaptorContainer::exampleBoostFlatMap();
    //BoostAdaptorContainer::exampleBoostFlatMultiMap();

    return 0;
}
