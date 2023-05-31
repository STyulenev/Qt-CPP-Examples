#include "BoostRange.h"


#include <boost/container/vector.hpp>

//#include <boost/range/algorithm.hpp> // <- including all
#include <boost/range/algorithm/adjacent_find.hpp>
#include <boost/range/algorithm/binary_search.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/range/algorithm/copy_backward.hpp>
#include <boost/range/algorithm/count.hpp>
#include <boost/range/algorithm/count_if.hpp>
#include <boost/range/algorithm/equal.hpp>
#include <boost/range/algorithm/equal_range.hpp>
#include <boost/range/algorithm/fill.hpp>
#include <boost/range/algorithm/fill_n.hpp>
#include <boost/range/algorithm/find.hpp>
#include <boost/range/algorithm/find_end.hpp>
#include <boost/range/algorithm/find_first_of.hpp>
#include <boost/range/algorithm/find_if.hpp>
#include <boost/range/algorithm/for_each.hpp>
#include <boost/range/algorithm/generate.hpp>
#include <boost/range/algorithm/heap_algorithm.hpp>
#include <boost/range/algorithm/inplace_merge.hpp>
#include <boost/range/algorithm/lexicographical_compare.hpp>

auto BoostRange::exampleBoostRangeAlgorithms() -> void
{

    { // boost::range::adjacent_find
        std::string s = "abccdb";

        std::string::iterator eq_it = boost::range::adjacent_find(s);
        std::string::iterator gt_it = boost::range::adjacent_find(s, std::greater<char>());

        qDebug() << "First duplicate character: '" << *eq_it << "' " << "at position " << (eq_it - s.begin());
        qDebug() << "First character greater than next: '" << *gt_it << "' " << "at position " << (gt_it - s.begin());
    }

    { // boost::range::binary_search
        boost::container::vector<int> vector = { 4, 9, 10, 5, 3, 11, 2 };
        std::sort(boost::begin(vector), boost::end(vector)); // необходима сортировка!

        qDebug() << "Element 5 " << (boost::range::binary_search(vector, 3) ? "found" : "not found") << " in array.";

        auto predicat = [](int first, int second) -> bool {
            return first < second;
        };

        qDebug() << "Element 10 " << (boost::range::binary_search(vector, 10, predicat) ? "found" : "not found") << " in array.";
    }

    { // boost::range::copy
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5, 6 };
        boost::container::vector<int> vector2;

        boost::range::copy(vector, std::back_inserter(vector2));

        QDebug debug = qDebug();
        debug << "boost::range::copy vector2 = ";
        for (const auto& element : vector2) {
            debug << element;
        }
    }

    { // boost::range::copy_backward
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5, 6 };
        boost::container::vector<int> vector2(vector.size() + 2);
        vector2[0] = 8;
        vector2[1] = 7;

        boost::range::copy_backward(vector, boost::end(vector2));

        QDebug debug = qDebug();
        debug << "boost::range::copy_backward vector2 = ";
        for(const auto& element : vector2) {
            debug << element;
        }
    }

    { // boost::range::count
        boost::container::vector<int> vector {0, 1, 0, 1, 0, 1};
        qDebug() << "boost::count 0 =" << boost::range::count(vector, 0);
    }

    { // boost::range::count_if
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5, 6, 7};

        auto predicat = [](int element) -> bool {
            return element > 3 && element < 6;
        };

        qDebug() << "boost::range::count_if 3 < element < 6 = " << boost::range::count_if(vector, predicat);
    }

    { // boost::range::equal
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5, 6 };
        boost::container::vector<int> vector2 = { 1, 2, 3, 4, 5, 8 };

        qDebug() << "boost::range::equal" << (boost::range::equal(vector, vector2) ? "Equal" : "Not Equal");
    }

    { // boost::range::equal_range
        std::string s = "abbCCCcccd";
        std::locale locale;

        auto predicat = [&locale](char lhs, char rhs) -> bool {
            return std::toupper(lhs, locale) < std::toupper(rhs, locale);
        };

        auto c_range = boost::range::equal_range(s, 'c');
        auto cC_range = boost::range::equal_range(s, 'c', predicat);

        qDebug() << "boost::range::equal_range" << c_range.first.base() << c_range.second.base() << "and" << cC_range.first.base() << cC_range.second.base();
    }

    { // boost::range::fill
        boost::container::vector<int> vector(10);
        boost::range::fill(vector, 5);

        QDebug debug = qDebug();
        debug << "boost::range::fill vector ";
        for (const auto& element : vector) {
            debug << element;
        }
    }

    { // boost::range::fill_n
        boost::container::vector<int> vector(10, 1);
        boost::range::fill_n(vector, 5, 8);

        QDebug debug = qDebug();
        debug << "boost::range::fill vector ";
        for (const auto& element : vector) {
            debug << element;
        }
    }

    { // boost::range::find
        boost::container::vector<int> vector {10, 20, 30, 40, 40, 50};
        auto iterator = boost::range::find(vector, 40);
        qDebug() << "boost::range::find" << *iterator;
    }

    { // boost::range::find_end
        boost::container::vector<int> vector1 = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4 };
        boost::container::vector<int> vector2 = { 1, 2, 3 };
        boost::container::vector<int>::iterator iterator;

        iterator = boost::range::find_end(vector1, vector2);

        qDebug() << "boost::range::find_end" << iterator - vector1.begin();
    }

    { // boost::range::find_first_of
        const std::string string = "ABC abc abc";
        std::locale locale;

        auto predicat = [&locale](char lhs, char rhs) -> bool {
            return std::toupper(lhs, locale) < std::toupper(rhs, locale);
        };

        auto iterator1 = boost::range::find_first_of(string, "cb");
        auto iterator2 = boost::range::find_first_of(string, "cb", predicat);

        qDebug() << "boost::range::find_first_of" << (iterator1 - string.begin()) << "with predicat" << (iterator2 - string.begin());
    }

    { // boost::range::find_if
        const std::string string = "ABC abc abc";

        auto iterator = boost::range::find_if(string, [](char c) {
            return c == 'a';
        });

        qDebug() << "boost::range::find_if" << (iterator - string.begin());
    }

    { // boost::range::for_each
        boost::container::vector<int> vector {10, 20, 30, 40, 40, 50};

        QDebug debug = qDebug();
        auto predicat_print = [&debug](const int& element) -> void {
            debug << element;
        };
        debug << "boost::range::for_each";
        boost::range::for_each(vector, predicat_print);
    }

    { // boost::range::generate
        boost::container::vector<int> vector(10);

        srand(time(NULL));
        auto random_num  = [](void) -> int {
            return rand() % 10;
        };

        boost::range::generate(vector, random_num);

        QDebug debug = qDebug();
        debug << "boost::range::generate vector =";
        for (const auto& element : vector) {
            debug << element;
        }
    }

    { // boost::range::heap
        boost::container::vector<int> vector = {1, 3, 9, 4, 16, 7};

        boost::range::make_heap(vector);

        boost::range::pop_heap(vector);
        vector.pop_back();

        vector.push_back(32);
        boost::range::push_heap(vector);

        boost::range::sort_heap(vector);

        QDebug debug = qDebug();
        debug << "boost::range::heap vector =";
        for (const auto& element : vector) {
            debug << element;
        }
    }

    { // boost::range::inplace_merge
        boost::container::vector<int> vector1(5), vector2(5), final_vector;
        vector1 = { 2, 4, 6, 8, 10 };
        vector2 = { 7, 10, 5, 25, 30 };

        std::sort(vector2.begin(), vector2.end());

        final_vector.insert(final_vector.end(), vector1.begin(), vector1.end());
        final_vector.insert(final_vector.end(), vector2.begin(), vector2.end());

        boost::range::inplace_merge(final_vector, final_vector.begin() + 5);

        QDebug debug = qDebug();
        debug << "boost::range::inplace_merge vector =";
        for (const auto& element : final_vector) {
            debug << element;
        }
    }

    { // boost::range::lexicographical_compare
        std::string str1 = "abcd", str2 = "abcd";

        qDebug() << "boost::range::lexicographical_compare" << (boost::range::lexicographical_compare(str1, str2) ? "str1 < str2" : "str1 >= str2");
    }
}
