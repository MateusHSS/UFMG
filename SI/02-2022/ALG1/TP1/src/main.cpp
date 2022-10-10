// C++ implementation to find if the given
// expression is satisfiable using the
// Kosaraju's Algorithm
#include <iostream>
#include <vector>
#include <stack>
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

// counter maintains the number of the SCC
int counter = 1;

// adds edges to form the original graph
void addEdges(int a, int b)
{
	adj[a].push_back(b);
}

// add edges to form the inverse graph
void addEdgesInverse(int a, int b)
{
	adjInv[b].push_back(a);
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

	scc[u] = counter;
}

// function to check 2-Satisfiability
void is2Satisfiable(int n, int m, int a[], int b[])
{
	// adding edges to the graph
  // adicionadno as arestas ao grafo
  cout << "teste" << endl;
	for(int i = 0; i < m; i++){
    // variavel x eh mapeada para x
    // variavel -x eh mapeada para n+x = n-(-x)

    /*
    * para a[i] ou b[i], adiciona arestas 
    * -a[i] -> b[i] E -b[i] -> a[i]
    */
    cout << "adicionando arestas para ("<< a[i] << ", " << b[i] << ")" << endl;
		if (a[i] > 0 && b[i] > 0){
      cout << "primeiro if " << endl;
			addEdges(a[i]+n, b[i]);
			addEdgesInverse(a[i]+n, b[i]);
			addEdges(b[i]+n, a[i]);
			addEdgesInverse(b[i]+n, a[i]);
		}

		else if (a[i]>0 && b[i]<0)
		{
      cout << "segundo if " << endl;
			addEdges(a[i]+n, n-b[i]);
			addEdgesInverse(a[i]+n, n-b[i]);
			addEdges(-b[i], a[i]);
			addEdgesInverse(-b[i], a[i]);
		}

		else if (a[i]<0 && b[i]>0)
		{
      cout << "terceiro if " << endl;
			addEdges(-a[i], b[i]);
			addEdgesInverse(-a[i], b[i]);
			addEdges(b[i]+n, n-a[i]);
			addEdgesInverse(b[i]+n, n-a[i]);
		}
    else if (a[i] == 0) {
      cout << "quarto if " << endl;
      if(b[i] < 0){
        addEdges(-b[i], n-b[i]);
        addEdgesInverse(-b[i], n-b[i]);
      }else if(b[i] > 0) {
        addEdges(b[i], b[i]+n);
        addEdgesInverse(b[i], b[i]+n);
      }
    }
    else if(b[i] == 0){
      cout << "quinto if " << endl;
      cout << "ZERO AQUIIIIII" << endl;
      if(a[i] < 0){
        addEdges(-a[i], n-a[i]);
        addEdgesInverse(-a[i], n-a[i]);
      }else if(a[i] > 0){
        addEdges(a[i]+n, a[i]);
        addEdgesInverse(a[i]+n, a[i]);
      }

      cout << "PASSSOUUUU" << endl;
    }
		else
		{
      cout << "ultimo if " << endl;
			addEdges(-a[i], n-b[i]);
			addEdgesInverse(-a[i], n-b[i]);
			addEdges(-b[i], n-a[i]);
			addEdgesInverse(-b[i], n-a[i]);
		}
	}

	// STEP 1 of Kosaraju's Algorithm which
	// traverses the original graph
	for (int i=1;i<=2*n;i++)
		if (!visited[i])
			dfsFirst(i);

	// STEP 2 of Kosaraju's Algorithm which
	// traverses the inverse graph. After this,
	// array scc[] stores the corresponding value
	while (!s.empty())
	{
		int n = s.top();
		s.pop();

		if (!visitedInv[n])
		{
			dfsSecond(n);
			counter++;
		}
	}

	for (int i=1;i<=n;i++)
	{
		// for any 2 variable x and -x lie in
		// same SCC
		if(scc[i]==scc[i+n])
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

// Driver function to test above functions
int main()
{
	int num_seguidores;
    int num_propostas;
    while(cin >> num_seguidores >> num_propostas){
      // vector<int> literal_um, literal_dois;
      // int literal_um[num_seguidores], literal_dois[num_seguidores];
      int* literal_um = (int*)malloc((num_seguidores * 2) * sizeof(int));
      int* literal_dois = (int*)malloc((num_seguidores * 2) * sizeof(int));
      int aux = 0;

      for (int i = 0; i < num_seguidores; i++){
        int voto_a_favor_um, voto_a_favor_dois;

        cin >> voto_a_favor_um;

        // literal_um.push_back(voto_a_favor_um);
        literal_um[aux] = voto_a_favor_um;

        cin >> voto_a_favor_dois;

        // literal_dois.push_back(voto_a_favor_dois);
        literal_dois[aux] = voto_a_favor_dois;

        aux++;

        int voto_contra_um, voto_contra_dois;

        cin >> voto_contra_um;

        // literal_um.push_back(-voto_contra_um);
        literal_um[aux] = -voto_contra_um;

        cin >> voto_contra_dois;

        // literal_dois.push_back(-voto_contra_dois);
        literal_dois[aux] = -voto_contra_dois;

        aux++;
      }    

      is2Satisfiable(num_propostas, num_seguidores*2, literal_um, literal_dois);
    }
}
