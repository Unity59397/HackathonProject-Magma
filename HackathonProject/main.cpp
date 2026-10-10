#include <iostream>
#include <string>
#include <exception>

#include "Graph.h"
#include "NoteLoader.h"
#include "GraphJson.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <notes_folder>" << std::endl;
        return 1;
    }

    std::string folder = argv[1];

    try {
        Graph graph = buildGraphFromFolder(folder);
        std::cout << toJson(graph) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}