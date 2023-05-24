#include <SmartPointers.h>
#include <PointerContainer.h>
#include <ScopeExit.h>

auto main(int argc, char* argv[]) -> int
{
    // Smart Pointers examples
    //SmartPointers::SharedPointerExample();
    //SmartPointers::ScopedPointerExample();
    //SmartPointers::WeakPointerExample();

    // Pointer Containers examples
    //PointerContainer::PointerVectorExample();
    //PointerContainer::PointerListExample();

    // Scope Exit example
    ScopeExit::ScopeExitExample();

    return 0;
}
