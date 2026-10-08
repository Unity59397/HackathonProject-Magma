#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "Graph.h"
#include "LinkParser.h"

int main() {

    Graph graph;
    
    auto links = extractLinks("[[]] [[A]] and [[B|shown]] and [[|x]] and [[Note|]] end");
    for (const auto& l : links) std::cout << l << "\n";

    return 0;
}