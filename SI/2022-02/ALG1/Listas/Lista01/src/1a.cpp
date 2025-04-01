#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

vector<vector<int>> g;
bool visitados[MAX];
int num_visitados = 0;

int bfs(int v) {
  queue<int> q;

  q.push(v);
  visitados[v] = true;
  num_visitados++;

  while(!q.empty()){
    int v = q.front();
    q.pop();
    
    for(auto w : g[v]){
      if(!visitados[w]){
        q.push(w);
        visitados[w] = true;
        num_visitados++;
      }
    }

  }

  return num_visitados;
  
}


int main() {

  //Conexo
  g = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 5}, {1}, {2, 3}};
  // Desconexo
  // g = {{2, 3}, {4}, {0, 5}, {0, 5}, {1}, {2, 3} };

  memset(visitados, -1, sizeof visitados);
  bfs(0);

  cout << (num_visitados == g.size()) << endl;
  
  return 0;
}