#include "graph.h"


Vert::Vert(char name) {
    _name = name;
}


void Vert::addNeighbor(Vert *vertex) {
    neighbors.push_back(vertex);
}


char Vert::getName() const {
    return _name;
}


std::vector<Vert*> Vert::getNeighbors() const {
    return neighbors;
}

void Graph::setVertices(const std::vector<char> &names, const std::vector<std::vector<int>> &weights) {

    for (auto &name : names)
        vertices.push_back(new Vert(name));

    for (int i = 0; i < vertices.size(); ++i)
        for (int j = 0; j < vertices.size(); ++j)
            if (i != j && weights[i][j] != 0)
                vertices[i]->addNeighbor(vertices[j]);
}


bool Graph::empty() const {
    return vertices.empty();
}


int Graph::size() const {
    return vertices.size();
}


std::vector<Vert*> Graph::getVert() const {
    return vertices;
}