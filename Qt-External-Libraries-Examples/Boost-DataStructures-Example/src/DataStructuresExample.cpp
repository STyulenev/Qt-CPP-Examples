#include "DataStructuresExample.h"

#include <QDebug>

#include <boost/optional.hpp>
#include <boost/any.hpp>
#include <boost/variant.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/compressed_pair.hpp>
#include <boost/logic/tribool.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/dynamic_bitset.hpp>

auto DataStructuresExample::OptionalExample() -> void
{
    auto boost_optional_func = [](int value) -> boost::optional<int> {
        if (value > 5)
            return boost::make_optional(10); // or return 10;
        if (value < 5)
            return boost::make_optional(0); // or return 0;

        return boost::none; // return empty object
    };

    auto std_optional_func = [](int value) -> std::optional<int> {
        if (value > 5)
            return std::make_optional(10); // or return 10;
        if (value < 5)
            return std::make_optional(0); // or return 0;

        return std::nullopt; // return empty object
    };

    {
        boost::optional<int> boost_data = boost_optional_func(3); // 5

        if (!boost_data)
            qDebug() << "none";
        else
            qDebug() << boost_data.get();
    }

    {
        std::optional<int> std_data = std_optional_func(3); // 5

        if (!std_data)
            qDebug() << "none";
        else
            qDebug() << std_data.value();
    }
}

auto DataStructuresExample::AnyExample() -> void
{
    boost::any value; // ~ std::any

    try {
        qDebug() << "value = " << boost::any_cast<int>(value);
    } catch (boost::bad_any_cast& error) {
        qDebug() << error.what();
    }

    if (value.empty()) { // std::any -> value.has_value()
        qDebug() << "value is empty";
    }

    value = 7;

    if (value.type().name() == typeid(int).name()) {
        qDebug() << "value = " << boost::any_cast<int>(value); // std::any -> std::any_cast<int>
    } else {
        qDebug() << "unknown type";
    }
}

auto DataStructuresExample::VariantExample() -> void
{
    struct output_boost : public boost::static_visitor<>
    {
        auto operator()(double d) const -> void { qDebug() << d; }
        auto operator()(bool b) const -> void { qDebug() << b; }
        auto operator()(std::string s) const -> void { qDebug() << s.c_str(); }
    };

    struct output_std
    {
        auto operator()(const double& d) const -> void { qDebug() << d; }
        auto operator()(const bool& b) const -> void { qDebug() << b; }
        auto operator()(const std::string& s) const -> void { qDebug() << s.c_str(); }
    };

    { // boost::variant
        boost::variant<double, bool, std::string> value;

        try {
            value = 3.14;
            qDebug() << boost::get<std::string>(value).c_str();
        } catch (boost::bad_get& error) {
            qDebug() << error.what();
        }

        value = true;

        if (value.type().name() == typeid(bool).name()) {
            qDebug() << boost::get<bool>(value);
        } else {
            qDebug() << "unknown type";
        }
        boost::apply_visitor(output_boost(), value); // or use visitor

        value = std::string("Boost");
        qDebug() << boost::get<std::string>(value).c_str();
    }

    { // std::variant
        std::variant<double, bool, std::string> value;

        value = true;
        std::visit(output_std{}, value);
    }
}

auto DataStructuresExample::TupleExample() -> void
{
    typedef boost::tuple<std::string, int> person; // name, age, = std::tuple<std::string, int> person

    person p {"John", 44};
    p = boost::make_tuple("John S", 46); // std::make_tuple("John S", 46);
    p.get<1>() = 45;

    qDebug() << p.get<0>().c_str() << p.get<1>();

    std::string name;
    int age = 0;;

    boost::tie(name, age) = p; // std::tie(name, age)
    qDebug() << name.c_str() << age;
}

auto DataStructuresExample::CompressedPairExample() -> void
{
    {
        struct empty
        {
            // none
        };

        std::pair<int, empty> p;
        qDebug() << sizeof(p);

        boost::compressed_pair<int, empty> cp;
        qDebug() << sizeof(cp);
    }

    boost::compressed_pair<int, bool> pair(11, true);

    qDebug() << pair.first() << pair.second();
}

auto DataStructuresExample::TriboolPairExample() -> void
{
    auto chech_value = [](boost::logic::tribool value) -> void {
        if (value) {
            qDebug() << "true";
        } else if (!value) {
            qDebug() << "false";
        } else {
            qDebug() << "indeterminate";
        }
    };

    boost::logic::tribool value;

    value = true;
    value = false;
    value = boost::logic::indeterminate;

    chech_value(value);

    {
        boost::logic::tribool b1 = true;
        chech_value(b1 || boost::logic::indeterminate);
        chech_value(b1 && boost::logic::indeterminate);

        boost::logic::tribool b2 = false;
        chech_value(b2 || boost::logic::indeterminate);
        chech_value(b2 && boost::logic::indeterminate);

        boost::logic::tribool b3 = boost::logic::indeterminate;
        chech_value(b3 || b3);
        chech_value(b3 && b3);
    }
}

auto parse_tree(const boost::property_tree::ptree& pt, std::string key) -> void
{
    std::string nkey;

    if (!key.empty()) {
        nkey = key + ".";
    }

    try {
        qDebug() << pt.get<std::string>(key).c_str();
    } catch (boost::property_tree::ptree_bad_path& error) {
        //qDebug() << error.what();
    }

    boost::property_tree::ptree::const_iterator end = pt.end();
    for (boost::property_tree::ptree::const_iterator it = pt.begin(); it != end; ++it) {
        qDebug() << it->first.c_str() << it->second.data().c_str();
        parse_tree(it->second, nkey + it->first);
    }
}

auto DataStructuresExample::PropertyTreeExample() -> void
{
    boost::property_tree::ptree family;

    family.put("Husband", "John");
    family.put("Wife",    "Sarah");
    family.put("Children.First",  "Mike");
    family.put("Children.Second", "Tom");
    family.put("Children.Third",  "Emily");

    boost::property_tree::ptree inventoryTree = family.get_child("Children");
    inventoryTree.put("Fourth", "Josef");

    boost::property_tree::ptree::const_iterator it;
    for (it = family.begin(); it != family.end(); ++it) {
        qDebug() << it->first.c_str() << it->second.data().c_str();
        parse_tree(it->second, "Children" + it->first);
    }

    boost::property_tree::json_parser::write_json("file.json", family);
}

auto DataStructuresExample::DynamicBitsetExample() -> void
{
    boost::dynamic_bitset<> db{3, 4}; // constructor creates db with 3 bits, the number 4 initializes the most significant bit – the bit on the very left

    db.push_back(true);

    qDebug() << db.size();
    qDebug() << db.count();
    qDebug() << db.any();
    qDebug() << db.none();

    qDebug() << db[0].flip();
    qDebug() << ~db[3];

    for (int i = 0; i < db.size(); ++i) {
        qDebug() << i << db[i];
    }
}
