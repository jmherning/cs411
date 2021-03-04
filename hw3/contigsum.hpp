// Title:      contigsum.hpp
// Author:     Jason Herning
// Class:      CS411
// Instructor: Chris Hartman
// Purpose:    Find the greatest contiguous sum using Divide-and-Conquer


#ifndef CONTIGSUM_HPP
#define CONTIGSUM_HPP
#include <iterator>
#include <algorithm>
#include <tuple>
using std::distance;
using std::max;
using std::tuple;
using std::get;


// Tuple to hold greatest contiguous sum
using gcs = tuple<int, int, int, int>;

template<typename RAIter>
int contigSum(RAIter first, RAIter last);

template<typename RAIter>
gcs recursive(RAIter first, RAIter last);



template<typename RAIter>
int contigSum(RAIter first, RAIter last) {
    if (first == last)
        return 0;

    auto values = recursive(first, last);
    return get<0>(values);
}



template<typename RAIter>
gcs recursive(RAIter first, RAIter last) {

    if(distance(first, last) == 1)
        return *first < 0 ? gcs(0, 0, 0, (*first)) : gcs((*first), (*first), (*first), (*first));
    RAIter middle = first + (last - first)/2;

    auto left_side = recursive(first, middle);
    auto right_side = recursive(middle, last);
    return gcs( max(get<0>(left_side), max(get<0>(right_side), get<2>(left_side) + get<1>(right_side)) ),
                max(get<1>(left_side), get<3>(left_side) + get<1>(right_side)),
                max(get<2>(right_side), (get<2>(left_side) + get<3>(right_side) ) ),
                get<3>(left_side) + get<3>(right_side) );

}


#endif