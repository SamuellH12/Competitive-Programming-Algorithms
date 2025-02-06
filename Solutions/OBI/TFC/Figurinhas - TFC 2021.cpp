#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

//Grafos, BFS e Bitset
//Material de grafos, bfs e dfs: https://youtu.be/z3hsECuv3mM 
//Bitset tem uma explicação breve abaixo

int n, s;
bitset<25> banca [100010];
int memo [100010];
bool dp  [100010];
vi grafo [100010];


int main(){
	cin >> n >> s;

	for(int i=1, k, f; i<=n; i++)
	{
		cin >> k;
		while(k--)
		{
			cin >> f;
			banca[i][f] = 1;
		}
	}

	for(int i=1, u, v; i<n; i++)
	{
		cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}


	//====BFS=====
	queue<int> fila;
	queue<bitset<25>> filaF;

	fila.push(s);
	filaF.push(banca[s]);

	while(!fila.empty())
	{
		int u = fila.front(); 	fila.pop();
		auto f = filaF.front();	filaF.pop();

		f = f | banca[u];			//junta as figurinhas atuais a lista
		memo[u] = f.count();		//salva a qtd na memo
		dp[u] = true;				//marca como true a dp

		for(auto v : grafo[u]){		//visita todos os vizinhos
			if(!dp[v]){				//se o vizinho atual nunca foi visitado, coloca na fila
				fila.push(v);
				filaF.push(f);
			}		
		}
	}

	//====BFS-END====


	int q, d;
	cin >> q;

	while(q--)
	{
		cin >> d;
		cout << memo[d] << endl; 
		//pra cada consulta imprime o valor que encontramos na BFS e ficou salvo na memoria
	}

	
	return 0;	
}


/*
++==========++
||  BITSET  ||
++==========++

Imagine um array de bits: isso é um bitset!

	Ele pode armazenar informações de verdadeiro ou falso de maneira eficiente e
nos fornece algumas funcionalidades interessantes, como o count, que nós diz 
quantos bits estão ligados, ou quantos 1.

	Cada posição do bitset pode armazenar 1 ou 0, ou seja, um bit. Podemos acessar
o bit na posição n através de colchetes, como se acessa um array, assim bits[i] = 1; 
diz que o bit da posição i deve estar ligado. Usamos isso pra marcar qual banca vende
qual figurinha.

	Uma outra coisa interessante que podemos fazer é juntar dois bitsets de maneira
eficiente, através do operador | que é como um 'or'. Veja um exemplo:

	100101 | 010110 = 110111

	100101
	010110 
	------
	110111

	Usamos isso pra juntar as figurinhas de duas bancas, e assim saber quais figurinha
as bancas em um caminho vendem sem precisar verificar se há figurinhas repetidas. Após
juntar todas as bancas do caminho vemos quantas figurinhas diferentes conseguimoa com o
count();


	OBS: Nesse problema acredito que a estutura de dados "set" também poderia ser utilizada,
porém o bitset é mais rápido e, acho eu, prático, até pq só queremos saber se há, sim
ou não, 1 ou 0, aquela figurinha na rota.

*/