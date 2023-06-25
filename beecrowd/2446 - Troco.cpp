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

//https://www.beecrowd.com.br/judge/pt/problems/view/2446

int k, n;
vi moeda;

bool memo[100005][1005];
bool dp[100005][1005];

bool solve(int i, int s)
{
	if(s == k) return true;
	if(i == n || s > k) return false;
	if(dp[s][i]) return memo[s][i];

	dp[s][i] = true;

	if(solve(i+1, s+moeda[i])) return memo[s][i] = true;
	if(solve(i+1, s)) 		   return memo[s][i] = true;
	
	return memo[s][i] = false;
}

int main(){

	cin >> k >> n;
	moeda.resize(n);

	for(auto &x : moeda) cin >> x;

	cout << (solve(0, 0) ? "S" : "N") << endl;
	
	return 0;	
}
