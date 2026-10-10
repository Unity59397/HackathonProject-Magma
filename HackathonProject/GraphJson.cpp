#include "GraphJson.h"
#include "json.hpp"

std::string toJson(const Graph& graph) {
    nlohmann::json result;

    // Make sure both keys exist as arrays, even for an empty graph
    result["nodes"] = nlohmann::json::array();
    result["edges"] = nlohmann::json::array();

    for (const Node& node : graph.getNodes()) {
        result["nodes"].push_back(node.getName());
    }

    for (const Edge& edge : graph.getEdges()) {
        nlohmann::json e;
        e["from"] = edge.getFrom();
        e["to"] = edge.getTo();
        result["edges"].push_back(e);
    }

    return result.dump(2);
}