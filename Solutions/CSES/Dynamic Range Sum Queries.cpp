#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<ll>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;

//https://cses.fi/problemset/task/1648

ll bit[MAXN];

void update(int pos, ll val){
	for(; pos < MAXN; pos += pos&(-pos))
		bit[pos] += val;
}

ll query(int pos){
	ll sum = 0;
	for(; pos > 0; pos -= pos&(-pos))
		sum += bit[pos];
	return sum;
}

int main(){

	int n, q;
	cin >> n >> q;

	vi num(n+1);

	for(int i=1; i<=n; i++)
	{
		cin >> num[i];
		update(i, num[i]);
	}

	ll t, a, b;
	
	while(q--)
	{
		cin >> t >> a >> b;

		if(t == 1)
		{
			update(a, b-num[a]);
			num[a] = b;
		}
		else
		{
			cout << query(b) - query(a-1) << endl;
		}
	}
	
	return 0;	
}
