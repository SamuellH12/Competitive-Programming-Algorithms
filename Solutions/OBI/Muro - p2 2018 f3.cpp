#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 10010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2018/f3/muro/

ll n;
ll memo [MAXN];

ll solve(ll i)
{
	if(i == n) return 1;
	if(i > n) return 0;
	if(memo[i]) return memo[i];

	ll resp = 0;

	//1 de comp -> dois bloquinhos # empilhados -> possib 1
	resp += solve(i+1) % MOD;

	//2 de comp -> um bloquinho L e um # juntos	-> possib 4
	if(i+2 <= n)
	resp += (4 * solve(i+2)) % MOD;

	//3 de comp -> dois bloquinhos L juntos 	-> possib 2
	if(i+3 <= n)
	resp += (2 * solve(i+3)) % MOD;

	return memo[i] = resp % MOD;
}

int main(){
	cin >> n;
	
	cout << solve(0) << endl;

	return 0;	
}
