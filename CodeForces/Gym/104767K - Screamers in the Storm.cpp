#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define ll long long
using namespace std;
// https://codeforces.com/gym/104767/problem/K

#define int ll

const int MOD = 1e9 + 7;
const int MAXS = 50*50 + 1000;

int dp[55][MAXS];
int pd[55][MAXS];

int number_of_ways(int d, int r){
  if(d == 0) return 1;
  if(~pd[d][r]) return pd[d][r];

  int ans = 0;

  for(int i=0; i*i<=r; i++)
    ans = (ans + number_of_ways(d-1, r-i*i)) % MOD;

  for(int i=-1; i*i<=r; i--)
    ans = (ans + number_of_ways(d-1, r-i*i)) % MOD;

  return pd[d][r] = ans;
}

int sum_of_coord(int d, int r){
  if(d == 0) return 0;
  if(~dp[d][r]) return dp[d][r];

  int ans = 0;

  for(int i=0; i*i<=r; i++)
    ans = (sum_of_coord(d-1, r-i*i)  +  i*number_of_ways(d-1, r-i*i)  +ans)%MOD;

  for(int i=-1; i*i<=r; i--)
    ans = (sum_of_coord(d-1, r-i*i)  -  i*number_of_ways(d-1, r-i*i)  +ans)%MOD;

  return dp[d][r] = ans;
}


int32_t main(){
  memset(dp, -1, sizeof dp);
  memset(pd, -1, sizeof pd);

	int d, r;
	cin >> d >> r;
	
	cerr << number_of_ways(d, r*r) << endl;
	cout << sum_of_coord(d, r*r) << endl;

	return 0;	
}
