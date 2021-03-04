// Title:      build.hpp
// Author:     Jason Herning
// Class:      CS411
// Instructor: Chris Hartman
// Purpose:    Find optimal solution via dynamic programming


#ifndef BUILD_HPP
#define BUILD_HPP

#include <vector>
using std::vector;

using Bridge = vector<int>;
using Bridges = vector<Bridge>;
using Table = vector<vector<int>>;

int build(int w, int e, const Bridges & bridges);






#endif
