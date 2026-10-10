#include "NoteLoader.h"
#include "LinkParser.h"

#include <filesystem>
#include <sstream>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

static std::string readFile(const fs::path& path) {
    std::ifstream file(path);
        if (!file) {
            return "";
    }
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

Graph buildGraphFromFolder(const std::string& folder) {
    Graph graph;

    for (const auto& entry : fs::directory_iterator(folder)) {
        if (entry.path().extension() != ".md") {
            continue;
        }
        std::string noteName = entry.path().stem().string();
        graph.addNode(noteName);
        std::string text = readFile(entry.path());
        auto links = extractLinks(text);
        for (const auto& link : links) {
            graph.addEdge(noteName, link);
        }
    }

    return graph;
}