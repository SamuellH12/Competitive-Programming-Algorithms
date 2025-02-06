#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define ll long long
#define vi vector<int>
const int MAXN = 1000 + 5;
const int MOD = 1e9 + 7;
using namespace std;

vi grafo[MAXN];
vector<ll> pol[MAXN];
int n;

vector<ll> multiply(vector<ll> a, vector<ll> b){
	vector<ll> ans(a.size()-1 + b.size()-1 + 1, 0);

	for(int i=0; i<a.size(); i++)
		for(int j=0; j<b.size(); j++)
			ans[i+j] = (ans[i+j] + (a[i]*b[j])%MOD) % MOD;

	return ans;
}

void dfs(int u){
	pol[u] = {0,  1};

	for(auto v : grafo[u])
	{
		dfs(v);
		pol[u] = multiply(pol[u], pol[v]);
	}
	
	pol[u][0] = 1;
}


int main(){
	optimize;
	cin >> n;
	
	for(int i=1, p; i<n; i++)
	{
		cin >> p;
		grafo[p].emplace_back(i);
	}

	dfs(0);

	vi ans(n);

	for(int u=0; u<n; u++)
		for(int i=1; i<pol[u].size(); i++)
			ans[i-1] = (ans[i-1] + pol[u][i]) % MOD;
	
	for(int i=1; i<=n; i++)
		cout << ans[i-1] << endl;

	return 0;	
}
