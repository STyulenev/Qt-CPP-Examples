#include "BoostGeneric.h"

#include <boost/type_traits.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/fusion/container.hpp>
#include <boost/fusion/tuple.hpp>
#include <boost/fusion/algorithm.hpp>
#include <boost/fusion/iterator.hpp>
#include <boost/fusion/container.hpp>
#include <boost/fusion/sequence.hpp>
#include <boost/fusion/adapted.hpp>

auto BoostGeneric::exampleBoostTypeTraits() -> void
{
    qDebug() << boost::is_integral<int>::value; // является ли числом
    qDebug() << boost::is_floating_point<int>::value; // является ли именно числом с плавающей точкой
    qDebug() << boost::is_arithmetic<int>::value; // поддерживает ли арифметические операции
    qDebug() << boost::is_reference<int>::value; // ссылка или нет

    // сравнение
    qDebug() << boost::is_same<boost::is_integral<int>::type, boost::true_type>::value;
    qDebug() << boost::is_same<boost::is_floating_point<int>::type, boost::false_type>::value;
    qDebug() << boost::is_same<boost::is_arithmetic<int>::type, boost::true_type>::value;
    qDebug() << boost::is_same<boost::is_reference<int>::type, boost::false_type>::value;

    // имеет ли определенные методы/операторы
    qDebug() << boost::has_plus<int>::value;
    qDebug() << boost::has_pre_increment<int>::value;
    qDebug() << boost::has_trivial_copy<int>::value;
    qDebug() << boost::has_virtual_destructor<int>::value;
}

namespace templatesEnableIf {

template <typename Type>
typename boost::enable_if<std::is_same<Type, int>, Type>::type getValue()
{
    return 0;
}

template <typename Type>
typename boost::enable_if<std::is_same<Type, std::string>, Type>::type getValue()
{
    return "string";
}

template <typename Type>
auto print(typename boost::enable_if<std::is_integral<Type>, Type>::type i) -> std::string
{
    return "integer " + std::to_string(i);
}

template <typename Type>
auto print(typename boost::enable_if<std::is_floating_point<Type>, Type>::type f) -> std::string
{
    return "float " + std::to_string(f);
}

} // namespace templates

auto BoostGeneric::exampleBoostEnableIf() -> void
{
    using namespace templatesEnableIf;

    qDebug() << getValue<std::string>().c_str();

    qDebug() << print<short>(1).c_str();
    qDebug() << print<long>(2).c_str();
    qDebug() << print<double>(3.14).c_str();
}

struct print
{
    template <typename Type>
    auto operator()(const Type& value) const -> void
    {
        qDebug() << value;
    }
};

struct fusion_struct
{
  int i;
  double d;
};

BOOST_FUSION_ADAPT_STRUCT(fusion_struct,
  (int, i)
  (double, d)
)

auto BoostGeneric::exampleBoostFusion() -> void
{
    { // boost::fusion::for_each для гетерогенный контейнеров
        boost::fusion::tuple<int, QString, bool, double> fusion_tuple { 1, "string", true, 0.99 };
        boost::fusion::for_each(fusion_tuple, print{});

        // получить итератор на первый элемент
        auto iterator = boost::fusion::advance<boost::mpl::int_<0>>(boost::fusion::begin(fusion_tuple));
        qDebug() << "iterator[0]" << *iterator;
    }

    { // boost::fusion::filter_view - фильтр, только целочисленные
        boost::fusion::tuple<int, QString, bool, double> fusion_tuple { 1, "string", true, 0.99 };

        // boost::mpl::arg<1> как boost::phoenix::place_holders::arg1 из Boost.Phoenix, передаёт n-ый элемент
        boost::fusion::filter_view<boost::fusion::tuple<int, QString, bool, double>, boost::is_integral<boost::mpl::arg<1>>> view {fusion_tuple};
        boost::fusion::for_each(view, print{});
    }

    {
        boost::fusion::vector<int, std::string, bool, double> vector { 1, "string", true, 0.99 };
        qDebug() << "at[0] =" << boost::fusion::at<boost::mpl::int_<0>>(vector);

        auto iterator = boost::fusion::begin(vector);
        qDebug() << boost::fusion::deref(iterator); // == *iterator;
    }

    {
        auto map = boost::fusion::make_map<int, QString, bool, double>(1, "string", true, 0.99);

        if (boost::fusion::has_key<QString>(map))
            qDebug() << "key" << boost::fusion::at_key<QString>(map);
    }

    {
        fusion_struct fs = { 1, 0.99 }; // or std::make_pair(10, 3.14);
        qDebug() << "fusion struct" << boost::fusion::at<boost::mpl::int_<0>>(fs);
    }
}
