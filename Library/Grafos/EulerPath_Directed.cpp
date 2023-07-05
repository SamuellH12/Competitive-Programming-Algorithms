#include <bits/stdc++.h>
using namespace std;

//Código pra grafo Direcionado

const int MAXN = 1e6 + 5;

vector<int> grafo[MAXN];
vector<int> path;
int in[MAXN], out[MAXN], idx[MAXN];
int N, startVertex, noEdge;


void addEdge(int u, int v){
	grafo[u].push_back(v);	
	out[u]++;
	in[v]++;
}


bool isConnected(int s){

	vector<bool> vis (N, false);
	queue<int> fila;

	fila.push(s);
	vis[s] = true;
	int cnt = 1;

	while(!fila.empty())
	{
		int u = fila.front();
		fila.pop();

		for(auto v : grafo[u])
			if(!vis[v])
			{
				vis[v] = true;
				fila.push(v);
				cnt++;
			}
	}

	return cnt == N - noEdge;
}


bool hasEuler()
{
	int start = -1, end = -1;

	for(int i=0; i<N; i++)
	{
		if(!in[i] && !out[i]) noEdge++;
		if(in[i]  ==  out[i]) continue;

		if(in[i] - out[i] == -1 && start == -1) start = i;
		else
		if(in[i] - out[i] == 1  &&  end == -1 ) end = i;
		else 
			return false;
	}

	if(start == -1  && end != -1) return false;
	if(start != -1  && end == -1) return false;

	while(start == -1 && out[++start] == 0);
	startVertex = start;

	if(!isConnected(startVertex)) return false;

	return true;
}


void findPath(int u)
{
	while(idx[u] < grafo[u].size())
		findPath(grafo[u][idx[u]++]);
	
	path.push_back(u);
}





int main(){
	cout << "Hierholzer - Euler Path in a DIRECTED Graph" << endl;
	return 0;	
}


/**************************************
Algoritmo de Hierholzer para encontrar caminho
Euleriano (Euler Path) em um grafo direcionado

Complexity:
O(V + E)


* Informações

	addEdge(u, v) -> Adiciona uma aresta de U para V
	hasEuler() -> Retorna se existe um Euler Path
	isConnected() -> Retona se o grafo é conexo (chamado dentro do hasEuler())
	findPath(startVertex) -> dfs que encontra o caminho Euleriano a partir do {startVertex}

	vi path -> Lista de vértices do Euler Path na ordem REVERSA a que são visitados
	in[u] -> Quantidade de vértices que chegam em U
	out[u] -> Quantidade de vértices que saem de U
	idx[u] -> Para a DFS do findPath() saber qual o próximo vértice a ser visitado para cada U
	startVertex -> Vértice Inicial do Euler Path. Pega o elemento de início obrigatório se houver ou o primeiro com arestas de saída
	noEdge -> Quantidade de vértices que não possuem arestas. Essa quantidade é descontada na verificação de conectividade


IMPORTANTE! O algoritmo está 0-indexado
IMPORTANTE! Lembre de dar reverse(path.begin(), path.end()) após chamar o findPath()
IMPORTANTE! findPath() deve ser chamado a partir do startVertexv
**************************************/



/**************************************
Para saber se um grafo possui um Caminho Euleriano:

Undirected graph:
	- Cada vértice deve ter um número par de arestas (circuito); OU
	- Exatamente dois vértices devem ter um número ímpar de arestas (caminho);

Directed graph:
	- Cada vértice deve ter a mesma quantidade de arestas de entrada e de saída (circuito); OU
	- Exatamente um vértice deve ter uma aresta de entrada a mais e exatemente um vértice deve ter uma aresta de saída a mais (caminho);

 * Circuito -> Sai do vértice U e retorna ao mesmo vértice no final
 * Caminho -> Sai de um vértice U e chega em um vértice V no final
**************************************/
