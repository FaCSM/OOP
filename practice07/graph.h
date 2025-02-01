#ifndef ADS_GRAPH_H
#define ADS_GRAPH_H


#include <vector>


class Vert {
    friend class Graph;

private:
    char _name;
    std::vector<Vert*> neighbors;

public:
    explicit Vert(char);
    void addNeighbor(Vert*);

    char getName() const;
    std::vector<Vert*> getNeighbors() const;
};


class Graph {
private:
    std::vector<Vert*> vertices;

public:
    Graph() = default;
    void setVertices(const std::vector<char>&, const std::vector<std::vector<int>>&);

    bool empty() const;
    int size() const;
    std::vector<Vert*> getVert() const;
};


#endif
