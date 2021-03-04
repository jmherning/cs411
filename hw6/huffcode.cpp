// Title:      huffcode.cpp
// Author:     Jason Herning
// Class:      CS411
// Instructor: Chris Hartman

#include "huffcode.hpp"  // for class HuffCode declaration
#include <utility>
using std::make_shared;
using std::string;
using std::move;


void HuffCode::setWeights(const Weights & weights) {

    if (weights.empty())
        return;

    for(auto & weight : weights)
        weight_queue.push(Node(weight.first, weight.second));

    if (weight_queue.size() == 1)
        codes_map(const_cast<Node &>(weight_queue.top()), "1");

    Node left, right;
    while(weight_queue.size() > 1) {

        left = weight_queue.top();
        weight_queue.pop();

        right = weight_queue.top();
        weight_queue.pop();

        weight_queue.push(Node(make_shared<Node>(left), make_shared<Node>(right), left._weight + right._weight));
    }
    codes_map(const_cast<Node &>(weight_queue.top()), "");
}



string HuffCode::encode(const string & uncoded_string) const {
    string encoding;
    for(char letter:uncoded_string)
        encoding+=huff_map.find(letter)->second;
    return encoding;
}


string HuffCode::decode(const string & encoded_string) const {
    string decoded_string, current;
    for(char letter:encoded_string) {
        current+=letter;
        for(const auto & i : huff_map)
            if(i.second == current) {
                decoded_string+=i.first;
                current.clear();
            }
    }
    return decoded_string;
}


void HuffCode::codes_map(Node & node, const string & code) {
    if (node._key) {
        huff_map.insert({node._key, code});
        return;
    }

    codes_map(*node._left_node, code + "0");
    codes_map(*node._right_node, code + "1");
}

Node::Node(shared_ptr<Node> left_node, shared_ptr<Node> right_node, int weight) :
        _left_node(move(left_node)),
        _right_node(move(right_node)),
        _key(0),
        _weight(weight)
{}

Node::Node(char key, int weight) :
        _key(key),
        _weight(weight)
{}
