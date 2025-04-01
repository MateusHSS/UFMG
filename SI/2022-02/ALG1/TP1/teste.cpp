// C++ implementation to find if the given
// expression is satisfiable using the
// Kosaraju's Algorithm
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <string>
using namespace std;
  
const int MAX = 100000;
  
// data structures used to implement Kosaraju's
// Algorithm. Please refer
// https://www.geeksforgeeks.org/strongly-connected-components/
vector<int> adj[MAX];
vector<int> adjInv[MAX];
bool visited[MAX];
bool visitedInv[MAX];
stack<int> s;
  
// this array will store the SCC that the
// particular node belongs to
int scc[MAX];

int num_componente = 1;
  
// adds edges to form the original graph
void addEdges(int primeiro_literal, int segundo_literal)
{
  cout << "teste 6" << endl;
  cout << "adj["<<primeiro_literal<<"].push_back(" << segundo_literal << ")" << endl;
  adj[primeiro_literal].push_back(segundo_literal);
}
  
// add edges to form the inverse graph
void addEdgesInverse(int primeiro_literal, int segundo_literal)
{ 
  cout << "teste 8" << endl;
  adjInv[segundo_literal].push_back(primeiro_literal);
}
  
// for STEP 1 of Kosaraju's Algorithm
void dfsFirst(int u)
{
    if(visited[u])
        return;
  
    visited[u] = 1;
  
    for (int i=0;i<adj[u].size();i++)
        dfsFirst(adj[u][i]);
  
    s.push(u);
}
  
// for STEP 2 of Kosaraju's Algorithm
void dfsSecond(int u)
{
    if(visitedInv[u])
        return;
  
    visitedInv[u] = 1;
  
    for (int i=0;i<adjInv[u].size();i++)
        dfsSecond(adjInv[u][i]);
  
    scc[u] = num_componente;
}
  
// function to check 2-Satisfiability
void is2Satisfiable(int num_propostas, int num_clausulas, vector<int> primeiro_literal, vector<int> segundo_literal)
{
    // adding edges to the graph
    for(int i = 0; i < num_clausulas; i++){
      cout << "Acessando clausula: " << i << endl;
      cout << "(" << primeiro_literal[i] << " OR " << segundo_literal[i] << ")" << i << endl;
      // variable x is mapped to x
      // variable -x is mapped to num_propostas+x = num_propostas-(-x)

      // for primeiro_literal[i] or segundo_literal[i], addEdges -primeiro_literal[i] -> segundo_literal[i]
      // AND -segundo_literal[i] -> primeiro_literal[i]
      if (primeiro_literal[i] > 0 && segundo_literal[i] > 0){
        cout << "teste 1" << endl;
        addEdges(primeiro_literal[i]+num_propostas, segundo_literal[i]);
        addEdgesInverse(primeiro_literal[i]+num_propostas, segundo_literal[i]);
        addEdges(segundo_literal[i]+num_propostas, primeiro_literal[i]);
        addEdgesInverse(segundo_literal[i]+num_propostas, primeiro_literal[i]);

      } else if (primeiro_literal[i] > 0 && segundo_literal[i] < 0){
        cout << "teste 2" << endl;
        addEdges(primeiro_literal[i]+num_propostas, num_propostas-segundo_literal[i]);
        addEdgesInverse(primeiro_literal[i]+num_propostas, num_propostas-segundo_literal[i]);
        addEdges(-segundo_literal[i], primeiro_literal[i]);
        addEdgesInverse(-segundo_literal[i], primeiro_literal[i]);

      } else if (primeiro_literal[i] < 0 && segundo_literal[i] > 0){
        cout << "teste 3" << endl;
        addEdges(-primeiro_literal[i], segundo_literal[i]);
        addEdgesInverse(-primeiro_literal[i], segundo_literal[i]);
        addEdges(segundo_literal[i]+num_propostas, num_propostas-primeiro_literal[i]);
        addEdgesInverse(segundo_literal[i]+num_propostas, num_propostas-primeiro_literal[i]);

      } else if(segundo_literal[i] == 0) {
        
        addEdges(primeiro_literal[i], primeiro_literal[i]);
        addEdgesInverse(primeiro_literal[i], primeiro_literal[i]);

      } else if(primeiro_literal[i] == 0) {
        
        addEdges(segundo_literal[i], segundo_literal[i]);
        addEdgesInverse(segundo_literal[i], segundo_literal[i]);
      
      }else{
        cout << "teste 4" << endl;
        addEdges(-primeiro_literal[i], num_propostas-segundo_literal[i]);
        cout << "teste 7" << endl;
        addEdgesInverse(-primeiro_literal[i], num_propostas-segundo_literal[i]);
        cout << "teste 9" << endl;
        addEdges(-segundo_literal[i], num_propostas-primeiro_literal[i]);
        cout << "teste 10" << endl;
        addEdgesInverse(-segundo_literal[i], num_propostas-primeiro_literal[i]);
        cout << "teste 11" << endl;
      }
    }
    cout << "teste 12" << endl;
    // STEP 1 of Kosaraju's Algorithm which
    // traverses the original graph
    for (int i=1;i<=2*num_propostas;i++)
        if (!visited[i])
            dfsFirst(i);
  
    // STEP 2 of Kosaraju's Algorithm which
    // traverses the inverse graph. After this,
    // array scc[] stores the corresponding value
    while (!s.empty())
    {
        int num_propostas = s.top();
        s.pop();
  
        if (!visitedInv[num_propostas])
        {
            dfsSecond(num_propostas);
            num_componente++;
        }
    }
  
    for (int i=1;i<=num_propostas;i++)
    {
        // for any 2 variable x and -x lie in
        // same SCC
        if(scc[i]==scc[i+num_propostas])
        {
            cout << "nao" << endl;
            return;
        }
    }
  
    // no such variables x and -x exist which lie
    // in same SCC
    cout << "sim" << endl;
    return;
}
  
