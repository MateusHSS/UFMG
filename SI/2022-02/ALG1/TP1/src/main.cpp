#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Grafo {
	private:
		int n;
		vector<int> *adj;
		bool *visitados;
		stack<int> *pilha;
		int *comp_fort_con;
		int contador_componente;

	public:
		Grafo(int n);
		void adicionarAresta(int n1, int n2);
		void dfsPilha(int n);
		void detectaComponentes(int n);
		Grafo inverso();
		void ehSatisfazivel(int n);
		void dfsComponentes();
		void componentes(Grafo *g_t, int n);
};

// Construtor
Grafo::Grafo(int n){
	this->n = n;
	this->adj = new vector<int>[n+1];
	this->visitados = new bool[this->n+1];
	this->pilha = new stack<int>;
	this->comp_fort_con = new int[this->n+1];
	this->contador_componente = 1;

	for(int i = 0; i < n; i++){
		this->visitados[i] = false;
	}
}

// Adiciona arestas no grafo
void Grafo::adicionarAresta(int n1, int n2){
	adj[n1].push_back(n2);
}

void Grafo::dfsPilha(int n) {
	// Verifica se o vertice n já foi visitado
	if(this->visitados[n]) return;

	// marca o n como visitado
	this->visitados[n] = true;

	// percorre os vizinhos de n e chama a bfs pra cada um deles
	for (int i = 0; i < this->adj[n].size(); i++){
		this->dfsPilha(this->adj[n][i]);
	}

	// depois que todos os vizinhos de n foram visitados, insere n na pilha
	pilha->push(n);
	return;
}

// Calcula as componentes fortemente conexas de todos os vertices do grafo
void Grafo::dfsComponentes() {
	// Cria um grafo inverso ao original
	Grafo g_t = this->inverso();

	// Desempilha os vertices e calcula em qual componente ele se encontra
	while(!this->pilha->empty()){
		int n = this->pilha->top();
		this->pilha->pop();

		if(!g_t.visitados[n]){
			this->componentes(&g_t, n);
			this->contador_componente++;
		}
	}
}

// Calcula as componentes fortemente conexas a partir de um vertice
void Grafo::componentes(Grafo *g_t, int n) {
	// Verifica se o vertice n ja foi visitado
	if(g_t->visitados[n]) return;

	// marca o n como visitado
	g_t->visitados[n] = true;

	// percorre todos os vizinhos de n e calcula a componente de cada um
	for(int i = 0; i < g_t->adj[n].size(); i++){
		this->componentes(g_t, g_t->adj[n][i]);
	}

	// define a componente conexa de n depois de visitar todos os vizinhos
	this->comp_fort_con[n] = this->contador_componente;
}

// gera o grafo inverso
Grafo Grafo::inverso() {
	Grafo g = Grafo(this->n);

	// para cada aresta do grafo original, cria uma aresta inversa e insere no grafo inverso
	for(int i = 0; i < this->n; i++){
		for(int j = 0; j < this->adj[i].size(); i++){
			g.adj[j].push_back(i);
		}
	}

	return g;
}

// verifica se a expresao é satisfazivel
void Grafo::ehSatisfazivel(int n) {
	// faz uma bfs em todos os vertices do grafo e insere cada um na pilha
	for (int i = 1; i <= n; i++){
		if(!this->visitados[i]){
			this->dfsPilha(i);
		}
	}
	
	// calculando as componentes fortemente conexas do grafo
	this->dfsComponentes();

	// verifica se o vertice esta na mesma componente fortemente conexa que o seu complementar
	for (int i = 1; i <= n; i++){
		if(this->comp_fort_con[i] == this->comp_fort_con[i+n]){
			cout << "nao" << endl;
			return;
		}
	}

	cout << "sim" << endl;
}

// processa os votos de todos os seguidores sobre as propostas
void processaVotos(int n, int m, int a[], int b[]){
	Grafo g = Grafo(2*n);

	/*
	* Os votos sao mapeados de acordo com o numero de propostas do candidato.
	* Para simbolizar um voto contrario, ou seja, negativo, o algoritmo utiliza
	* a soma do identificador proposta (x) + o numero de propostas do candidato (n),
	* ou seja x = x e -x = n-x
	*/
	for(int i = 0; i < m; i++){
		if (a[i] > 0 && b[i] > 0){
			g.adicionarAresta(a[i]+n, b[i]);
			g.adicionarAresta(b[i]+n, a[i]);
		}else if (a[i]>0 && b[i]<0){
			g.adicionarAresta(a[i]+n, n-b[i]);
			g.adicionarAresta(-b[i], a[i]);
		}else if (a[i]<0 && b[i]>0){
			g.adicionarAresta(-a[i], b[i]);
			g.adicionarAresta(b[i]+n, n-a[i]);
		}else if (a[i] == 0) {
      if(b[i] < 0){
				g.adicionarAresta(-b[i], n-b[i]);
      }else if(b[i] > 0) {
				g.adicionarAresta(b[i], b[i]+n);
      }
    }else if(b[i] == 0){
      if(a[i] < 0){
				g.adicionarAresta(-a[i], n-a[i]);
      }else if(a[i] > 0){
				g.adicionarAresta(a[i]+n, a[i]);
      }
    }else if(a[i]<0 && b[i] < 0){
			g.adicionarAresta(-a[i], n-b[i]);
			g.adicionarAresta(-b[i], n-a[i]);
		}
	}

	// verifica se a expressa é satisfazivel
	g.ehSatisfazivel(2*n);
	return;
}


int main() {
	int num_seguidores;
	int num_propostas;

	// lê o arquivo de entrada, até que as entradas sejam 0 e 0
	while(cin >> num_seguidores >> num_propostas){

		if(num_seguidores == 0 && num_propostas == 0) return 0;
		int* literal_um = (int*)malloc((num_seguidores * 2) * sizeof(int));
		int* literal_dois = (int*)malloc((num_seguidores * 2) * sizeof(int));
		int aux = 0;

		// lê os votos de cada seguidor
		for (int i = 0; i < num_seguidores; i++){
			int voto_a_favor_um, voto_a_favor_dois;

			cin >> voto_a_favor_um;

			literal_um[aux] = voto_a_favor_um;

			cin >> voto_a_favor_dois;

			literal_dois[aux] = voto_a_favor_dois;

			aux++;

			int voto_contra_um, voto_contra_dois;

			cin >> voto_contra_um;

			literal_um[aux] = -voto_contra_um;

			cin >> voto_contra_dois;

			literal_dois[aux] = -voto_contra_dois;

			aux++;
		}

		// processa os votos lidos do arquivo de entrada
		processaVotos(num_propostas, num_seguidores*2, literal_um, literal_dois);
	}
}
