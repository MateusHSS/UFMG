#include <bits/stdc++.h>

typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

class Canal {
  public:
    ll ano_conclusao;
    ll tempo_travessia;
    ll custo_construcao;

    Canal(ll ano_conclusao, ll tempo_travessia, ll custo_construcao) : ano_conclusao(ano_conclusao), tempo_travessia(tempo_travessia), custo_construcao(custo_construcao){};
};

class Grafo{
  private:
    ll num_vertices, num_arestas;
    vector<vector<pair<ll, Canal>>> arestas;
    vector<pair<ll, pair<ll, ll>>> arestas_kruskal1;
    vector<pair<ll, pair<ll, ll>>> arestas_kruskal2;
    vector<ll> vertices;
    vector<ll> componentes;
    vector<ll> tam_comp;

    void inicializa_dsu(ll v);
    ll find(ll vertice);
    void join(ll v1, ll v2);
  public:
    Grafo(ll num_vertices, ll num_arestas);
    void add_aresta(ll origem, ll destino, ll ano_conclusao, ll tempo_travessia, ll custo_construcao);
    pair<int, vector<ll>> menor_caminho(int v);
    pair<ll, vector<tuple<ll, ll, ll>>> kruskal(ll v);
    pair<ll, vector<tuple<ll, ll, ll>>> kruskal2(ll v);
    void teste(vector<int> pai, int v);
};

Grafo::Grafo(ll num_vertices, ll num_arestas) {
  this->num_vertices = num_vertices;
  this->num_arestas = num_arestas;
  this->vertices.resize(num_vertices + 1);
  this->arestas.resize(num_arestas + 1);
};

void Grafo::add_aresta(ll origem, ll destino, ll ano_conclusao, ll tempo_travessia, ll custo_construcao) {
  origem--;
  destino--;
  Canal c = Canal(ano_conclusao, tempo_travessia, custo_construcao);
  this->arestas[origem].push_back(make_pair(destino, c));
  this->arestas[destino].push_back(make_pair(origem, c));

  this->arestas_kruskal1.push_back(make_pair(ano_conclusao, make_pair(origem, destino)));
  this->arestas_kruskal2.push_back(make_pair(custo_construcao, make_pair(origem, destino)));
}

pair<int, vector<ll>> Grafo::menor_caminho(int v) {
  v--;
  vector<ll> dist(this->num_vertices);
  vector<int> conectores(this->num_arestas, -1);

  for (ll i = 0; i < this->num_vertices; i++) dist[i] = LINF;
	
  dist[v] = 0;
  
	priority_queue<pair<ll, int>> pq;
	pq.emplace(0, v);
 
	while (pq.size()) {
    pair<ll, ll> top = pq.top();
    pq.pop();
    ll ndist = top.first;
    int u = top.second;

		if (-ndist > dist[u]) continue;
 
		for (auto vizinho : this->arestas[u]) {
      if (dist[vizinho.first] > dist[u] + vizinho.second.tempo_travessia) {
			  dist[vizinho.first] = dist[u] + vizinho.second.tempo_travessia;
			  pq.emplace(-dist[vizinho.first], vizinho.first);
        conectores[vizinho.first] = vizinho.second.ano_conclusao;
		  }
    }
	}

  return make_pair(*max_element(conectores.begin(), conectores.end()), dist);
}

void Grafo::inicializa_dsu(ll v) {
  this->componentes.resize(v);
  this->tam_comp.resize(v);

  fill(this->tam_comp.begin(), this->tam_comp.end(), 1);

  iota(this->componentes.begin(), this->componentes.end(), 0);
}

ll Grafo::find(ll vertice) {   
  return vertice == this->componentes[vertice] ? vertice : this->componentes[vertice] = this->find(this->componentes[vertice]); 
}

void Grafo::join(ll a, ll b) {
  a = this->find(a);
  b = this->find(b);

  if (a == b) return;

  if (this->tam_comp[a] < this->tam_comp[b]) {
    swap(a, b);
  }

  this->tam_comp[a] += this->tam_comp[b];
  this->componentes[b] = a;
}

pair<ll, vector<tuple<ll, ll, ll>>> Grafo::kruskal(ll n) {
  this->inicializa_dsu(n);

	sort(this->arestas_kruskal1.begin(), this->arestas_kruskal1.end());

	ll cost = 0;
	vector<tuple<ll, ll, ll>> mst;
  for(auto v : this->arestas_kruskal1) {
    if (this->find(v.second.first) != this->find(v.second.second)) {
      mst.emplace_back(v.first, v.second.first, v.second.second);
      cost += v.first;
      this->join(v.second.first, v.second.second);
    }
  }

	return {cost, mst};
}

pair<ll, vector<tuple<ll, ll, ll>>> Grafo::kruskal2(ll n) {
  this->inicializa_dsu(n);

	sort(this->arestas_kruskal2.begin(), this->arestas_kruskal2.end());

	ll cost = 0;
	vector<tuple<ll, ll, ll>> mst;
  for(auto v : this->arestas_kruskal2) {
    if (this->find(v.second.first) != this->find(v.second.second)) {
      mst.emplace_back(v.first, v.second.first, v.second.second);
      cost += v.first;
      this->join(v.second.first, v.second.second);
    }
  }

	return {cost, mst};
}

int main() {
  ll num_vertices;
  ll num_arestas;
  ll origem;
  ll destino;
  ll ano_construcao;
  ll tempo_travessia;
  ll custo_construcao;

  scanf("%lld", &num_vertices);
  scanf("%lld", &num_arestas);

  Grafo* g = new Grafo(num_vertices, num_arestas);

  for (int i = 0; i < num_arestas; i++) {
    scanf("%lld", &origem);
    scanf("%lld", &destino);
    scanf("%lld", &ano_construcao);
    scanf("%lld", &tempo_travessia);
    scanf("%lld", &custo_construcao);
    g->add_aresta(origem, destino, ano_construcao, tempo_travessia, custo_construcao);
  }

  pair<ll, vector<ll>> custos = g->menor_caminho(1);
  
  for(ll i = 0; i < num_vertices; i++) {
    cout << custos.second[i] << endl;
  }
  
  cout << custos.first << endl;
  vector<tuple<ll, ll, ll>> mst = g->kruskal(num_vertices).second;

  sort(mst.begin(), mst.end());

  cout << get<0>(mst.back()) << endl;

  cout << g->kruskal2(num_vertices).first << endl;

  return 0;
}
