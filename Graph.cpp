// Student ID: 20558765
#include "Graph.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

Graph::Graph() {
    _nodes = {{}};
}
void Graph::add_edge(int src, int dst, std::string tag) {
    _nodes[src].push_back(Edge(dst, tag));
}

std::string Graph::to_string() const {
    std::string res = "Graph\n";
    for (unsigned int i = 0; i < _nodes.size(); i++) {
        res += "Node " + std::to_string(i) + " :\n";
        for (unsigned int j = 0; j < _nodes[i].size(); j++) {
            res += std::to_string(j) + "->" + std::to_string(_nodes[i][j]._dst) + ", " + _nodes[i][j]._tag + "\n";
        }
    }
    return res;
}

void Graph::make_silly_snake(){
    _nodes.clear();
    _nodes.resize(6);
    add_edge(0, 1, "i-see");
    add_edge(1, 2, "the-silly-snake");
    add_edge(2, 3, "i-be");
    add_edge(3, 4, "you-saw-me");
    add_edge(4, 5, "once-like");
    add_edge(5, 0, "kekule");
}
void Graph::make_mr_sticky(){
    _nodes.clear();
    _nodes.resize(7);
    add_edge(0, 1, ".");
    add_edge(1, 2, ".");
    add_edge(1, 3, ".");
    add_edge(1, 4, ".");
    add_edge(4, 5, ".");
    add_edge(4, 6, ".");
}
void Graph::make_driftin_dragonfly(){
    _nodes.clear();
    _nodes.resize(13);
    add_edge(0, 1, "dis-be-me-head");
    add_edge(1, 2, "me");
    add_edge(1, 5, "dis-be-me");
    add_edge(1, 9, "dis-be-me");
    add_edge(2, 3, "long-tail");
    add_edge(3, 4, "be-dis");
    add_edge(5, 6, "front-right");
    add_edge(6, 7, "me-right");
    add_edge(7, 8, "back");
    add_edge(8, 2, "be-dis");
    add_edge(9, 10, "front-left");
    add_edge(10, 11, "and-left");
    add_edge(11, 12, "back");
    add_edge(12, 2, "be-dis");
}
void Graph::make_slinky_star(){
    _nodes.clear();
    _nodes.resize(15);
    add_edge(0, 1, "-");
    add_edge(0, 3, "-");
    add_edge(0, 5, "-");
    add_edge(0, 7, "-");
    add_edge(0, 9, "-");
    add_edge(0, 11, "-");
    add_edge(0, 13, "-");
    add_edge(1, 2, "-");
    add_edge(3, 4, "-");
    add_edge(5, 6, "-");
    add_edge(7, 8, "-");
    add_edge(9, 10, "-");
    add_edge(11, 12, "-");
    add_edge(13, 14, "-");
}
void Graph::make_kathy_da_grate(){
    _nodes.clear();
    _nodes.resize(15);
    add_edge(0, 1, "-");
    add_edge(1, 2, "-");
    add_edge(2, 3, "-");
    add_edge(3, 4, "-");
    add_edge(4, 0, "-");
    add_edge(0, 5, "-");
    add_edge(5, 6, "-");
    add_edge(1, 7, "-");
    add_edge(7, 8, "-");
    add_edge(2, 9, "-");
    add_edge(9, 10, "-");
    add_edge(3, 11, "-");
    add_edge(11, 12, "-");
    add_edge(4, 13, "-");
    add_edge(13, 14, "-");
}
void Graph::make_dodos_in_space(){
     _nodes.clear();
    _nodes.resize(50);
    for (int i = 0; i < 50; i++) {
         if (i % 2 == 0)
            add_edge(i, i + 1, "Yippee-Dodo-#" + std::to_string(i));
    }
}
void Graph::make_purty_pitcher(){
    _nodes.clear();
    _nodes.resize(6);
    add_edge(0, 1, "Basketball");
    add_edge(1, 2, "Surface");
    add_edge(2, 3, "Air");
    add_edge(3, 4, "Hands");
    add_edge(4, 5, "Dribble");
    add_edge(5, 0, "Basketball");
}