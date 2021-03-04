// Title:      build.cpp
// Author:     Jason Herning
// Class:      CS411
// Instructor: Chris Hartman
// Purpose:    Find optimal solution via exhaustive search

#include "build.h"
#include <cmath>


int final_toll(const Bridges & bridges) {

    int final_toll = 0;
    int size = bridges.size();
    int n = 0;

    for (const auto& b1:bridges) {
        for (int k= n + 1; k < size; ++k)
            if (invalid(b1, bridges[k]))
                return 0;
        final_toll += get_toll(b1);
        ++n;
    }
    return final_toll;
}

bool invalid(const Bridge & a, const Bridge & b)
{
    if (a[0] >= b[0])
        return (b[0] >= a[0] && a[1] >= b[1]) || a[1] <= b[1];
    return b[0] >= a[0] && a[1] >= b[1];
}

int get_toll(const Bridge & bridge){
    return bridge[2];
}


vector<Bridges> make_sets(const Bridges & bridges) {

    auto set_size = bridges.size();
    unsigned int power_set_size = pow(2, set_size);
    vector<Bridges> final_set(power_set_size);
    int count = 0;

    for (; count < power_set_size; ++count)
        for (int i=0; i < set_size; ++i)
            if ((1 << i & count) != 0)
                final_set[count].push_back(bridges[i]);

    return final_set;

}

int build(int w, int e, const Bridges & bridges) {

    auto set = make_sets(bridges);
    int toll = 0;

    for(const auto& i:set)
        if(final_toll(i) > toll)
            toll = final_toll(i);

    return toll;

}
