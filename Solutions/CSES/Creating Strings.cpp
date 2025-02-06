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

// https://cses.fi/problemset/task/1622

int main(){
	string s; cin >> s;

	set<string> conj;

	while(conj.count( s ) == 0 ){ conj.insert(s); next_permutation(ALL(s));}
	

	cout << conj.size() << endl;
	for(auto x : conj)
	{
		cout << x << endl;
	}
	
	return 0;	
}
