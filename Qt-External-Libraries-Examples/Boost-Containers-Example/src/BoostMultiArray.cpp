#include "BoostMultiArray.h"

#include <boost/multi_array.hpp>

auto BoostMultiArray::exampleBoostIMultiArray() -> void
{
    const int rows = 3;
    const int cols = 5;

    boost::multi_array<double, 2> array2D(boost::extents[rows][cols]);
    boost::multi_array<double, 2>::element* iterator = array2D.data();

    for (int i = 0; i < rows * cols; i++) {
        *iterator++ = i;
    }

    for (int i = 0; i < rows; i++) {
        QDebug debug = qDebug();
        for (int j = 0; j < cols; j++)
            debug << array2D[i][j];
    }
}
