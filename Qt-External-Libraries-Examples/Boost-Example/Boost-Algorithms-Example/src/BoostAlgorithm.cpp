#include "BoostAlgorithm.h"

#include <boost/container/vector.hpp>
#include <boost/iostreams/device/back_inserter.hpp>

// Searching Algorithms
#include <boost/algorithm/searching/boyer_moore.hpp>
#include <boost/algorithm/searching/boyer_moore_horspool.hpp>
#include <boost/algorithm/searching/knuth_morris_pratt.hpp>

// C++11 Algorithms
#include <boost/algorithm/cxx11/all_of.hpp>
#include <boost/algorithm/cxx11/any_of.hpp>
#include <boost/algorithm/cxx11/none_of.hpp>
#include <boost/algorithm/cxx11/one_of.hpp>
#include <boost/algorithm/cxx11/is_sorted.hpp>
#include <boost/algorithm/cxx11/is_partitioned.hpp>
#include <boost/algorithm/cxx11/is_permutation.hpp>
#include <boost/algorithm/cxx11/partition_point.hpp>
#include <boost/algorithm/cxx11/partition_copy.hpp>
#include <boost/algorithm/cxx11/copy_if.hpp>
#include <boost/algorithm/cxx11/copy_n.hpp>
#include <boost/algorithm/cxx11/iota.hpp>

// C++14 Algorithms
#include <boost/algorithm/cxx14/equal.hpp>
#include <boost/algorithm/cxx14/mismatch.hpp>

// C++17 Algorithms
#include <boost/algorithm/cxx17/for_each_n.hpp>
#include <boost/algorithm/cxx17/transform_inclusive_scan.hpp>
#include <boost/algorithm/cxx17/transform_exclusive_scan.hpp>

// Copy Algorithms
//#include <boost/algorithm/cxx11/copy_if.hpp>

// Other Algorithms
#include <boost/algorithm/cxx11/none_of.hpp>
#include <boost/algorithm/cxx11/is_sorted.hpp>
#include <boost/algorithm/clamp.hpp>
#include <boost/algorithm/find_not.hpp>
#include <boost/algorithm/find_backward.hpp>
#include <boost/algorithm/cxx11/find_if_not.hpp>
#include <boost/algorithm/gather.hpp>
#include <boost/algorithm/hex.hpp>
#include <boost/algorithm/is_palindrome.hpp>
#include <boost/algorithm/is_partitioned_until.hpp>
#include <boost/algorithm/cxx11/iota.hpp>

auto BoostAlgorithm::exampleSearchingAlgorithms() -> void
{
    std::string text("one, two, three, four");
    std::string pattern("two");

    { // boost::algorithm::boyer_moore
        boost::algorithm::boyer_moore<std::string::const_iterator> search(pattern.begin(), pattern.end());

        auto iterator = search(text.begin(), text.end()); // pair<iterator start, iterator and>

        qDebug() << *(iterator.first) << *(iterator.second);
    }

    { // boost::algorithm::boyer_moore_horspool
        boost::algorithm::boyer_moore_horspool<std::string::const_iterator> search(pattern.begin(), pattern.end());

        auto iterator = search(text.begin(), text.end()); // pair<iterator start, iterator and>

        qDebug() << *(iterator.first) << *(iterator.second);
    }

    { // boost::algorithm::knuth_morris_pratt
        boost::algorithm::knuth_morris_pratt<std::string::const_iterator> search(pattern.begin(), pattern.end());

        auto iterator = search(text.begin(), text.end()); // pair<iterator start, iterator and>

        qDebug() << *(iterator.first) << *(iterator.second);
    }
}

