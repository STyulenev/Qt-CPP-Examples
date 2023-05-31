#include "BoostRange.h"


#include <boost/container/vector.hpp>

// algorithm
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
#include <boost/range/algorithm/lower_bound.hpp>
#include <boost/range/algorithm/max_element.hpp>
#include <boost/range/algorithm/merge.hpp>
#include <boost/range/algorithm/min_element.hpp>
#include <boost/range/algorithm/mismatch.hpp>
#include <boost/range/algorithm/nth_element.hpp>
#include <boost/range/algorithm/partial_sort.hpp>
#include <boost/range/algorithm/partition.hpp>
#include <boost/range/algorithm/permutation.hpp>
#include <boost/range/algorithm/random_shuffle.hpp>
#include <boost/range/algorithm/remove.hpp>
#include <boost/range/algorithm/remove_copy.hpp>
#include <boost/range/algorithm/remove_copy_if.hpp>
#include <boost/range/algorithm/remove_if.hpp>
#include <boost/range/algorithm/replace.hpp>
#include <boost/range/algorithm/replace_copy.hpp>
#include <boost/range/algorithm/replace_copy_if.hpp>
#include <boost/range/algorithm/replace_if.hpp>
#include <boost/range/algorithm/reverse.hpp>
#include <boost/range/algorithm/reverse_copy.hpp>
#include <boost/range/algorithm/rotate.hpp>
#include <boost/range/algorithm/rotate_copy.hpp>
#include <boost/range/algorithm/search.hpp>
#include <boost/range/algorithm/search_n.hpp>
#include <boost/range/algorithm/set_algorithm.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <boost/range/algorithm/stable_partition.hpp>
#include <boost/range/algorithm/swap_ranges.hpp>
#include <boost/range/algorithm/transform.hpp>
#include <boost/range/algorithm/unique.hpp>
#include <boost/range/algorithm/unique_copy.hpp>
#include <boost/range/algorithm/upper_bound.hpp>

