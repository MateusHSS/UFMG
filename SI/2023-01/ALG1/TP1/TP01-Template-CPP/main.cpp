#include <iostream>
#include "graph.hpp"

#define INF 0x3f3f3f3f
#define ORIGEM 1
#define EHIMPAR(x) (x % 2)

using namespace std;

int main(int argc, char const *argv[]) {
    int num_cidades, num_rodovias;
    int origem, destino, distancia;

    cin >> num_cidades;
    cin >> num_rodovias;

    int DESTINO = num_cidades;

    Graph *g = new Graph(num_cidades);

    for (int i = 0; i < num_rodovias; i++){
        cin >> origem;
        cin >> destino;
        cin >> distancia;

        if(!EHIMPAR(distancia)) {
            g->add_aresta(origem, destino, distancia);
        }
    }

    int res = g->menor_caminho(ORIGEM, DESTINO);

    if(res == INF) {
        cout << -1 << endl;
    }else {
        cout << res << endl;
    }
    

    return 0;
}