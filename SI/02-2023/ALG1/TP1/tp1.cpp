#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Ponto {
  double x, y;
};

class Grafo {
private:
  int num_vertices;
  int num_arestas;
  vector<vector<int>> arestas;
  vector<Ponto> vertices;
  vector<vector<int>> faces;
  int num_faces;

  double calcularDistancia(Ponto a, Ponto b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
  }

  double calcularInclinacao(Ponto p) {
    return atan2(p.y, p.x);
  }

  double calcularInclinacaoRelativa(Ponto p, Ponto q) {
    return atan2(q.y - p.y, q.x - p.x);
  }

  int determinarTipoCurva(Ponto a, Ponto b, Ponto c) {
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0) return -1;  // curva à esquerda
    if (v > 0) return 1;   // curva à direita
    return 0;              // reta
  }

  void ordenarVizinhos(int indice) {
    auto comparar = [&](int a, int b) {
      Ponto p, q;
      p.x = vertices[a].x - vertices[indice].x;
      p.y = vertices[a].y - vertices[indice].y;
      q.x = vertices[b].x - vertices[indice].x;
      q.y = vertices[b].y - vertices[indice].y;

      double inclinacao_p = calcularInclinacao(p);
      double inclinacao_q = calcularInclinacao(q);

      if (inclinacao_p != inclinacao_q)
        return inclinacao_p < inclinacao_q;

      return determinarTipoCurva(vertices[indice], vertices[a], vertices[b]) > 0;
    };

    sort(arestas[indice].begin(), arestas[indice].end(), comparar);
  }

  void descobrirFaces() {
    vector<vector<bool>> visitado(num_vertices + 1);

    for (int i = 1; i <= num_vertices; i++) {
      visitado[i].resize(arestas[i].size(), false);
      ordenarVizinhos(i);
    }

    for (int i = 1; i <= num_vertices; i++) {
      for (int j = 0; j < arestas[i].size(); j++) {
        if (visitado[i][j]) continue;

        vector<int> face;
        int v = i;
        int a = j;

        while (!visitado[v][a]) {
          visitado[v][a] = true;
          face.push_back(v);

          int adjacente = arestas[v][a];
          int proximo = lower_bound(arestas[adjacente].begin(), arestas[adjacente].end(), v, [&](int a, int b) {
            Ponto p, q;
            p.x = vertices[a].x - vertices[adjacente].x;
            p.y = vertices[a].y - vertices[adjacente].y;
            q.x = vertices[b].x - vertices[adjacente].x;
            q.y = vertices[b].y - vertices[adjacente].y;

            double inclinacao_p = calcularInclinacao(p);
            double inclinacao_q = calcularInclinacao(q);

            if (inclinacao_p != inclinacao_q)
              return inclinacao_p < inclinacao_q;

            return determinarTipoCurva(vertices[adjacente], vertices[a], vertices[b]) > 0;
          }) - arestas[adjacente].begin() + 1;

          if (proximo == arestas[adjacente].size()) {
            proximo = 0;
          }

          v = adjacente;
          a = proximo;
        }
        face.push_back(face[0]);
        faces.push_back(face);
      }
    }
  }

public:
  Grafo(int num_vertices, int num_arestas) {
    this->num_vertices = num_vertices;
    this->num_arestas = num_arestas;
    vertices.resize(num_vertices + 1);
    arestas.resize(num_vertices + 1);
    num_faces = 2 + num_arestas - num_vertices;
  }

  void adicionarAresta(int origem, int destino) {
    arestas[origem].push_back(destino);
  }

  void definirCoordenadas(int vertice, double x, double y) {
    vertices[vertice].x = x;
    vertices[vertice].y = y;
  }

  int numeroFaces() {
    return num_faces;
  }

  void imprimirFaces() {
    cout << numeroFaces() << endl;
    descobrirFaces();

    for (int i = 0; i < num_faces; i++) {
      cout << faces[i].size() << " ";

      for (int j = 0; j < faces[i].size(); j++) {
        cout << faces[i][j] << " ";
      }

      cout << endl;
    }
  }
};

int main() {
  int n, m, grau, vizinho;
  double x, y;

  cin >> n >> m;
  Grafo* g = new Grafo(n, m);

  for (int i = 1; i <= n; i++) {
    cin >> x >> y >> grau;

    g->definirCoordenadas(i, x, y);

    for (int j = 0; j < grau; j++) {
      cin >> vizinho;
      g->adicionarAresta(i, vizinho);
    }
  }

  g->imprimirFaces();

  return 0;
}