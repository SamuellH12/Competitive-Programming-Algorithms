#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vl vector<long long>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;

//https://olimpiada.ic.unicamp.br/pratique/p2/2019/f1/soma/
//busca binária na soma de prefixos

int main(){
	optimize;
	
	int n, k;
	cin>>n>>k;
	
	ll resp=0;
	vl seq, prefix;
	
	// 1 indexado
	seq.push_back(0);   //[0]
	prefix.push_back(0);//[0]

	for(int i=1, x; i<=n; i++)
	{
		cin>>x;
		seq.push_back(x);
		prefix.push_back(x + prefix[i-1]);
	}
		
	for(int i=1; i<=n; i++)
			resp += upper_bound(prefix.begin() + i, prefix.end(), prefix[i-1] + k) 
			      - lower_bound(prefix.begin() + i, prefix.end(), prefix[i-1] + k);

	cout << resp << endl;

	return 0;	
}


/*

Cheguei numa solução com -> prefix sum <- com dois for, i=0 a n e e=i a n
Essa solução dá 50 de 100 pontos na questão, mas no restante dá TLE

Uma outra solução que eu encontrei, que é essa aqui ^, usando uma busca binária 
em conjunto com a prefix sum é, na verdade, beeeeeeem melhor, mas pra ela
é interessante entender o funcionamente do upper e lower_bound

upper_bound -> faz uma busca binária no vetor, recebe três argumentos:
	início do vetor, fim do vetor e valor buscado. Ele retorna a última 
	posição em que o valor foi encontrado + 1;

lower_bound -> Semelhante ao upper_bound, sua principal diferença é que ele
	retorna a primeira posição em que o valor foi encontrado no array;

Se o valor não existir no vetor, ambos retornam a posição do elemento seguinte, 
ou seja, o primeiro elemento maior que o procurado. Dessa forma é simples
perceber que o valor não existe, pois quando este for o caso tanto o upper 
quanto o lower retornarão o mesmo valor

*/