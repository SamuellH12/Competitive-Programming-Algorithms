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

int dir[31], esq[31];

int main(){

	int n; cin >> n;

	string p;
	for(int i=0, l; i < n; i++)
	{
		cin >> l >> p;

		if(p == "D")
			dir[l-30]++;
		else
			esq[l-30]++;
	}

	int resp = 0;
	for(int i=0; i<31; i++)
		resp += min(dir[i], esq[i]);
	
	cout << resp << endl;
	
	
	return 0;	
}
