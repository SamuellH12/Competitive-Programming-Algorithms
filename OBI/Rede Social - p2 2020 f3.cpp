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
//https://olimpiada.ic.unicamp.br/pratique/p2/2020/f3/rede/


int main(){
	int n; cin >> n;

	vi msg (n);
	for(int i=0, x; i<n; i++)
	{
		cin >> x;
		msg[i] = x;
	}

	sort(ALL(msg));


	int l=1, r=msg.size(), mid, resp = 0, siz = msg.size();
	while(l <= r)
	{
		mid=(l+r)/2;

		if( msg[siz - mid] >= mid )
		{
			resp = max(resp, mid);
			l = mid+1;
		}
		else r = mid-1;
	}
	
	cout << resp << endl;

	return 0;	
}
