#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;
 
#define int long long

//https://codeforces.com/contest/1776/problem/L
 
int mdc(int A, int B){
    return (B == 0 ?  A  : mdc(B, A%B) ); 
}
 
int mmc(int A, int B){
    return (A * B) / mdc(A, B);
}
 
int32_t main(){
 
	int n; cin >> n;
	string s; cin >> s;
 
	int m=0, p=0;
	for(auto c : s) if(c == '+') p++; else m++;
	if(p < m) swap(p, m); // p > m
 
	int t; cin >> t;
 
	while(t--){
 
		int a, b; cin >> a >> b;
 
		if(a == b){
			cout << (p == m ? "YES" : "NO") << endl;
			continue;
		}
 
		if(a > b) swap(a, b); //a < b
 
		int mt = mmc(b, a);
		int k = mt/a, l = mt/b;
 
		int x =  p / k;

		while(x > 0 && !(p - (k*x) == m - (l*x) &&  p - (k*x) >= 0) ) x--;
 
		if( p - (k*x) == m - (l*x) &&  p - (k*x) >= 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
 
	
	
	return 0;	
}