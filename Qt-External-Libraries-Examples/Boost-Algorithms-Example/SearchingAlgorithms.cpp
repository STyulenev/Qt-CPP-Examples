#include "SearchingAlgorithms.h"

namespace BoostAlgorithmsExamples {

auto ExampleSearchingAlgorithms() -> void
{
    std::string text("one, two, three, four");
    std::string pattern("two");

    {
        boost::algorithm::boyer_moore<std::string::const_iterator> search(pattern.begin(), pattern.end());

        auto iterator = search(text.begin(), text.end()); // pair<iterator start, iterator and>

        qDebug() << *(iterator.first) << *(iterator.second);
    }

    {
        boost::algorithm::boyer_moore_horspool<std::string::const_iterator> search(pattern.begin(), pattern.end());

        auto iterator = search(text.begin(), text.end()); // pair<iterator start, iterator and>

        qDebug() << *(iterator.first) << *(iterator.second);
    }

    {
        boost::algorithm::knuth_morris_pratt<std::string::const_iterator> search(pattern.begin(), pattern.end());

        auto iterator = search(text.begin(), text.end()); // pair<iterator start, iterator and>

        qDebug() << *(iterator.first) << *(iterator.second);
    }
}

auto ExampleCPP11Algorithms() -> void
{
    qDebug() << "all_of" << boost::algorithm::all_of(boost::container::vector<int>({ 2, 2, 2 }), [](int a) -> bool {
        return a % 2 == 0;
    } );

    qDebug() << "any_of" << boost::algorithm::any_of(boost::container::vector<int>({ 2, 3, 2 }), [](int a) -> bool {
        return a == 3;
    } );

    qDebug() << "one_of" << boost::algorithm::one_of(boost::container::vector<int>({ 1, 2, 3 }), [](int a) -> bool {
        return a == 2;
    } );

    qDebug() << "none_of" << boost::algorithm::none_of(boost::container::vector<int>({ 1, 2, 3 }), [](int a) -> bool {
        return a != 4;
    } );

    qDebug() << "is_sorted" << boost::algorithm::is_sorted(boost::container::vector<int>({ 1, 3, 2 }));

    qDebug() << "is_partitioned" << boost::algorithm::is_partitioned(boost::container::vector<int>({ 1, 5, 3, 4, 5 }), [](int a) -> bool {
        return a < 4;
    } );

    {
        std::string str1 = "cppsecrets";
        std::string str2 = "secretscppboost";

        qDebug() << "is_permutation" << boost::algorithm::is_permutation(str1.begin(), str1.end(), str2.begin());
    }

    {
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5 };

        auto iterator = boost::algorithm::partition_point(vector.begin(), vector.end(), [](int a) -> bool {
            return a < 4;
        } );

        qDebug() << "partition_point" << *iterator;
    }

    {
        boost::container::vector<int> in = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> out_true;
        boost::container::vector<int> out_false;

        boost::algorithm::partition_copy(in.begin(), in.end(), std::back_inserter(out_true), std::back_inserter(out_false), [](int a) -> bool {
            return a % 2 == 0;
        } );

        qDebug() << "partition_copy";

        for(auto iterator = out_true.begin(); iterator != out_true.end(); ++iterator) {
            qDebug() << *iterator;
        }

        for(auto iterator = out_false.begin(); iterator != out_false.end(); ++iterator) {
            qDebug() << *iterator;
        }
    }

    {
        boost::container::vector<int> in = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> out;

        boost::algorithm::copy_if(in.begin(), in.end(), std::back_inserter(out), [](int a) -> bool {
            return a % 2 == 0;
        } );

        qDebug() << "copy_if";

        for(auto iterator = out.begin(); iterator != out.end(); ++iterator) {
            qDebug() << *iterator;
        }
    }

    {
        boost::container::vector<int> in = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> out;

        boost::algorithm::copy_n(in.begin(), 2, std::back_inserter(out));

        qDebug() << "copy_n";

        for(auto iterator = out.begin(); iterator != out.end(); ++iterator) {
            qDebug() << *iterator;
        }
    }

    {
        boost::container::vector<int> in(10);

        boost::algorithm::iota(in.begin(), in.begin() + 10, 5);

        qDebug() << "iota";

        for(auto iterator = in.begin(); iterator != in.end(); ++iterator) {
            qDebug() << *iterator;
        }
    }
}

auto ExampleCPP14Algorithms() -> void
{
    {
        boost::container::vector<int> vectorOne = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> vectorTwo = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> vectorThree = { 1, 2, 3, 4, 6 };

        qDebug() << boost::algorithm::equal(vectorOne.begin(), vectorOne.end(), vectorTwo.begin(), vectorTwo.end());   // true
        qDebug() << boost::algorithm::equal(vectorOne.begin(), vectorOne.end(), vectorThree.begin(), vectorThree.end()); // false
    }

    {
        boost::container::vector<int> vectorOne = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> vectorTwo = { 1, 2, 6, 4, 5 };

        auto pair = boost::algorithm::mismatch(vectorOne.begin(), vectorOne.end(), vectorTwo.begin(), vectorTwo.end());
        qDebug() << *pair.first << *pair.second; // 3 != 6
    }
}

auto ExampleCPP17Algorithms() -> void
{
    {
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5 };

        boost::algorithm::for_each_n(vector.begin(), vector.size(), [](int& element) -> void { // { 3, 4, 5, 6, 7 }
            element += 2;
        });

        for(auto iterator = vector.begin(); iterator != vector.end(); ++iterator) {
            qDebug() << *iterator;
        }
    }

    {
        boost::container::vector<int> vectorIn = { -1, -2, -3, -4, -5 };

        boost::container::vector<int> vectorOut;
        boost::algorithm::transform_inclusive_scan(vectorIn.begin(), vectorIn.end(),
                                                   std::back_inserter(vectorOut),
                                                   std::plus<>{}, [](int element) -> int {
            return std::abs(element);
        });

        for(auto iterator = vectorOut.begin(); iterator != vectorOut.end(); ++iterator) {
            qDebug() << *iterator;
        }
    }

    {
        boost::container::vector<int> vectorIn = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> vectorOut;

        boost::algorithm::transform_exclusive_scan(vectorIn.begin(), vectorIn.end(), std::back_inserter(vectorOut), 10, std::plus<>{},
                                                   [](int element) -> int {
            return element;
        });

        for(auto iterator = vectorOut.begin(); iterator != vectorOut.end(); ++iterator) {
            qDebug() << *iterator;
        }
    }
}

} // namespace BoostAlgorithmsExamples
