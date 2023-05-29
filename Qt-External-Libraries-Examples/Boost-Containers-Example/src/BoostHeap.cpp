#include "BoostHeap.h"

#include <boost/heap/priority_queue.hpp>
#include <boost/heap/binomial_heap.hpp>
#include <boost/heap/fibonacci_heap.hpp>

auto BoostHeap::exampleBoostPriorityQueue() -> void
{
    boost::heap::priority_queue<int> priority_queue;

    priority_queue.push(3);
    priority_queue.push(1);
    priority_queue.push(2);

    for (auto& element : priority_queue)
        qDebug() << element;

    qDebug() << "pop" << priority_queue.top();
    priority_queue.pop();

    for (auto& element : priority_queue)
        qDebug() << element;
}

auto BoostHeap::exampleBoostBinomialHeap() -> void
{
    boost::heap::binomial_heap<int> binomial_heap;

    binomial_heap.push(3);
    binomial_heap.push(1);
    binomial_heap.push(2);

    boost::heap::binomial_heap<int> binomial_heap2;
    binomial_heap2.push(0);
    binomial_heap.merge(binomial_heap2);

    for (auto iterator = binomial_heap.ordered_begin(); iterator != binomial_heap.ordered_end(); ++iterator)
        qDebug() << *iterator;

    qDebug() << binomial_heap2.empty();

    auto handle = binomial_heap.push(5);
    binomial_heap.update(handle, 4);

    for (auto iterator = binomial_heap.ordered_begin(); iterator != binomial_heap.ordered_end(); ++iterator)
        qDebug() << *iterator;
}

struct node
{
    int id;

    node(int i) :
        id(i)
    {

    }
};

struct compare_node
{
    auto operator()(const node& firstNode, const node& secondNode) const -> bool
    {
        return firstNode.id > secondNode.id;
    }
};

auto BoostHeap::exampleBoostFibonacciHeap() -> void
{
    boost::heap::fibonacci_heap<node, boost::heap::compare<compare_node>> fibonacci_heap;
    fibonacci_heap.push(node(3));
    fibonacci_heap.push(node(2));
    fibonacci_heap.push(node(1));

    for(const node& element : fibonacci_heap) {
        qDebug() << element.id;
    }
}
