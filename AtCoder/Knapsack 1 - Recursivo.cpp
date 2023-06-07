#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;

ll n, W;
vector<pair<ll, ll>>  itens;

ll memo[105][100005];

ll solve(ll i, ll capacidade)
{
	if(capacidade < 0) return -999999999999;
	if(i == n) return 0;
	if(memo[i][capacidade] != -1) return memo[i][capacidade];

	// pega o item
	ll resp = solve(i+1, capacidade);

	//pega o item
	ll ans = solve(i+1, capacidade - itens[i].first) + itens[i].second;

	return memo[i][capacidade] = max(resp, ans);
}

int main(){
	memset(memo, -1, sizeof memo);
	cin >> n >> W;

	itens.resize(n);

	for(int i=0; i<n; i++){
		cin >> itens[i].first >> itens[i].second;
	}

	ll resp = solve(0, W);
	
	cout << resp << endl;

	return 0;	
}
