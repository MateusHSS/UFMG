#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Ponto {
  double x, y;
};

// Distancia euclidiana de a para b.
double Distancia(Ponto a, Ponto b) {
  double x = (a.x - b.x);
  double y = (a.y - b.y);

  return sqrt(x*x + y*y);
}

// Coeficiente da reta que passa na origem e p.
double Inclinacao(Ponto p) {
  return atan2(p.y, p.x);
}

// Coeficiente da reta orientada de p para q.v1
double InclinacaoRelativa(Ponto p, Ponto q) {
  return atan2(q.y - p.y, q.x - p.x);
}

// Determina se ao caminhar de a para b e depois de b para c estamos fazendo uma curva a esquerda, a direita, ou seguindo em frente.
int TipoCurva(Ponto a, Ponto b, Ponto c) {
  double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
  
  if (v < 0) return -1; // esquerda.
  if (v > 0) return +1; // direita.
  return 0; // em frente.
}

// Classe do grafo a ser utilizada
class Grafo {
  private:
    int num_vertices;
    int num_arestas;
    int num_faces;
    vector<vector<int>> arestas;
    vector<Ponto> vertices;
    vector<vector<int>> faces; 
    void ordenaVizinhos(int indice);
    void descobreFaces();

  public:
    Grafo(int num_vertices, int num_arestas);
    int numFaces();
    void addAresta(int origem, int destino);
    void coord(int v, double x, double y);
    void printFaces();
};

// Inicializa o grafo
Grafo::Grafo(int num_vertices, int num_arestas) {
  this->num_vertices = num_vertices;
  this->num_arestas = num_arestas;
  this->vertices.resize(num_vertices + 1);
  this->arestas.resize(num_vertices + 1);
  this->num_faces = 2 + num_arestas - num_vertices;
}

// Adiciona uma aresta origem -> destino
void Grafo::addAresta(int origem, int destino) {
  this->arestas[origem].push_back(destino);
}

// Armazena a coordenada euclidiana do vertice v
void Grafo::coord(int v, double x, double y) {
  this->vertices[v].x = x;
  this->vertices[v].y = y;
}

// Número de faces do grafo
int Grafo::numFaces() {
  return this->num_faces;
}

// Ordena os vizinhos do vertice de acordo com a inclinação ou no tipo de curva (caso a inclinação seja a mesma)
void Grafo::ordenaVizinhos(int indice) {
  auto compara = [&](int a, int b) {
    Ponto p; 
    p.x = this->vertices[a].x - this->vertices[indice].x;
    p.y = this->vertices[a].y - this->vertices[indice].y;

    Ponto q; 
    q.x = this->vertices[b].x - this->vertices[indice].x;
    q.y = this->vertices[b].y - this->vertices[indice].y;

    double inclinacao_p = Inclinacao(p);
    double inclinacao_q = Inclinacao(q);

    if (inclinacao_p != inclinacao_q)
      return inclinacao_p < inclinacao_q;

    return TipoCurva(vertices[indice], vertices[a], vertices[b]) > 0;
  };
  
  sort(this->arestas[indice].begin(), this->arestas[indice].end(), compara);
}

// Descobre as faces do grafo
void Grafo::descobreFaces() {
  vector<vector<bool>> visit(this->num_vertices+1);

  for (int i = 1; i <= this->num_vertices; i++) {
    visit[i].resize(this->arestas[i].size(), false);
    this->ordenaVizinhos(i);
  }
  
  for (int i = 1; i <= this->num_vertices; i++) {
    for (int j = 0; j < this->arestas[i].size(); j++) {
      if (visit[i][j]) continue;

      vector<int> face;
      int v = i;
      int a = j;

      while(!visit[v][a]) {
        
        visit[v][a] = true;
        face.push_back(v);

        int adj = this->arestas[v][a];
        int prox = lower_bound(this->arestas[adj].begin(), this->arestas[adj].end(), v, [&](int a, int b) {
          Ponto p; 
          p.x = this->vertices[a].x - this->vertices[adj].x;
          p.y = this->vertices[a].y - this->vertices[adj].y;

          Ponto q; 
          q.x = this->vertices[b].x - this->vertices[adj].x;
          q.y = this->vertices[b].y - this->vertices[adj].y;

          double inclinacao_p = Inclinacao(p);
          double inclinacao_q = Inclinacao(q);
  
          if (inclinacao_p != inclinacao_q)
              return inclinacao_p < inclinacao_q;
  
          return TipoCurva(vertices[adj], vertices[a], vertices[b]) > 0;
          
        }) - this->arestas[adj].begin() + 1;
      
        if (prox == this->arestas[adj].size()) {
          prox = 0;
        }

        v = adj;
        a = prox;
      }
      face.push_back(face[0]);
      this->faces.push_back(face);
    }
  }
}

// Imprime a quantidade de faces e os vertices de cada face
void Grafo::printFaces() {
    cout << this->numFaces() << endl;
    this->descobreFaces();

    for (int i = 0; i < this->num_faces; i++) {
        cout << this->faces[i].size() << " ";

        for (int j = 0; j < this->faces[i].size(); j++) {
            cout << this->faces[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {
  int n, m, grau, vizinho;
  double x, y;

  // Lê os vertices e arestas
  cin >> n >> m;

  // Cria o grafo com n vertices e m arestas
  Grafo* g = new Grafo(n, m);

  // Lê as coordenadas de cada vertice e adiciona no grafo
  for (int i = 1; i <= n; i++) {
    cin >> x >> y >> grau;

    g->coord(i, x, y);

    for (int j = 0; j < grau; j++) {
      cin >> vizinho;
      g->addAresta(i, vizinho);
    }
  }

  // Imprime o numero de faces e seus vertices
  g->printFaces();
  
  return 0;
}