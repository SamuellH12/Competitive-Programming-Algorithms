#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 100010
#define INF 100000010
#define debug cout<<"ate aqui ok\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2017/f3/arranhaceu/

ll n, bit[MAXN];

void update(int pos, int som){
	for(; pos <= n; pos += pos & (-pos))
		bit[pos] += som;
}

ll query(int pos){
	ll resp = 0;
	for(; pos > 0; pos -= pos & (-pos))
		resp+=bit[pos];
	return resp;
}


int main(){
	//optimize;
	memset(bit, 0, sizeof bit);
	int q;
	cin>>n>>q;
	int moradores[n+1];

	for(int i=1; i<=n; i++)
	{
		cin>>moradores[i];
		update(i, moradores[i]);
	}

	while(q--)
	{
		int e, k, p;
		cin>>e;

		if(e==0)
		{
			cin>>k>>p;
			update(k, p - moradores[k]);
			moradores[k] = p;
		} 
		else 
		{
			cin>>k;
			cout<<query(k)<<endl;
		}
	}

	return 0;	
}
