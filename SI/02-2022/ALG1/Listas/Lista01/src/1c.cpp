#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

vector<vector<pair<int, int>>> g;
int dist[MAX];
int num_visitados = 0;


void dijkstra(int v) {
  priority_queue<pair<int, int>> pq;
  pq.push({-0, v});

  while(!pq.empty()){
    int d = -pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if(d > dist[u] && dist[u] != -1) continue;
    dist[u] = d;
    for(auto pv : g[u]){
      if(dist[pv.second] > d + pv.first || dist[pv.second] == -1){
        pq.push({-(d + pv.first), pv.second});
      }
    }
  }
}

int main() {
  
  //Conexo
  // g = {{{1, 1}, {1, 3}}, {{1, 0}, {1, 2}, {1, 4}}, {{1, 1}, {1, 5}}, {{1, 0}, {1, 5}}, {{1, 1}}, {{1, 2}, {1, 3}}};
  // Desconexo
  g = {{{1, 2}, {1, 3}}, {{1, 4}}, {{1, 0}, {1, 5}}, {{1, 0}, {1, 5}}, {{1, 1}}, {{1, 2}, {1, 3}} };

  memset(dist, -1, sizeof dist);
  dijkstra(0);

  bool nao_alcancavel = false;
  for(int i = 0; i < g.size(); i++){
    if(dist[i] == -1){
      nao_alcancavel = true;
      break;
    }
  }

  if(nao_alcancavel)
    cout << "0" << endl;
  else
    cout << "1" << endl;


  return 0;
}