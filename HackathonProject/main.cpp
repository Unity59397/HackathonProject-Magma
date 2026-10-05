#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "Graph.h"

int main() {

    Graph graph;

    graph.addEdge("Law", "Parliament");
    graph.addEdge("Law", "Courts");

    //Call displaying functions so I can see wtf is going on. Thank you.
    graph.displayNodes();
    graph.displayEdges();

    return 0;
}