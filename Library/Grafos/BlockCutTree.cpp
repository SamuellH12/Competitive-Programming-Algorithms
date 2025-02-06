#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

const int MAXN = 1e6 + 5;
const int MAXM = 1e6 + 5;//Cuidado

vector<pii> grafo [MAXN];
int pre[MAXN], low[MAXN], clk=0, C=0;

vector<pii> edge;
bool visEdge[MAXM];
int edgeComponent[MAXM];
int vertexComponent[MAXN];

int cut[MAXN];
stack<int> s;

vector<int> tree [2*MAXN];
int componentSize[2*MAXN]; //vertex - cutPoints

void reset(int n){
	for(int i=0; i<=edge.size(); i++)
		visEdge[i] = edgeComponent[i] = 0;

	edge.clear();
	
	for(int i=0; i<=n; i++){
		pre[i] = low[i] = -1;
		cut[i] = false;
		vertexComponent[i] = 0;
		grafo[i].clear();
	}

	for(int i=0; i<=C; i++){
		componentSize[i] = 0;
		tree[i].clear();
	}

	while(!s.empty()) s.pop();

	clk = C = 0;
}

void newComponent(int i){
	C++;
	int j;

	do {
		j = s.top(); s.pop();		
		edgeComponent[j] = C;

		auto [u, v]	 = edge[j];
		if(!cut[u] && !vertexComponent[u]) componentSize[C]++, vertexComponent[u] = C;
		if(!cut[v] && !vertexComponent[v]) componentSize[C]++, vertexComponent[v] = C;
		
	} while(!s.empty() && j != i);
}

void tarjan(int u, bool root = true){
	pre[u] = low[u] = clk++;
	
	bool any = false;
	int chd = 0;

	for(auto [v, i] : grafo[u]){
		if(visEdge[i]) continue;
		visEdge[i] = true;

		s.emplace(i);

		if(pre[v] == -1)
		{
			tarjan(v, false);

			low[u] = min(low[v], low[u]);
			chd++;

			if(!root && low[v] >= pre[u]) cut[u] = true, newComponent(i);
			if( root && chd >= 2) 		  cut[u] = true, newComponent(i);
		}
		else
			low[u] = min(low[u], pre[v]);
	}

	if(root) newComponent(-1);
}

//ATENCAO: ESTA 1-INDEXADO
void buildBCC(int n){
	vector<bool> marc(C+1, false);

	for(int u=1; u<=n; u++)
	{
		if(!cut[u]) continue;

		C++;
		cut[u] = C;

		for(auto [v, i] : grafo[u])
		{
			int ec = edgeComponent[i];
			if(!marc[ec])
			{
				marc[ec] = true;
				tree[cut[u]].emplace_back(ec);
				tree[ec].emplace_back(cut[u]);
			}
		}

		for(auto [v, i] : grafo[u]) 
			marc[edgeComponent[i]] = false;
	}
}

void addEdge(int u, int v){
	int i = edge.size();
	grafo[u].emplace_back(v, i);
	grafo[v].emplace_back(u, i);
	edge.emplace_back(u, v);
}

/***********************
Block Cut Tree - BiConnected Component

reset(n);
addEdge(u, v);
tarjan(Root);
buildBCC(n);

No fim o grafo da Block Cut Tree estara em _vector<int> tree []_
***********************/