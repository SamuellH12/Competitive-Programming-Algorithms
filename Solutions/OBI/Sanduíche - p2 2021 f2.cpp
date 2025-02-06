#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 22
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;

int n, m;
bitset<21> namm [MAXN];

ll cozinha(int i, bitset<21> nam){
	ll ans = 1;

	for(int j=i+1; j <= n; j++)
	{
		if(!nam[j])
		{
			ans += cozinha(j, nam | namm[j]);
		}
	}

	return ans;
}

int main(){
	cin >> n >> m;
	
	for(int i=0, x, y; i<m; i++)
	{
		cin >> x >> y;
		namm[x][y] = 1;
		namm[y][x] = 1;
	}

	ll resp = 0;

	for(int i=1; i<=n; i++)
	{
		resp += cozinha(i, namm[i]);
	}

	cout << resp << endl;
	
	return 0;	
}
