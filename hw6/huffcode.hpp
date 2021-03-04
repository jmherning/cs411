// Title:      huffcode.hpp
// Author:     Jason Herning
// Class:      CS411
// Instructor: Chris Hartman


#ifndef HUFFCODE_HUFFCODE_HPP
#define HUFFCODE_HUFFCODE_HPP

#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>
using std::shared_ptr;
using std::move;
using std::unordered_map;
using std::string;
using std::priority_queue;
using std::vector;


using Weights = unordered_map<char, int> ;

struct Node {
    Node() = default;
    Node(char key, int weight);
    Node(shared_ptr<Node>  left_node, shared_ptr<Node>  right_node, int weight);

    char _key    = 0;
    int  _weight = 0;
    shared_ptr<Node> _left_node  = nullptr;
    shared_ptr<Node> _right_node = nullptr;

};


struct compare {
    bool operator()(const Node & left_node, const Node & right_node) {
        return (left_node._weight > right_node._weight);
    }
};

// Class HuffCode
// Encoding & decoding using a Huffman code
class HuffCode {

// ***** HuffCode: ctors, dctor, op= *****
public:

    void setWeights(const unordered_map<char, int> &);
    string encode(const string &) const;
    string decode(const string &) const;
    void codes_map(Node &, const string &);


// ***** HuffCode: data members *****
private:
    priority_queue<Node, vector<Node>, compare> weight_queue;
    unordered_map<char, string> huff_map;

};  // End class HuffCode


#endif //HUFFCODE_HUFFCODE_HPP