// adaptor
//#include <boost/range/adaptors.hpp> // <- including all
#include <boost/range/adaptor/adjacent_filtered.hpp>
#include <boost/range/adaptor/copied.hpp>
#include <boost/range/adaptor/filtered.hpp>
#include <boost/range/adaptor/indexed.hpp>
#include <boost/range/adaptor/indirected.hpp>
#include <boost/range/adaptor/map.hpp>
#include <boost/range/adaptor/replaced.hpp>
#include <boost/range/adaptor/replaced_if.hpp>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/adaptor/sliced.hpp>
#include <boost/range/adaptor/strided.hpp>
#include <boost/range/adaptor/tokenized.hpp>
#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/adaptor/uniqued.hpp>

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

    { // boost::range::lower_bound
        boost::container::vector<int> vector = { 1, 1, 1, 2, 2, 3, 5, 5, 6 };

        QDebug debug = qDebug();
        debug << "boost::range::lower_bound";
        debug << ">2 position =" << boost::range::lower_bound(vector, 2) - vector.begin() << ",";
        debug << ">1 position =" << boost::range::lower_bound(vector, 1) - vector.begin() << ",";
        debug << ">7 position =" << boost::range::lower_bound(vector, 7) - vector.begin() << ",";
    }

    { // boost::range::max_element
        boost::container::vector<int> vector = { 1, 1, 1, 2, 2, 3, 5, 5, 6 };
        qDebug() << "boost::range::max_element =" << *boost::range::max_element(vector) << "position" << boost::range::max_element(vector) - vector.begin();
    }

    { // boost::range::merge
        boost::container::vector<int> vector1(5), vector2(5), final_vector(10);
        vector1 = { 3, 4, 0, 2, 1 };
        vector2 = { 7, 6, 8, 9, 5 };

        std::sort(boost::begin(vector1), boost::end(vector1));
        std::sort(boost::begin(vector2), boost::end(vector2));

        boost::range::merge(vector1, vector2, final_vector.begin());
        QDebug debug = qDebug();
        debug << "boost::range::merge vector =";
        for (const auto& element : final_vector) {
            debug << element;
        }
    }

    { // boost::range::min_element
        boost::container::vector<int> vector = { 1, 1, 1, 0, 2, 3, 5, 5, 6 };
        qDebug() << "boost::range::min_element =" << *boost::range::min_element(vector) << "position" << boost::range::min_element(vector) - vector.begin();
    }

    { // boost::range::mismatch
        std::string string1 = "abcdefg";
        std::string string2 = "abCdXfg";

        std::locale locale;

        auto predicat = [&locale](char lhs, char rhs) -> bool {
            return std::toupper(lhs, locale) < std::toupper(rhs, locale);
        };

        auto it1_pair = boost::range::mismatch(string1, string2);
        auto it2_pair = boost::range::mismatch(string1, string2, predicat);

        qDebug() << (it1_pair.first - string1.begin()) << *(it1_pair.first) << "!=" << *(it1_pair.second);
        qDebug() << (it2_pair.first - string1.begin()) << *(it2_pair.first) << "==" << *(it2_pair.second);
    }

    { // boost::range::nth_element
        boost::container::vector<int> vector = { 1, 1, 1, 0, 2, 3, 1, 5, 6 };
        boost::range::nth_element(vector, vector.begin() + 5);

        QDebug debug = qDebug();
        debug << "boost::range::nth_element vector =";
        for (const auto& element : vector) {
            debug << element;
        }
    }

    { // boost::range::partial_sort
        boost::container::vector<int> vector = { 0, 2, 3, 1, 5, 3, 2, 6 };
        boost::range::partial_sort(vector, vector.begin() + 5);

        QDebug debug = qDebug();
        debug << "boost::range::partial_sort vector =";
        for (const auto& element : vector) {
            debug << element;
        }
    }

    { // boost::range::partition
        boost::container::vector<int> vector = {14, 9, 10, 3, 119, 42, 8, 5};

        auto predicat = [](int element) -> bool {
            return (floor(log10(element)) + 1) <= 1;
        };

        boost::container::vector<int>::iterator partition_point;
        qDebug() << "boost::range::partition" << *boost::range::partition(vector, predicat);
    }

    { // boost::range::next_permutation boost::range::prev_permutation
        std::string string = "123";
        QDebug debug = qDebug();

        do {
            debug << string.c_str();
        } while (boost::range::next_permutation(string)); // boost::range::prev_permutation(string)
    }

    { // boost::range::random_shuffle
        boost::container::vector<int> vector = { 0, 2, 3, 1, 5, 3, 2, 6 };
        boost::range::random_shuffle(vector);

        QDebug debug = qDebug();
        debug << "boost::range::random_shuffle vector =";
        for (const auto& element : vector) {
            debug << element;
        }
    }

    { // boost::range::remove
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5 };
        QDebug debug = qDebug();
        auto iterator = boost::range::remove(vector, 4);
        debug << "boost::range::remove last =" << *iterator << "->";

        for (const auto& element : vector) {
            debug << element;
        }
    }

    { // boost::range::remove_copy
        boost::container::vector<int> vector1 { 1, 2, 5, 9, 5, 7, 5 };
        boost::container::vector<int> vector2 { 3, 4 };

        boost::range::remove_copy(vector1, std::back_inserter(vector2), 5);

        QDebug debug = qDebug();
        debug << "boost::range::remove_copy =";
        for (const auto& element : vector2) {
            debug << element;
        }
    }

    { // boost::range::remove_copy_if
        boost::container::vector<int> vector1 { 1, 2, 5, 9, 5, 10, 5 };
        boost::container::vector<int> vector2 { 3, 4 };

        auto predicat = [] (const int& element) -> bool {
            return element % 5 == 0;
        };

        boost::remove_copy_if(vector1, std::back_inserter(vector2), predicat);

        QDebug debug = qDebug();
        debug << "boost::remove_copy_if =";
        for (const auto& element : vector2) {
            debug << element;
        }
    }

    { // boost::range::remove_if
        boost::container::vector<int> vector { 1, 2, 5, 9, 5, 10, 5 };

        auto predicat = [] (const int& element) -> bool {
            return element % 5 == 0;
        };

        auto iterator_end = boost::range::remove_if(vector, predicat); // 5, 5, 10, 5 не удалены, они перемещены в конец

        QDebug debug = qDebug();
        debug << "boost::remove_if =";
        for (auto iterator = vector.begin(); iterator != iterator_end; ++iterator) {
            debug << *iterator;
        }
    }

    { // boost::range::replace
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5 };

        boost::range::replace(vector, 3, 10);
        QDebug debug = qDebug();

        debug << "boost::range::replace =";
        for (const auto& element : vector) {
            debug << element;
        }
    }

    { // boost::range::replace_copy
        boost::container::vector<int> vector1 = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> vector2;

        boost::range::replace_copy(vector1, std::back_inserter(vector2), 3, 10);
        QDebug debug = qDebug();

        debug << "boost::range::replace_copy =";
        for (const auto& element : vector2) {
            debug << element;
        }
    }

    { // oost::range::replace_copy_if
        boost::container::vector<int> vector1 = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> vector2;

        auto predicat = [] (const int& element) -> bool {
            return element % 2 == 0;
        };

        boost::range::replace_copy_if(vector1, std::back_inserter(vector2), predicat, 3);
        QDebug debug = qDebug();

        debug << "oost::range::replace_copy_if =";
        for (const auto& element : vector2) {
            debug << element;
        }
    }

    { // boost::range::replace_if
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5 };

        auto predicat = [] (const int& element) -> bool {
            return element % 2 == 0;
        };

        boost::range::replace_if(vector, predicat, 3);
        QDebug debug = qDebug();

        debug << "boost::range::replace_if =";
        for (const auto& element : vector) {
            debug << element;
        }
    }

    { // boost::range::reverse
        boost::container::vector<int> vector = { 1, 2, 3, 4, 5 };
        boost::range::reverse(vector); // boost::range::reverse_copy ещё и копирует

        QDebug debug = qDebug();

        debug << "boost::range::reverse =";
        for (const auto& element : vector) {
            debug << element;
        }
    }

    { // boost::range::rotate
        boost::container::vector<int> vector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        boost::range::rotate(vector, vector.begin() + 3); // boost::range::rotate_copy ещё и копирует
        QDebug debug = qDebug();

        debug << "boost::range::rotate =";
        for (const auto& element : vector) {
            debug << element;
        }
    }

    { // boost::range::search
        boost::container::vector<int> vector1 = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> vector2 = { 2, 3 };
        auto iterator = boost::range::search(vector1, vector2);

        qDebug() << "boost::range::search" << *iterator;
    }

    { // boost::range::search_n
        boost::container::vector<int> vector = { 1, 2, 3, 3, 3 };
        int count = 2;
        auto iterator = boost::range::search_n(vector, count, 3);

        qDebug() << "boost::range::search_n" << *iterator << "count" << count;
    }

    { // boost::range::set_algorithm
        boost::container::vector<int> vector1 = { 1, 2, 3, 4, 5 };
        boost::container::vector<int> vector2 = { 2, 3, 4, 5, 6, 7 };

        // проверяет вхождение
        qDebug() << "includes" << boost::range::includes(vector1, vector2);

        { // функция создает отсортированный диапазон, являющийся пересечением
            boost::container::vector<int> vector_out;

            boost::range::set_intersection(vector1, vector2, std::back_inserter(vector_out));
            QDebug debug = qDebug();

            debug << "set_intersection =";
            for (const auto& element : vector_out) {
                debug << element;
            }
        }

        { // создает отсортированный диапазон, который является объединением отсортированных диапазонов
            boost::container::vector<int> vector_out;

            boost::range::set_union(vector1, vector2, std::back_inserter(vector_out));
            QDebug debug = qDebug();

            debug << "set_union =";
            for (const auto& element : vector_out) {
                debug << element;
            }
        }

        { // создает отсортированный диапазон разницы диапазонов
            boost::container::vector<int> vector_out;

            boost::range::set_difference(vector1, vector2, std::back_inserter(vector_out));
            QDebug debug = qDebug();

            debug << "set_difference =";
            for (const auto& element : vector_out) {
                debug << element;
            }
        }

        { // функция строит отсортированный диапазон, который представляет собой заданную симметричную разность диапазонов

            boost::container::vector<int> vector_out;

            boost::range::set_symmetric_difference(vector1, vector2, std::back_inserter(vector_out));
            QDebug debug = qDebug();

            debug << "set_symmetric_difference =";
            for (const auto& element : vector_out) {
                debug << element;
            }
        }
    }

    { // boost::range::sort
        boost::container::vector<int> vector = { 1, 4, 3, 5, 2 };
        boost::range::sort(vector);

        QDebug debug = qDebug();

        debug << "boost::range::sort =";
        for (const auto& element : vector) {
            debug << element;
        }
    }

    { // boost::range::stable_partition
        boost::container::vector<int> vector = { 1, 4, 3, 5, 2, 6 };
        auto predicat = [] (const int& element) -> bool {
            return element % 2 == 0;
        };

        boost::range::stable_partition(vector, predicat);

        QDebug debug = qDebug();

        debug << "boost::range::stable_partition =";
        for (const auto& element : vector) {
            debug << element;
        }
    }

    { // boost::range::swap_ranges
        std::string string1 = "12345";
        std::string string2 = "67890";
        boost::range::swap_ranges(string1, string2);
        qDebug() << string1.c_str() << " " << string2.c_str();
    }

    { // boost::range::transform
        boost::container::vector<int> vector = { 1, 4, 3, 5, 2, 6 };
        boost::container::vector<int> vector_out;

        auto predicat = [] (int element) -> int {
            return element * 2;
        };

        boost::range::transform(vector, std::back_inserter(vector_out), predicat);

        QDebug debug = qDebug();

        debug << "boost::range::transform =";
        for (const auto& element : vector_out) {
            debug << element;
        }
    }

    { // boost::range::unique
        boost::container::vector<int> vector = {1, 1, 3, 1, 3, 3};

        auto vector_out = boost::range::unique(vector);
        QDebug debug = qDebug();

        debug << "boost::range::unique =";
        for (const auto& element : vector_out) {
            debug << element;

        }
    }

    { // boost::range::upper_bound
        std::string string = "abcdef";

        auto iterator = boost::range::upper_bound(string, 'd');

        qDebug() << "boost::range::upper_bound" << (iterator - string.begin());
    }
}