auto BoostAlgorithm::exampleCPP11Algorithms() -> void
{
    qDebug() << "all_of" << boost::algorithm::all_of(boost::container::vector<int>({ 2, 2, 2 }), [](int a) -> bool {
        return a % 2 == 0;
    });

    qDebug() << "any_of" << boost::algorithm::any_of(boost::container::vector<int>({ 2, 3, 2 }), [](int a) -> bool {
        return a == 3;
    });

    qDebug() << "one_of" << boost::algorithm::one_of(boost::container::vector<int>({ 1, 2, 3 }), [](int a) -> bool {
        return a == 2;
    });

    qDebug() << "none_of" << boost::algorithm::none_of(boost::container::vector<int>({ 1, 2, 3 }), [](int a) -> bool {
        return a != 4;
    });

    qDebug() << "is_sorted" << boost::algorithm::is_sorted(boost::container::vector<int>({ 1, 3, 2 }));

    qDebug() << "is_partitioned" << boost::algorithm::is_partitioned(boost::container::vector<int>({ 1, 5, 3, 4, 5 }), [](int a) -> bool {
        return a < 4;
    } );

    { // boost::algorithm::is_permutation
        std::string str1 = "cppsecrets";
        std::string str2 = "secretscppboost";

        qDebug() << "is_permutation" << boost::algorithm::is_permutation(str1.begin(), str1.end(), str2.begin());
    }

    { // boost::algorithm::partition_point
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5 };

        auto iterator = boost::algorithm::partition_point(vector.begin(), vector.end(), [](int a) -> bool {
            return a < 4;
        });

        qDebug() << "partition_point" << *iterator;
    }

    { // boost::algorithm::partition_copy
        boost::container::vector<int> in = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> out_true;
        boost::container::vector<int> out_false;

        boost::algorithm::partition_copy(in.begin(), in.end(), std::back_inserter(out_true), std::back_inserter(out_false), [](int a) -> bool {
            return a % 2 == 0;
        });

        qDebug() << "partition_copy";

        for(auto iterator = out_true.begin(); iterator != out_true.end(); ++iterator) {
            qDebug() << *iterator;
        }

        for(auto iterator = out_false.begin(); iterator != out_false.end(); ++iterator) {
            qDebug() << *iterator;
        }
    }

    { // boost::algorithm::copy_if
        boost::container::vector<int> in = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> out;

        boost::algorithm::copy_if(in.begin(), in.end(), std::back_inserter(out), [](int a) -> bool {
            return a % 2 == 0;
        });

        qDebug() << "copy_if";

        for(auto iterator = out.begin(); iterator != out.end(); ++iterator) {
            qDebug() << *iterator;
        }
    }

    { // boost::algorithm::copy_n
        boost::container::vector<int> in = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> out;

        boost::algorithm::copy_n(in.begin(), 2, std::back_inserter(out));

        qDebug() << "copy_n";

        for(auto iterator = out.begin(); iterator != out.end(); ++iterator) {
            qDebug() << *iterator;
        }
    }

    { // boost::algorithm::iota
        boost::container::vector<int> in(10);

        boost::algorithm::iota(in.begin(), in.begin() + 10, 5);

        qDebug() << "iota";

        for(auto iterator = in.begin(); iterator != in.end(); ++iterator) {
            qDebug() << *iterator;
        }
    }
}

auto BoostAlgorithm::exampleCPP14Algorithms() -> void
{
    { // boost::algorithm::equal
        boost::container::vector<int> vectorOne = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> vectorTwo = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> vectorThree = { 1, 2, 3, 4, 6 };

        qDebug() << boost::algorithm::equal(vectorOne.begin(), vectorOne.end(), vectorTwo.begin(), vectorTwo.end());   // true
        qDebug() << boost::algorithm::equal(vectorOne.begin(), vectorOne.end(), vectorThree.begin(), vectorThree.end()); // false
    }

    { // boost::algorithm::mismatch
        boost::container::vector<int> vectorOne = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> vectorTwo = { 1, 2, 6, 4, 5 };

        auto pair = boost::algorithm::mismatch(vectorOne.begin(), vectorOne.end(), vectorTwo.begin(), vectorTwo.end());
        qDebug() << *pair.first << *pair.second; // 3 != 6
    }
}

