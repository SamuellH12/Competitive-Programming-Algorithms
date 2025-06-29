#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int pre[MAXN], low[MAXN], clk=0;
vector<int> grafo [MAXN];

vector<pair<int, int>> pontes;
vector<int> cut;

#warning "lembrar do memset(pre, -1, sizeof pre);"
void tarjan(int u, int p = -1){
	pre[u] = low[u] = clk++;
	
	bool any = false;
	int chd = 0;

	for(auto v : grafo[u]){
		if(v == p) continue;

		if(pre[v] == -1)
		{
			tarjan(v, u);

			low[u] = min(low[v], low[u]);

			if(low[v] >  pre[u]) pontes.emplace_back(u, v); 	
			if(low[v] >= pre[u]) any = true;

			chd++;
		}
		else
			low[u] = min(low[u], pre[v]);
	}

	if(p == -1 && chd >= 2) cut.push_back(u);
	if(p != -1 && any)      cut.push_back(u);
}

/*LATEX_DESC_BEGIN***************************
Tarjan - Pontes e Pontos de Articulação
Algoritmo para encontrar pontes e pontos de articulação.

**Complexity:** O(V + E)
IMPORTANTE! Lembre do **memset(pre, -1, sizeof pre);**

*** Variáveis e explicações ***
pre[u] = "Altura", ou, x-ésimo elemento visitado na DFS. Usado para saber a posição de um vértice na árvore de DFS
low[u] = Low Link de U, ou a menor aresta de retorno (mais próxima da raiz) que U alcança entre seus filhos

chd = Children. Quantidade de componentes filhos de U. Usado para saber se a Raiz é Ponto de Articulação.
any = Marca se alguma aresta de retorno em qualquer dos componentes filhos de U não ultrapassa U. Se isso for verdade, U é Ponto de Articulação.

if(low[v] >  pre[u]) pontes.emplace_back(u, v); -> se a mais alta aresta de retorno de V (ou o menor low) estiver abaixo de U, então U-V é ponte
if(low[v] >= pre[u]) any = true;				-> se a mais alta aresta de retorno de V (ou o menor low) estiver abaixo de U ou igual a U, então U é Ponto de Articulação
*****************************LATEX_DESC_END*/