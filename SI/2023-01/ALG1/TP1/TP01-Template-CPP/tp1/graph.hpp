#ifndef GRAPH_HPP
#define GRAPH_HPP
#define INF 0x3f3f3f3f

#include <list>
#include <queue>

using namespace std;

class Graph {
    int num_vertices;
    list<pair<int, int>> *arestas;

    public:
        Graph(int num_vertices);
        void add_aresta(int origem, int dest, int dist);
        int menor_caminho(int origem, int dest);
};

#endif // GRAPH_HPP