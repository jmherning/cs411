// Title:      inversions.hpp
// Author:     Jason Herning
// Class:      CS411
// Instructor: Chris Hartman
// Credit:     Using mergesort implementation provided by Dr. Hartman

#ifndef INVERSIONS_HPP
#define INVERSIONS_HPP

#include <vector>
#include <iterator>
using std::distance;
using std::advance;
using std::vector;
using std::copy;
using std::size_t;


template<typename RAIter>
size_t mergeSort(RAIter first, RAIter last);

template <typename RAIter>
size_t stableMerge(RAIter first, RAIter middle, RAIter last);




template<typename RAIter>
size_t inversions(RAIter first, RAIter last) {
    return mergeSort(first, last);
}


template<typename RAIter>
size_t stableMerge(RAIter first, RAIter middle, RAIter last) {
    using Value = typename std::iterator_traits<RAIter>::value_type;

    vector<Value> buffer(distance(first, last));

    RAIter in1 = first;         // Read location in 1st half
    RAIter in2 = middle;        // Read location in 2nd half
    auto out = buffer.begin();  // Write location in buffer

    size_t count = 0;
    // Merge two sorted lists into a single list in buff.
    while (in1 != middle && in2 != last) {
        if (*in2 < *in1) {
            *out++ = *in2++;
            count += middle - in1;
        }
        else
            *out++ = *in1++;
    }

    copy(in1, middle, out);
    copy(in2, last, out);

    copy(buffer.begin(), buffer.end(), first);
    return count;
}

template<typename RAIter>
size_t mergeSort(RAIter first, RAIter last) {
    // Compute size of sequence
    size_t size = distance(first, last);

    // BASE CASE
    if (size <= 1)
        return 0;

    // RECURSIVE CASE
    RAIter middle = first;
    advance(middle, size/2);  // middle is iterator to middle of range

    // Recursively sort the two lists
    size_t left_side = mergeSort(first, middle);
    size_t right_side = mergeSort(middle, last);

    // And merge them
    return (stableMerge(first, middle, last) + left_side + right_side);
}





#endif