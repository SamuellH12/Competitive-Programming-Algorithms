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

// https://cses.fi/problemset/task/1145


int main(){

	int n; cin >> n;

	int lista [n];
	for(int &x : lista) cin >> x;

	//LIS
	vi lis;

	for(int i=0; i<n; i++)
	{
		auto it = lower_bound(ALL(lis), lista[i]);

		if(it == lis.end()) lis.push_back(lista[i]);
		else *it = lista[i];
	}

	cout << lis.size() << endl;
	
	return 0;	
}
