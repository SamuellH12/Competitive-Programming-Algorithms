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

//https://www.spoj.com/problems/CSUMQ/

int main(){

	int n;
	cin >> n;

	vi ps(n+1);

	ps[0] = 0;

	for(int i=1, x; i<=n; i++)
	{
		cin >> x;
		ps[i] = ps[i-1] + x;
	}

	int q, a, b;
	cin >> q;

	while(q--)
	{
		cin >> a >> b;
		cout << ps[b+1] - ps[a] << endl;
	}
	
	return 0;	
}
