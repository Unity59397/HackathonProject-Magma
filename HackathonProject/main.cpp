#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "Graph.h"

int main() {

    Graph graph;
    
    graph.addEdge("Law", "Parliament");
    graph.addEdge("Law", "Courts");
    graph.addEdge("Courts", "Parliament");

    graph.removeEdge("Law", "Courts");
    graph.displayGraph();                 // Law->Parliament, Courts->Parliament remain

    graph.removeNode("Parliament");
    graph.displayGraph();                 // both edges gone, Parliament not listed

    graph.removeNode("Banana");           // should return false, not crash

    return 0;
}