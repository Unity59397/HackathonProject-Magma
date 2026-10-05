#pragma once

#include <string>

class Edge {
private:
    std::string from;
    std::string to;

public:
    Edge(const std::string& from, const std::string& to);
    std::string getFrom() const;
    std::string getTo() const;
};