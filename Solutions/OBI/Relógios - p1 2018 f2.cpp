#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;

int sala[MAXN][MAXN], l, c, k;
bool mem[MAXN][MAXN];

struct Arestas{
	int custo, linha, coluna;

	Arestas(int C, int L, int Cl){
		custo = C;
		linha = L;
		coluna = Cl;
	}

	bool operator < (const Arestas &a) const
	{
		return custo > a.custo;
	}

};


int verificacao(int la, int ca, int lo, int co, int tempo)
{
	if(sala[lo][co] == -1) return 1;

	if( sala[la][ca] == -1 )
	{
		int espera = sala[lo][co] - (tempo % k);								//ATENÇÃO: < e <= FAZ |MUITA| DIFERENÇA!!! ( de 50 pra 100 pontos por isso :| )
		if(sala[lo][co] <= tempo%k) espera = (sala[lo][co] + k) - (tempo % k);	//outra obs.: o contrário de > é <= e o contrário de < é >= , sério, cuidado nos if's :]

		return espera;
	} 
	
	if( sala[lo][co] == (tempo+1)%k ) return 1;

	return INF;
}


ll chapeleiro(){
	//DIJKSTRA
	int dirl[4] = {-1, 0, 1, 0};
	int dirc[4] = {0, 1, 0, -1};
	
	priority_queue<Arestas> fila;

	fila.push(Arestas(0, 1, 1));

	while(!fila.empty())
	{
		int la, ca, custo; 							//linha atual coluna atual
		la = fila.top().linha;
		ca = fila.top().coluna;
		custo = fila.top().custo;
		fila.pop();

		if(mem[la][ca]) continue;
		mem[la][ca] = true;

		if(la == l && ca == c) return custo;

		for(int i=0; i<4; i++)
		{
			int co = ca+dirc[i], lo = la+dirl[i];	//linha objetivo coluna objetivo

			if(co == 0 || lo == 0 || co > c || lo > l) continue;

			int tempo = 0;
			tempo += verificacao(la, ca, lo, co, custo);

			if( tempo < INF )
				fila.push(Arestas(custo + tempo, lo, co));
		}
	}

	return INF;
}


int main(){
	//inicializar
	for(int i=0; i<110 ; i++){
		for(int e=0; e<110; e++){
			sala[i][e] = INF;
			mem[i][e] = false;
		}
	}

	cin>>l>>c>>k;

	for(int i=1; i<=l; i++)
		for(int e=1; e<=c; e++)
			cin>>sala[i][e];
	
	ll resp = chapeleiro();

	cout<<(resp >= INF ? -1 : resp)<< endl;

	return 0;	
}


/*
matriz utilizada como grafo. Guarda isso na memória para possíveis futuras questões
:] :3

importante: array com as direções {0, 0, -1, 1}
                                  {1, -1, 0, 0} mais outras se houver diagonais, isso é
bem prático na verdade, acho que posso adaptar para outras coisas
*/