auto BoostRange::exampleBoostRangeAdaptors() -> void
{
    {

    }

    { // boost::adaptors::copied
        boost::container::vector<int> vector { 1, 5, 2, 2, 2, 3, 4, 5, 6 };
        boost::container::vector<int> vector_out = vector | boost::adaptors::copied(3, 6);

        QDebug debug = qDebug();

        debug << "boost::adaptors::copied =";
        for (const auto& element : vector_out) {
            debug << element;

        }
    }

    { // boost::adaptors::filtered
        struct is_even
        {
            auto operator()(int element) const -> bool {
                return element % 2 == 0;
            }
        };

        boost::container::vector<int> vector { 1, 5, 2, 2, 2, 3, 4, 5, 6 };

        QDebug debug = qDebug();

        debug << "boost::adaptors::filtered =";
        for (const auto& element : vector | boost::adaptors::filtered(is_even())) {
            debug << element;

        }
    }

    { // boost::adaptors::indexed
        boost::container::vector<int> vector { 1, 5, 2, 2, 2, 3, 4, 5, 6 };

        QDebug debug = qDebug();

        debug << "boost::adaptors::indexed =";
        for (const auto& element : vector | boost::adaptors::indexed(0)) {
            debug << "index" << element.index() << "value" << element.value();

        }
    }

    { // boost::adaptors::map
        const std::map<int, std::string> map = {
            std::make_pair(1, "one"),
            std::make_pair(2, "two"),
            std::make_pair(3, "three"),
        };

        QDebug debug = qDebug();

        debug << "boost::adaptors::map =";
        for (const auto & key : map | boost::adaptors::map_keys) { //boost::adaptors::map_values
            debug << key;
        }
    }

    { // boost::adaptors::replaced
        boost::container::vector<int> vector { 1, 5, 2, 2, 2, 3, 2, 5, 2 };

        QDebug debug = qDebug();

        debug << "boost::adaptors::replaced =";
        for (const auto & element : vector | boost::adaptors::replaced(2, 0)) {
            debug << element;
        }
    }

    { // boost::adaptors::replaced_if
        boost::container::vector<int> vector { 1, 5, 2, 2, 2, 3, 2, 5, 2 };
        auto predicat = [] (const int& element) -> bool {
            return element % 2 == 0;
        };
        QDebug debug = qDebug();

        debug << "boost::adaptors::replaced_if =";
        for (const auto & element : vector | boost::adaptors::replaced_if(predicat, 0)) {
            debug << element;
        }
    }

    { // boost::adaptors::reversed
        boost::container::vector<int> vector { 1, 2, 3, 4, 5 };

        QDebug debug = qDebug();

        debug << "boost::adaptors::reversed =";
        for (const auto & element : vector | boost::adaptors::reversed) {
            debug << element;
        }
    }

    { // boost::adaptors::sliced
        boost::container::vector<int> vector { 1, 2, 3, 4, 5, 6, 7, 8 };

        QDebug debug = qDebug();

        debug << "boost::adaptors::sliced =";
        for (const auto & element : vector | boost::adaptors::sliced(2, 6)) {
            debug << element;
        }
    }

    { // boost::adaptors::strided
        boost::container::vector<int> vector { 1, 2, 3, 4, 5, 6, 7, 8 };

        QDebug debug = qDebug();

        debug << "boost::adaptors::strided =";
        for (const auto & element : vector | boost::adaptors::strided(2)) {
            debug << element;
        }
    }

    { // boost::adaptors::tokenize
        const std::string string = "111 222 333 444";

        for (const auto& token : string | boost::adaptors::tokenized(boost::regex("\\w+"))) {
            size_t token_begin_idx = token.first - string.begin();
            size_t token_end_idx = token.second - string.begin();
            qDebug() << "  "
                     << "token [" << token.str().c_str() << "] "
                     << "begin: " << token_begin_idx << "; "
                     << "end: " << token_end_idx << "; "
                     << "length: " << token.length() << ";";
        }
    }

    { // boost::adaptors::transformed
        boost::container::vector<int> vector { 1, 2, 3, 4, 5, 6, 7, 8 };
        auto predicat = [] (const int& element) -> int {
            return element * 3;
        };
        QDebug debug = qDebug();

        debug << "boost::adaptors::transformed =";
        for (const auto & element : vector | boost::adaptors::transformed(predicat)) {
            debug << element;
        }
    }

    { // boost::adaptors::uniqued
        boost::container::vector<int> vector { 1, 2, 2, 4, 5, 5, 7, 1 };

        QDebug debug = qDebug();

        debug << "boost::adaptors::uniqued =";
        for (const auto & element : vector | boost::adaptors::uniqued) {
            debug << element;
        }
    }
}
