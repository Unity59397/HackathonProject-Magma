#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <algorithm>

bool Graph::addNode(const std::string& name){
    //Check if a node already exists. If it already exists it will do nothing.
    if (hasNode(name)) {
        return false;
    }
    Node node(name);
    nodes.push_back(node);
    return true;
}

void Graph::addEdge(const std::string &from, const std::string &to) {
    if (hasEdge(from, to)) {
        return;
    }

    if (addNode(from)) {
        std::cout << "Created node: " << from << std::endl;
    }
    if (addNode(to)) {
        std::cout << "Created node: " << to << std::endl;
    }
    edges.emplace_back(from, to);
}

void Graph::displayNodes() const {
    for (const Node& node : nodes) {
        std::cout << node.getName() << std::endl;
    }
}

void Graph::displayEdges() const {
    for (const Edge& edge : edges) {
        std::cout << edge.getFrom() << "->" << edge.getTo() << std::endl;
    }
}

bool Graph::hasNode(const std::string& name) const {
    for (const auto& node : nodes) {
        if (node.getName() == name) return true;
    }
    return false;
}

bool Graph::hasEdge(const std::string& from, const std::string& to) const {
    for (const auto& edge : edges) {
        if (edge.getFrom() == from && edge.getTo() == to) {
            return true;
        }
    }
    return false;
}