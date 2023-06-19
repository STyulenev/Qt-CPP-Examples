#include "BoostBindAndRef.h"

#include <boost/container/vector.hpp>

#include <boost/bind.hpp>
#include <boost/functional.hpp>

#include <boost/ref.hpp>

auto print(QDebug& debug, int i) -> void
{
    debug << i;
}

auto BoostBindAndRef::exampleBoostBind() -> void
{
    boost::container::vector<int> vector = { 1, 2, 3, 4, 5 };
    QDebug debug = qDebug();

    std::for_each(vector.begin(), vector.end(), boost::bind(print, debug, std::placeholders::_1));
}

auto bad(const int& number) -> bool
{
    return number > 0;
}

class TestClass {
private:
    int a;
public:
    TestClass(int a) :
        a(a)
    {

    }
    auto print(QDebug& debug) -> void {
        debug << this->a;
    }
};

auto BoostBindAndRef::exampleBoostBindFunctions() -> void
{
    { // boost::not1
        boost::container::vector<int> vector = { 1, 2, -3, 4, 5 };

        auto iterator = std::find_if(vector.begin(), vector.end(), boost::not1(bad));

        qDebug() << *iterator;
    }

    { // boost::bind2nd
        QDebug debug = qDebug();

        boost::container::vector<TestClass> vector;
        TestClass a(5);
        vector.push_back(a);

        std::for_each(vector.begin(), vector.end(), boost::bind2nd(boost::mem_fun_ref(&TestClass::print), debug));
    }
}

auto BoostBindAndRef::exampleBoostRef() -> void
{
    boost::container::vector<int> vector = { 1, 2, -3, 4, 5 };
    QDebug debug = qDebug();
    std::for_each(vector.begin(), vector.end(), boost::bind(print, boost::ref(debug), std::placeholders::_1));
}
