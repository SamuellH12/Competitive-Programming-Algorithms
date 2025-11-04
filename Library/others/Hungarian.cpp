#include <bits/stdc++.h>
using namespace std;

typedef int TP;

const int MAXN = 1e3 + 5;
const TP INF = 0x3f3f3f3f;

TP matrix[MAXN][MAXN];
TP row[MAXN], col[MAXN];
int match[MAXN], way[MAXN];

TP hungarian(int n, int m){
	memset(row, 0, sizeof row);
	memset(col, 0, sizeof col);
	memset(match, 0, sizeof match);

	for(int i=1; i<=n; i++){
		match[0] = i;
		int j0 = 0, j1, i0;
		TP delta;

		vector<TP> minv (m+1, INF);
		vector<bool> used (m+1, false);

		do {
			used[j0] = true;
			i0 = match[j0];
			j1 = -1;
			delta = INF;

			for(int j=1; j<=m; j++)
				if(!used[j]){
					TP cur = matrix[i0][j] - row[i0] - col[j];

					if( cur < minv[j] ) minv[j] = cur, way[j] = j0;
					if(minv[j] < delta) delta = minv[j], j1 = j;
				}

			for(int j=0; j<=m; j++)
				if(used[j]){
					row[match[j]] += delta,
					col[j] -= delta;
				} 
				else minv[j] -= delta;

			j0 = j1;
		} while(match[j0]);

		do {
			j1 = way[j0];
			match[j0] = match[j1];
			j0 = j1;
		} while(j0);
	}

	return -col[0];
}

vector<pair<int, int>> getAssignment(int m){
	vector<pair<int, int>> ans;
	for(int i=1; i<=m; i++)
		ans.push_back(make_pair(match[i], i));
	return ans;
}

/*LATEX_DESC_BEGIN***************************
**Hungarian Algorithm** - Assignment Problem
Algoritmo para o problema de atribuição mínima.

**Complexity:** O(N^2 * M)

hungarian(int n, int m);  ->  Retorna o valor do custo mínimo
getAssignment(int m)      ->  Retorna a lista de pares <linha, Coluna> do Minimum Assignment

n -> Número de Linhas // m -> Número de Colunas

IMPORTANTE! O algoritmo é 1-indexado
IMPORTANTE! O tipo padrão está como int, para mudar para outro tipo altere | typedef <TIPO> TP; |
Extra: Para o problema da atribuição máxima, apenas multiplique os elementos da matriz por -1
*****************************LATEX_DESC_END*/