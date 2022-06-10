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
//https://olimpiada.ic.unicamp.br/pratique/p2/2018/f1/piso/

int main(){
	int l, c, t1=0, t2=0;
	cin>>l>>c;

	if( c%2 ) swap(l, c);

	t1 = (l*c) + (l-1)*(c-1);
	t2 = 2*(l-1) + 2*(c-1);

	cout << t1 << endl << t2 << endl;
	
	return 0;	
}

/*
Dava pra passar com for de boas tb, limite < 100 é baixo,
mas nesse caso preferi fazer a fórmula mesmo! :D
*/