#include "graph.hpp"
#include <iostream>

using namespace std;

// O vertice "par" x será representado por 2x
int par(int x) {
    return x * 2;
}

// O vértice "impar" x será representado por 2x + 1
int impar(int x) {
    return (x * 2) + 1;
}

Graph::Graph(int num_vertices) {
    this->num_vertices = (num_vertices * 2) + 1;
    this->arestas = new list<pair<int, int>> [(num_vertices * 2) + 2];
}

// Para cada aresta adiciona também a sua aresta "espelho"
void Graph::add_aresta(int origem, int dest, int dist) {
    this->arestas[par(origem)].push_back({impar(dest), dist});
    this->arestas[impar(origem)].push_back({par(dest), dist});
    this->arestas[impar(dest)].push_back({par(origem), dist});
    this->arestas[par(dest)].push_back({impar(origem), dist});
}

// Calcula o menor caminho com um numero par de arestas entre 2 vertices 
int Graph::menor_caminho(int origem, int dest) {
    // Fila de prioridades de um pair <distancia, posicao>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int dist[this->num_vertices];
    
    // Para cada vertice do grafo, inicializa a distancia como INF
    for (int i = 0; i < this->num_vertices; i++){
        dist[i] = INF;
    }

    // Adiciona a origem como o primeiro da fila de busca e inicializa a distancia dele como 0
    pq.push({0, par(origem)});
    dist[par(origem)] = 0;

    while(!pq.empty()) {
        // Pega o primeiro da fila
        int u = pq.top().second;
        // Tira o primeiro da fila
        pq.pop();

        // Itera sobre todos os vizinhos dele
        for(pair<int, int> p : this->arestas[u]) {
            // Pega a posicao do vizinho
            int v = p.first;
            // Pega a distancia do vizinho
            int distancia = p.second;
            
            // Verifica se a distancia do vizinho é maior que a distancia atual + a da rodovia pro vizinho 
            if(dist[u] + distancia < dist[v] ) {
                dist[v] = dist[u] + distancia;
                pq.push({dist[v], v});
            }
        }
    }
    
    // Retorna a distancia para o destino
    return dist[par(dest)];
}
