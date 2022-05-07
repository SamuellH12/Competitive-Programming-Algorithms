#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<long long>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;
//https://codeforces.com/gym/102861/problem/H

ll n, k, a, b;
vi boxes;
ll pascal[MAXN][MAXN];
ll dp[MAXN][MAXN];

ll comb(ll c, ll k)
{
	if(k > c) return 0;
	if(k == 0) return 1;
	if(pascal[c][k] != -1) return pascal[c][k];
	return pascal[c][k] = comb(c-1, k-1) + comb(c-1, k);
}

ll solve(ll p, ll i, ll q)
{
	if(q <= 0) return !q;
	if(i == n) return 0;
	if(dp[i][q] != -1) return dp[i][q];
	
	ll resp = 0;

	if(boxes[i] <= p  )
	{
		resp += solve(p - boxes[i], i+1, q-1);
		ll c = boxes.size() - i;
		resp += comb(c - 1, q);
	}
	else
	{
		resp += solve(p, i+1, q);
	}

	return dp[i][q] = resp;
}


int main(){

	cin>>n>>k;

	memset(dp, -1, sizeof(dp));
	memset(pascal, -1, sizeof(pascal));

	for(ll i=0; i<n; i++)
	{
		ll x;
		cin>>x;
		boxes.push_back(x);
	}

	cin>>a>>b;

	sort(ALL(boxes));
	reverse(ALL(boxes));

	ll resp = solve(b, 0, k);

	memset(dp, -1, sizeof(dp));

	cout<< resp - solve(a - 1, 0, k)<<endl;

	return 0;	
}
