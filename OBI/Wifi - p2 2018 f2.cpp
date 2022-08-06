#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug //cerr<<"ate aqui ok\n"
using namespace std;

//Novo conceito: Sweep Line
//https://olimpiada.ic.unicamp.br/pratique/p2/2018/f2/wifi/

struct evento{
	int x, t, yt, yd;

	evento(int x, bool t, int yt, int yd) : x(x), t(t), yt(yt), yd(yd) {}

	bool operator < (const evento &a) const{ 
		if( x == a.x ) return t < a.t;
		return x < a.x; 
	}
};

bool st = false, ed = true;

int main(){
	int n;
	cin >> n;
	vector<evento> eventos;

	for(int i=0; i<n; i++)
	{
		int xi, yt, xf, yd;	//x_inicial, y_top, x_final, y_down
		cin >> xi >> yt >> xf >> yd;
		eventos.push_back(evento(xi, st, yt, yd));	//start do quadrado
		eventos.push_back(evento(xf, ed, yt, yd));	//end do quadrado
	}

	sort(ALL(eventos));	//ordena os eventos pelo eixo x

	int resp = 0;
	map<int, int> verticalMap;  //marca na linha atual onde um quadrado começa e onde ele termina
	//importante usar o map pq ele mantem os dados ordenados, então se eu quiser saber por exemplo 
	//qual o limite de um quadrado acima de mim?  Eu posso só olhar a posição anterior do map para
	//isso, e também para saber se é o limite top ou down de um quadrado e assim se estou dentro ou fora dele;

	for(auto e : eventos)
	{

		if( e.t == st)	//se for o início de um quadrado (start);
		{
			verticalMap[e.yt] = 0; //parte de cima do square marcado com 0
			verticalMap[e.yd] = 1; //parte de baixo de um square marcado com 1
		}
		else	//se for o fim de um quadrado (end);
		{
			//#marca o square acima de mim (pq tô dentro dele) com 1, pra dizer que está ocupado por outro quadrado.
			map<int, int>::iterator it = verticalMap.find( e.yt ); //pego um ponteiro para o top do meu square atual
			it++; 			//vou para o y de cima
			it->second = 2; //marco a pos do square anterior com 1. Se for um down não faz diferença, mas se for o
							//top de um quadrado então ele vai ficar marcado como tendo um quadrado dentro dele.
							//se for o top de um quadrado já marcado tb não vai fazer diferença, ele continua marcado (como o quadrado principal que guarda todos os outros dentro)

			//verifico se meu quadrado atual já foi marcado antes (ou seja, se ele tem um square dentro dele)
			if(verticalMap[e.yt] == 0) resp++; //se não tem nenhum dentro, então incrementa a resposta, pq vou precisar de um roteador dentro dele

			//apaga nosso square do mapa vertical, pq ele acabou de acabar
			verticalMap.erase( e.yt );
			verticalMap.erase( e.yd );
		}

	}

	cout << resp << endl;
	
	return 0;	
}
