#include <QCoreApplication>

#include <boost/date_time/posix_time/posix_time.hpp>

auto main(int argc, char *argv[]) -> int
{
    QCoreApplication app(argc, argv);

    boost::posix_time::ptime datetime = boost::posix_time::microsec_clock::universal_time();

    std::cout << "Current Time and Date: " << datetime << std::endl;

    return app.exec();
}