auto BoostAlgorithm::exampleCPP17Algorithms() -> void
{
    { // boost::algorithm::for_each_n
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5 };

        boost::algorithm::for_each_n(vector.begin(), vector.size(), [](int& element) -> void { // { 3, 4, 5, 6, 7 }
            element += 2;
        });

        for(auto iterator = vector.begin(); iterator != vector.end(); ++iterator) {
            qDebug() << *iterator;
        }
    }

    { // boost::algorithm::transform_inclusive_scan
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

    { // boost::algorithm::transform_exclusive_scan
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

auto BoostAlgorithm::exampleCopyAlgorithms() -> void
{
    { // boost::algorithm::copy_until
        boost::container::vector<int> in = {-5, -3, -9, 2, 10, 20, 30, 5};
        boost::container::vector<int> out;

        auto predicate = [](int element){ return element > 0; };

        // будут скопированы только -5, -3, -9
        boost::algorithm::copy_until(in.begin(), in.end(), std::back_inserter(out), predicate);

        QDebug debug = qDebug();
        for(auto iterator = out.begin(); iterator != out.end(); ++iterator) {
            debug << *iterator;
        }
    }

    { // boost::algorithm::copy_while
        boost::container::vector<int> in = {-5, -3, -9, 2, 10, 20, 30, 5};
        boost::container::vector<int> out;

        boost::algorithm::copy_while(in.begin(), in.end(), std::back_inserter(out), [](int element) -> bool {
            return element < 0; // будут скопированы только -5, -3, -9
        });

        QDebug debug = qDebug();
        for(auto iterator = out.begin(); iterator != out.end(); ++iterator) {
            debug << *iterator;
        }
    }

    { // boost::algorithm::copy_if_until
        boost::container::vector<int> in = {-5, -3, -9, 2, 10, 20, 30, 5};
        boost::container::vector<int> out;

        boost::algorithm::copy_if_until(in.begin(), in.end(), std::back_inserter(out),
                                        [] (int element) -> bool {
            return element > 0;
        }, [] (int element) -> bool {
            return element == 30;
        });

        QDebug debug = qDebug();
        for(auto iterator = out.begin(); iterator != out.end(); ++iterator) {
            debug << *iterator;
        }
    }

    { // boost::algorithm::copy_if_while
        boost::container::vector<int> in = {-5, -3, -9, 2, 10, 20, 30, 5};
        boost::container::vector<int> out;

        boost::algorithm::copy_if_while(in.begin(), in.end(), std::back_inserter(out),
                                        [](int element) -> bool {
            return element < 0;
        }, [](int element) -> bool {
            return element < 10;
        });

        QDebug debug = qDebug();
        for(auto iterator = out.begin(); iterator != out.end(); ++iterator) {
            debug << *iterator;
        }
    }
}

auto BoostAlgorithm::exampleOtherAlgorithms() -> void
{
    { // boost::algorithm::none_of
        boost::container::vector<int> in = { 1, 2, 3, 4, 5, 6 };

        qDebug() << boost::algorithm::none_of(in.begin(), in.end(), [](int element) -> bool {
            return element == 3;
        });
    }

    { // boost::algorithm::one_of_equal
        boost::container::vector<int> in = { 1, 2, 3, 4, 5, 6 };

        qDebug() << boost::algorithm::one_of_equal(in.begin(), in.end(), 3);
    }

    { // boost::algorithm::is_decreasing
        boost::container::vector<int> in = { 4, 3, 3, 2, 1 };

        qDebug() << boost::algorithm::is_decreasing(in.begin(), in.end());
    }

    { // boost::algorithm::is_increasing
        boost::container::vector<int> in = { 1, 1, 2, 3, 4 };

        qDebug() << boost::algorithm::is_increasing(in.begin(), in.end());
    }

    { // boost::algorithm::is_strictly_decreasing
        boost::container::vector<int> in = { 4, 3, 2, 1 };

        qDebug() << boost::algorithm::is_strictly_decreasing(in.begin(), in.end());
    }

    { // boost::algorithm::is_strictly_increasing
        boost::container::vector<int> in = { 1, 2, 3, 4 };

        qDebug() << boost::algorithm::is_strictly_increasing(in.begin(), in.end());
    }

    { // boost::algorithm::clamp
        int value = 25;
        int low = 10;
        int high = 20;

        qDebug() << "clamp" << boost::algorithm::clamp(value, low, high);
    }

    { // boost::algorithm::clamp_range
        boost::container::vector<int> in = {-5, -3, -9, 2, 10, 20, 30, 5};
        boost::container::vector<int> out;

        boost::algorithm::clamp_range(in.begin(), in.end(), std::back_inserter(out), 0, 25);

        QDebug debug = qDebug();
        debug << "boost::algorithm::clamp_range";
        for(auto iterator = out.begin(); iterator != out.end(); ++iterator) {
            debug << *iterator;
        }
    }

    { // boost::algorithm::find_not
        boost::container::vector<int> in = { 0, 0, 1, 2, 3};
        auto it = boost::algorithm::find_not(in.begin(), in.end(), 0);
        qDebug() << "boost::algorithm::find_not" << *it;
    }

    { // boost::algorithm::find_backward
        boost::container::vector<int> in = { 0, 0, 1, 2, 3};
        auto it = boost::algorithm::find_backward(in.begin(), in.end(), 1);
        qDebug() << "boost::algorithm::find_backward" << *it;
    }

    { // boost::algorithm::find_not_backward
        boost::container::vector<int> in = { 0, 0, 1, 2, 3};
        auto it = boost::algorithm::find_not_backward(in.begin(), in.end(), 1);
        qDebug() << "boost::algorithm::find_not_backward" << *it;
    }

    { // boost::algorithm::find_if_backward
        boost::container::vector<int> in = { 0, 0, 1, 2, 3};
        auto it = boost::algorithm::find_if_backward(in.begin(), in.end(), [](int element) -> bool {
            return element < 2;
        });
        qDebug() << "boost::algorithm::find_if_backward" << *it;
    }

    { // boost::algorithm::find_if_not
        boost::container::vector<int> in = { 0, 0, 1, 2, 3};
        auto it = boost::algorithm::find_if_not(in.begin(), in.end(), [](int element) -> bool {
            return element < 2;
        });
        qDebug() << "boost::algorithm::find_if_not" << *it;
    }

    { // find_if_not_backward
        boost::container::vector<int> in = { 0, 0, 1, 2, 3};
        auto it = boost::algorithm::find_if_not_backward(in.begin(), in.end(), [](int element) -> bool {
            return element == 0;
        });
        qDebug() << "boost::algorithm::find_if_not_backward" << *it;
    }

    { // boost::algorithm::gather
        boost::container::vector<int> in = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        boost::algorithm::gather(in.begin(), in.end(), in.begin() /* + 2 */, [](int element) {
            return element % 2 == 0;
        });

        QDebug debug = qDebug();
        debug << "boost::algorithm::gather";
        for(auto iterator = in.begin(); iterator != in.end(); ++iterator) {
            debug << *iterator;
        }
    }

    { // boost::algorithm::hex
        std::string out;
        boost::algorithm::hex("hello", std::back_inserter(out)); // -> 68656C6C6F
        qDebug() << "boost::algorithm::hex hello ->" << out.c_str();
    }

    { // boost::algorithm::unhex
        std::string out;
        boost::algorithm::unhex("68656C6C6F", std::back_inserter(out)); // -> hello
        qDebug() << "boost::algorithm::unhex 68656C6C6F ->" << out.c_str();
    }

    { // boost::algorithm::hex_lower
        boost::container::vector<int> in = { 1, 2, 3, 4 };
        std::string out;
        boost::algorithm::hex_lower(in.begin(), in.end(), std::back_inserter(out));
        qDebug() << "boost::algorithm::hex_lower { 1, 2, 3, 4 } ->" << out.c_str();
    }

    { // boost::algorithm::is_palindrome
        std::string in = "asdsa";
        qDebug() << "boost::algorithm::is_palindrome" << boost::algorithm::is_palindrome(std::begin(in), std::end(in));
    }

    { // boost::algorithm::is_partitioned_until
        boost::container::vector<int> in = { 1, 2, 3, 4 };

        auto iterator = boost::algorithm::is_partitioned_until(in.begin(), in.end (), [](int element) {
            return element % 2 == 0;
        });

        qDebug() << "boost::algorithm::is_partitioned_until" << *iterator;
    }
}
