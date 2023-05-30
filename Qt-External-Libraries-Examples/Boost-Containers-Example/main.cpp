#include "BoostSequenceContainer.h"
#include "BoostAssociativeContainer.h"
#include "BoostAdaptorContainer.h"
#include "BoostMultiIndex.h"
#include "BoostHeap.h"
#include "BoostIntrusive.h"

auto main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) -> int
{
    /// Последовательные контейнеры
    //BoostSequenceContainer::exampleBoostArray();
    //BoostSequenceContainer::exampleBoostVector();
    //BoostSequenceContainer::exampleBoostSList();
    //BoostSequenceContainer::exampleBoostList();
    //BoostSequenceContainer::exampleBoostDeque();
    //BoostSequenceContainer::exampleBoostSmallVector();
    //BoostSequenceContainer::exampleBoostDeVector();
    //BoostSequenceContainer::exampleBoostStableVector();
    //BoostSequenceContainer::exampleBoostCircularBuffer();

    /// Ассоциативные контейнеры
    //BoostAssociativeContainer::exampleBoostSet();
    //BoostAssociativeContainer::exampleBoostMultiSet();
    //BoostAssociativeContainer::exampleBoostMap();
    //BoostAssociativeContainer::exampleBoostMultiMap();
    //BoostAssociativeContainer::exampleBoostBimap();
    //BoostAssociativeContainer::exampleBoostMultiBimap();

    //BoostAssociativeContainer::exampleBoostUnorderedSet();
    //BoostAssociativeContainer::exampleBoostUnorderedMultiSet();
    //BoostAssociativeContainer::exampleBoostUnorderedMap();
    //BoostAssociativeContainer::exampleBoostUnorderedMultiMap();

    /// Адапторы
    //BoostAdaptorContainer::exampleBoostFlatSet();
    //BoostAdaptorContainer::exampleBoostFlatMultiSet();
    //BoostAdaptorContainer::exampleBoostFlatMap();
    //BoostAdaptorContainer::exampleBoostFlatMultiMap();

    /// Пользовательские контейнеры с множественным поиском
    //BoostMultiIndex::exampleBoostMultiIndex();
    //BoostMultiIndex::exampleBoostMultiIndex2();

    // Очередь с приоритетом
    //BoostHeap::exampleBoostPriorityQueue();
    //BoostHeap::exampleBoostBinomialHeap();
    //BoostHeap::exampleBoostFibonacciHeap();

    // Высокопроизводительные навязчивые контейнеры
    //BoostIntrusive::exampleBoostIntrusiveList();
    BoostIntrusive::exampleBoostIntrusiveSet();

    return 0;
}
