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
//https://olimpiada.ic.unicamp.br/pratique/p2/2018/f1/compensacao/

int n, m;
ll dev [1010];

int main(){

	cin >> m >> n;
	
	int circ = 0;
	for(int i=0, x, v, y; i<m; i++)
	{
		cin >> x >> v >> y;
		dev[x] -= v;
		dev[y] += v;
		circ += v;
	}

	ll din = 0;
	for(int i=1; i<=n; i++)
		if(dev[i] > 0) din += dev[i];
	

	cout <<( din < circ ? 'S' : 'N' )<< endl << din << endl;
	
	return 0;	
}
