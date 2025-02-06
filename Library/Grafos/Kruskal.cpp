#include <bits/stdc++.h>
using namespace std;

/*Create a DSU*/ 
void join(int u, int v); int find(int u);

const int MAXN = 1e6 + 5;
struct Aresta{ int u, v, c; };
bool compAresta(Aresta a, Aresta b){ return a.c < b.c; }

vector<Aresta> arestas; 			//Lista de Arestas

int kruskal(){
	sort(begin(arestas), end(arestas), compAresta);	//Ordena pelo custo
	int resp = 0;					//Custo total da MST

	for(auto a : arestas)
		if( find(a.u) != find(a.v) )
		{
			resp += a.c;
			join(a.u, a.v);
		}
	return resp;
}
/*************************************************************
	Kruskal - Minimum Spanning Tree
Algoritmo para encontrar a Arvore Geradora Minima (MST)
-> Complexity: O(E log E) 
E : Numero de Arestas
***************************************************************/