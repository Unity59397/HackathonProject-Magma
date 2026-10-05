#pragma once

#include <vector>
#include <string>
#include "Node.h"
#include "Edge.h"

class Graph {
private:
    std::vector<Node> nodes;
    std::vector<Edge> edges;

    //Checks
    bool hasNode(const std::string& name) const;
    bool hasEdge(const std::string& from, const std::string& to) const;

public:
    // Nodes
    bool addNode(const std::string& name);
    void removeNode(std::string name);

    // Edges
    void addEdge(const std::string& from,const std::string& to);
    bool removeEdge(std::string& from, std::string& to);    

    // Display
    void displayNodes() const;
    void displayEdges() const;
    void displayGraph() const;
};