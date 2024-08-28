#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

const int MAXN = 1e6 + 5;

vi grafo[MAXN];
vi greve[MAXN];
vi dag[MAXN];
vi comp, order;
vector<bool> vis; 
int C;

void dfs(int u){
	vis[u] = true;
	for(auto v : grafo[u])
		if(!vis[v])
			dfs(v);
	order.push_back(u);
}

void dfs2(int u){
	comp[u] = C;
	for(auto v : greve[u])
		if(comp[v] == -1)
			dfs2(v);
}

void kosaraju(int n){
	order.clear();
	comp.assign(n, -1);
	vis.assign(n, false);

	for(int v=0; v<n; v++)
		if(!vis[v])
			dfs(v);

	C = 0;
	reverse(begin(order), end(order));

	for(auto v : order)
		if(comp[v] == -1)
			dfs2(v), C++;

	//// Montar DAG  ////
	vector<bool> marc(C, false);

	for(int u=0; u<n; u++){
		for(auto v : grafo[u])
		{
			if(comp[v] == comp[u] || marc[comp[v]]) continue;

			marc[comp[v]] = true;			
			dag[comp[u]].emplace_back(comp[v]);
		}

		for(auto v : grafo[u]) marc[comp[v]] = false;
	}
}
/**************************************
Kosaraju - Strongly Connected Component
Algoritmo de Kosaraju para encontrar Componentes Fortemente Conexas

Complexity: O(V + E)
IMPORTANTE! O algoritmo está 0-indexado

*** Variáveis e explicações ***
int C   -> C é a quantidade de Componetes Conexas. As componetes estão numeradas de 0 a C-1
dag     -> Após rodar o Kosaraju, o grafo das componentes conexas será criado aqui
comp[u] -> Diz a qual componente conexa U faz parte
order   -> Ordem de saída dos vértices. Necessário para o Kosaraju
grafo   -> grafo direcionado
greve	-> grafo reverso (que deve ser construido junto ao grafo normal) !!!

NOTA: A ordem que o Kosaraju descobre as componentes é uma Ordenação Topológica do SCC
em que o dag[0] não possui grau de entrada e o dag[C-1] não possui grau de saida
**************************************/