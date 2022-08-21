#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define MAXN 1010
#define debug cerr<<"ate aqui ok\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2019/f2/detetive/

vi grafo [MAXN];
bitset<MAXN> sources[MAXN];
vi vis(MAXN, 0);

void dfs(int folha, int u)
{
	sources[u][folha] = true;
	vis[u] = folha;

	for(auto v : grafo[u])
		if(vis[v] != folha)
			dfs(folha, v);
}


int main(){
	int e, I, V;
	cin >> e >> I >> V;
	vector<bool> folha(e+1, 1);

	//leitura
	for(int i=0, u, v; i<I; i++)
	{
		cin >> u >> v;
		grafo[u].push_back(v);
		folha[v] = 0; //marca os eventos "independentes"
	}

	//marca a lista de eventos "independentes" que cada vértice é fruto
	for(int i=1; i<=e; i++)	
		if(folha[i])
			dfs(i, i);
	

	set<int> verdadeiros;
	//lê os eventos verdadeiros e quais são tb verdeiros a partir disso
	while(V--)
	{
		int x; cin>>x;
		verdadeiros.insert(x);

		for(int i=1; i<=e; i++)
			if( (sources[x]&sources[i]).count() == sources[x].count() )	//se o nó i tiver todas as soucers de x então ele é true
				verdadeiros.insert(i);
	}


	for(auto x : verdadeiros)
		cout << x << " ";
	cout << endl;
	
	return 0;	
}

/*

Ok ok, como isso tudo funciona?

	Bem, primeiro pensa o seguinte: se meu evento é verdadeiro e ele tem apenas uma
"causa", a causa dele é verdadeira, certo? certo. Isso porque eu preciso que esse evento 
tenha ocorrido para que eu ocorra. Mas agora imagina outro exemplo, se ele possui mais 
de uma causa, qualquer uma delas pode ser verdadeira, então como vou saber qual delas é 
verdadeira? Pensa assim, eu tenho várias "causas independentes", que não dependem de 
outro evento, vou chamá-los de folhas, posso dizer com certeza de que pelo menos um deles 
aconteceu pro meu evento ter acontecido. Mas agora observa comigo:
	Se um evento tem todas as mesmas folhas que eu (mesmo que tenha outras tb) e se eu sou
verdadeiro por causa de uma das minhas folhas, então esse outro evento tb é verdadeiro, por
que o que quer que tenha desencadeado os eventos para eu ser verdadeiro também tornou esse 
outro nó verdadeiro junto, ele esteja acima de mim, ao lado ou em qualquer outro ponto.


Nova estrutura de dados aprendida: BITSET!
	Um bitset guarda vários true or false, 
como um array de bool, mas com uma grande 
diferença: ele é minúsculo!!! Cada true e 
false ocupa apenas um bit, 0 ou 1, então
ele se torna econômico em memória e, o mais
importante: se torna MUITO mais rápido para
comparar!!! Nesse caso posso analizar a
interseção entre os booleanos com & e a união
destes com |, o que facilita muito também!!!

*/