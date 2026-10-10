#include "LinkParser.h"

std::vector<std::string> extractLinks(const std::string& markdown) {
    std::vector<std::string> links;
    size_t pos = 0;

    while (true) {
        size_t openPos = markdown.find("[[", pos);
        if (openPos == std::string::npos) {
            break;
        }
        size_t closePos = markdown.find("]]", openPos + 2);
        if (closePos == std::string::npos) {
            break;
        }

        std::string content = markdown.substr(openPos + 2, closePos - (openPos + 2));
        size_t barPos = content.find("|");
        if (barPos != std::string::npos) {
            content = content.substr(0, barPos);
        }

        if (!content.empty()) {
            links.push_back(content);
        }

        pos = closePos + 2;
    }
    return links;
}

