#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 1010
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;
#define MOD 1000000007
//https://codeforces.com/problemset/problem/431/C

int n, k, d;
int dp[MAXN][MAXN][2];


ll tree(int edg, bool psD, int soma)
{
	if(edg >= d) psD = true;

	if(dp[edg][soma][psD] != -1) return dp[edg][soma][psD];

	bool folha = soma == n;

	if(folha && !psD) return 0;
	if(folha &&  psD) return 1;

	ll resp = 0;

	for(int i=1; i<=k; i++)
	{
		if( soma + i <= n )
			resp += tree(i, psD, soma + i) % MOD;
		else break;
	}

	return dp[edg][soma][psD] = resp % MOD;
}

int main(){
	for(int i=0; i<MAXN; i++)
		for(int e=0; e<MAXN; e++){
			dp[i][e][0] = -1;
			dp[i][e][1] = -1;
		}

	cin>>n>>k>>d;

	ll resp = tree(0, 0, 0)%MOD;

	cout<<resp<<endl;

	return 0;	
}
