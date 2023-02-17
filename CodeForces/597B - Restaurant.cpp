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

bool func(pii a, pii b){
	if(a.second != b.second)
		return a.second < b.second;
	return a.first < b.first;
}

int main(){
	int n;
	cin >> n;

	vector<pii> hora;

	for(int i=0, l, r; i<n; i++)
	{
		cin >> l >> r;
		hora.push_back({l, r});
	}

	sort(ALL(hora), func);
	
	int resp=0, time=-1;

	for(auto h : hora)
		if(time < h.first)
			resp++, time = h.second;

	cout << resp << endl;
	
	return 0;	
}


// GULOSO -> pega sempre o que termina primeiro