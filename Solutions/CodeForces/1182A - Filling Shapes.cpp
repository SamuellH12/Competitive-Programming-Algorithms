#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;
//https://codeforces.com/problemset/problem/1182/A


int main(){

	int n; cin>>n;

	cout<<(n%2 == 0 ? 1 << (n/2) : 0 )<<endl;

	return 0;	
}

//https://vjudge.net/contest/478241#problem/L