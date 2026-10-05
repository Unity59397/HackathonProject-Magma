#include "Edge.h"

Edge::Edge(const std::string& from, const std::string& to) {
    this->from = from;
    this->to = to;
}

std::string Edge::getFrom() const {
    return from;
}

std::string Edge::getTo() const {
    return to;
}