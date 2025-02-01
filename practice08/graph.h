#ifndef ADS_GRAPH_H
#define ADS_GRAPH_H


#include <vector>


class Vertex {
    friend class Graph;

private:
    char _name;
    std::vector<Vertex*> neighbors;

public:
    explicit Vertex(char);
    void addNeighbor(Vertex*);

    char getName() const;
    std::vector<Vertex*> getNeighbors() const;
};


class Graph {
private:
    std::vector<Vertex*> vertices;

public:
    Graph() = default;
    void setVertices(const std::vector<char>&, const std::vector<std::vector<int>>&);

    bool empty() const;
    int size() const;
    std::vector<Vertex*> getVertices() const;
};


#endif
