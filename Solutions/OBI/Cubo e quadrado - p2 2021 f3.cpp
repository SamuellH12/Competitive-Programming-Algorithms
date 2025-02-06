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
//https://olimpiada.ic.unicamp.br/pratique/p2/2021/f3/cubo/


int main(){
	int a, b, resp = 0;
	cin >> a >> b;

	set<int> quadrado;

	for(int i=sqrt(a); i <= sqrt(b); i++) quadrado.insert(i*i);
	
	for(int i=cbrt(a)-1; i <= cbrt(b); i++) if(quadrado.count(i*i*i) && i*i*i >= a) resp++;
	
	cout << resp << endl;

	return 0;	
}
