#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;

//https://atcoder.jp/contests/dp/tasks/dp_d

int n, k;
vector<ll> ps, vl;
vector< vector<ll> > dp (101, vector<ll>(MAXN, -1));
ll mochila(int peso, int i)
{	
	if(peso > k) return -INF;
	if(i == n) return 0;
	if(dp[i][peso] != -1) return dp[i][peso];

	return dp[i][peso] = max( ( mochila(peso + ps[i], i+1) + vl[i] ) , mochila(peso, i+1) );	
}

int main(){
	cin>>n>>k;

	for(int i = 0, p, v; i < n; i++)
	{
		cin>>p>>v;
		ps.push_back(p);
		vl.push_back(v);
	}

	cout<<mochila(0, 0)<<endl;

	return 0;	
}
