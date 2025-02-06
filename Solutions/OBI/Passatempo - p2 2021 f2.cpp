#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2021/f2/passatempo/

string matriz[MAXN][MAXN];
int somal[MAXN], somac[MAXN];
map<string, int> mapa;
set<string> conjunto;

int main(){
	optimize;
	int l, c;
	cin >> l >> c;
	
	//leitura
	for(int i=0; i<l; i++)
	{
		for(int e=0; e<c; e++){
			cin >> matriz[i][e];
			conjunto.insert(matriz[i][e]);
		}

		cin >> somal[i];
	}

	for(int i=0; i < c; i++)
		cin >> somac[i];

	int tam = conjunto.size();
	//processamento
	while(mapa.size() < tam)
	{
		//confere se tem linhas iguais
		for(int i=0; i<l; i++)
		{
			string aux = "";
			int qtd = 0, soma = 0;
			bool ok = false;

			for(int e=0; e<c; e++)
			{
				if( mapa.find(matriz[i][e]) == mapa.end() )
				{
					if(qtd == 0){ ok = true; aux = matriz[i][e]; qtd++;}
					else if( matriz[i][e] == aux ){ qtd++; }
					else { ok = false; break; }
				}
				else
				{
					soma += mapa[matriz[i][e]];
				}
			}

			if(ok)
			{
				mapa[aux] = (somal[i] - soma)/qtd;
			}
		}

		//confere colunas iguais
		for(int i=0; i<c; i++)
		{
			string aux = "";
			int qtd = 0, soma = 0;
			bool ok = false;

			for(int e=0; e<l; e++)
			{
				if( mapa.find(matriz[e][i]) == mapa.end() )
				{
					if(qtd == 0){ ok = true; aux = matriz[e][i]; qtd++;}
					else if( matriz[e][i] == aux ){ qtd++; }
					else { ok = false; break; }
				}
				else
				{
					soma += mapa[matriz[e][i]];
				}
			}

			if(ok)
			{
				mapa[aux] = (somac[i] - soma)/qtd;
			}
		}

	}

	
	//saída
	for(auto x : mapa)
		cout << x.first << " " << x.second << endl;
	
	return 0;	
}
