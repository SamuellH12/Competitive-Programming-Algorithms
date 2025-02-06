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



int main(){
	optimize;
	int n, q, caso = 1;

	while(cin >> n >> q && (n+q))
	{
		cout << "CASE# "<< caso << ":" << endl;
		vi lista(n);

		for(auto &x : lista) cin >> x;

		sort(ALL(lista));

		int x;
		while(q--)
		{
			cin >> x;

			auto bb = lower_bound(ALL(lista), x);

			if(bb != lista.end() && *bb == x)
				cout << x << " found at " << bb - lista.begin() + 1 << endl;
			else 
				cout << x << " not found" << endl;
		}

		caso++;
	}
	
	
	return 0;	
}