//  Driver function to test above functions
int main(int argc, char **argv){
    int num_seguidores;
    int num_propostas;
    while(cin >> num_seguidores >> num_propostas){
      vector<int> literal_um, literal_dois;

      for (int i = 0; i < num_seguidores; i++){
        int voto_a_favor_um, voto_a_favor_dois;

        cin >> voto_a_favor_um;

        literal_um.push_back(voto_a_favor_um);

        cin >> voto_a_favor_dois;

        literal_dois.push_back(voto_a_favor_dois);

        int voto_contra_um, voto_contra_dois;

        cin >> voto_contra_um;

        literal_um.push_back(-voto_contra_um);

        cin >> voto_contra_dois;

        literal_dois.push_back(-voto_contra_dois);
      }
      
      cout << "Primeiros literais" << endl;
      for (int i = 0; i < literal_um.size(); i++)
      {
        cout << literal_um[i] << ", ";
      }
      cout << endl;
      cout << "Segundos literais" << endl;
      for (int i = 0; i < literal_dois.size(); i++)
      {
        cout << literal_dois[i] << ", ";
      }
      cout << endl;
    

      is2Satisfiable(num_propostas, num_seguidores*2, literal_um, literal_dois);
    }

    
    // n is the number of variables
    // 2n is the total number of nodes
    // num_clausulas is the number of clauses
    int n = 5, num_clausulas = 7;
  
    // each clause is of the form primeiro_literal or segundo_literal
    // for num_clausulas clauses, we have primeiro_literal[num_clausulas], segundo_literal[num_clausulas]
    // representing primeiro_literal[i] or segundo_literal[i]
  
    // Note:
    // 1 <= x <= N for an uncomplemented variable x
    // -N <= x <= -1 for primeiro_literal complemented variable x
    // -x is the complement of primeiro_literal variable x
  
    // The CNF being handled is:
    // '+' implies 'OR' and '*' implies 'AND'
    // (x1+x2)*(x2’+x3)*(x1’+x2’)*(x3+x4)*(x3’+x5)*
    // (x4’+x5’)*(x3’+x4)
    // int primeiro_literal[] = {1, -3, 3, -1, 1, -2, 1, -3};
    // int segundo_literal[] = {2, -4, 4, -2, 3, -4, 4, -2};
  
    // // We have considered the same example for which
    // // Implication Graph was made
    // is2Satisfiable(n, num_clausulas, primeiro_literal, segundo_literal);
  
    return 0;
}