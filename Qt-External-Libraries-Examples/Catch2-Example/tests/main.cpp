#include <catch2/catch_session.hpp>

auto main(int argc, char* argv[]) -> int
{
    Catch::Session session;

    int result = session.applyCommandLine(argc, argv);
    if (result != 0)
        return result;

    return session.run();
}
