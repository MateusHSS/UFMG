#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1000


std::vector<std::vector<int>> g;
bool visitados[MAX];
int num_visitados = 0;

int bfs(int v) {
  visitados[v] = true;
  num_visitados ++;

  for(auto w : g[v]){
    if(!visitados[w]){
      bfs(w);
    }
  }

  return num_visitados;
}

int main(){
  g = {{2, 3}, {4}, {0, 5}, {0, 5}, {1}, {2, 3} };

  memset(visitados, -1, sizeof visitados);
  bfs(0);

  if(num_visitados == 6){
    std::cout << "1" << std::endl;
    return 1; 
  }

  std::cout << "0" << std::endl;

  return 0;
}