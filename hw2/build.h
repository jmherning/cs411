// Title:      build.h
// Author:     Jason Herning
// Class:      CS411
// Instructor: Chris Hartman
// Purpose:    Find optimal solution via exhaustive search

#ifndef BUILD_H
#define BUILD_H
#include <vector>

using std::vector;
using Bridge = vector<int>;
using Bridges = vector<Bridge>;

int build(int w, int e, const Bridges & bridges);
vector<Bridges > make_sets(const Bridges & bridges);
int final_toll(const Bridges & bridges);
bool invalid(const Bridge & a, const Bridge & b);
int get_toll(const Bridge & bridge);















#endif