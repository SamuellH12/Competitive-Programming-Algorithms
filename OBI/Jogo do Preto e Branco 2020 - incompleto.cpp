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

int matriz[7][7], l, c, p, resp = 0;
int possivelBeneficio, beneficioAnterior;
/*

0  0  2  0  0
2  1  1  0  2
0  0  0  2  1

*/

int verifica(int x, int y){
	if(x>l || y>c || !x || !y) return 0;
	return matriz[x][y];
}

void pintor(int x, int y){
	if(x>l || y>c || !x || !y)return;
	if(verifica(x, y)   != 0) return;
	if(verifica(x+1, y) == 2) return;
	if(verifica(x-1, y) == 2) return;
	if(verifica(x, y+1) == 2) return;
	if(verifica(x, y-1) == 2) return;

	matriz[x][y] = 2;
	resp++;
}

void solve(int x, int y){
	if(x>l || y>c || !x || !y) return;

	if (matriz[x][y] == 1 ){
		pintor(x+1, y);
		pintor(x-1, y);
		pintor(x, y+1);
		pintor(x, y-1);
	}

	if(y < c) solve(x, y+1);
	else 
	if(x < l) solve(x+1, 1);

}

int main(){
	
	cin>>l>>c;
	cin>>p;

	while(p--){
		int u, v; 
		cin>>u>>v;
		matriz[u][v] = 1;
	}

	solve(1, 1);

	cout<<resp<<endl;

	return 0;	
}

/*

8 de 10 pontos

Aparentemente a resposta consiste em
algo semelhante ao problema da mochila,
se deve testar os casos para "coloca" e
para "não coloca" para cada peça, 
entretanto, consegui resolver com essa
pontuação em muito pouco tempo, falhando
apenas em três casos individuais, dois 
do mesmo conjunto. Então, agora tô com
preguiça, e meio estressado com um trabalho
de biologia que surgio como uma reunião
quando eu tava tentando codar a solução 10/10,
por isso, ok, vou deixar pra um futuro eu
decidir se termina de resolver. Se quiser
ajuda, Samuell do futuro, você pode passar
para cada void solve chamado uma matriz[7][7],
é pequena, acho que deve rodar numa boa, e pode
fazer isso para os outros voids tb, no pintor
usando um &matriz[7][7], e o verifica cê pode
passar tb ou só fundir no pintor, ele é bem
simples, só precisaria digitar um pouco mais
nos ifs; obs: o pintor tem que ser um int 
ou bool no lugar de void, pra retornar 1 ou 0,
não mexendo na resp, igualmente o solve que tem 
que ser int pra retornar a pontuação conseguida


*/