// Title:      build.cpp
// Author:     Jason Herning
// Class:      CS411
// Instructor: Chris Hartman
// Purpose:    Find optimal solution via dynamic programming

#include "build.hpp"
#include <algorithm>
#include <vector>
using std::max;
using std::vector;
using std::max_element;


int build(int w, int e, const Bridges & bridges)
{

    Table table(w, vector<int>(e));
    for(auto bridge:bridges)
        table[(bridge[0])][(bridge[1])] = max(table[bridge[0]][bridge[1]], bridge[2]);

    for(int i = 1; i < w; ++i)
        for (int j = 1; j < e; ++j) {
            int elems[] = {table[i][j] + table[i - 1][j - 1], table[i - 1][j], table[i][j - 1]};
            table[i][j] = *max_element(elems, elems + 3);
        }

    return table[w - 1][e - 1];
}




