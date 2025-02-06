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

// N. No Luck
// https://codeforces.com/gym/103388/problem/N

vi seg[4*MAXN];


int query(int no, int l, int r, int a, int b, int p){
	if(b <  l || r <  a) return 0;
	if(a <= l && r <= b) return (int) (  seg[no].end() - lower_bound(ALL(seg[no]), p)  );
	

	int m=(l+r)/2, e=no*2, d=no*2+1;

	return query(e, l, m, a, b, p) + query(d, m+1, r, a, b, p);
}


void build(int no, int l, int r, vi &lista){
	if(l == r){ seg[no].push_back(lista[l-1]);  return; }

	int m=(l+r)/2, e=no*2, d=no*2+1;

	build(e, l,   m, lista);
	build(d, m+1, r, lista);


	int N = seg[e].size(), M = seg[d].size();
	int i=0, j=0;

	while(i < N || j < M)
	{
		if(i == N)
			seg[no].push_back(seg[d][j++]);
		else
		if(j == M)
			seg[no].push_back(seg[e][i++]);
		else
		if( seg[e][i] < seg[d][j]  )
			seg[no].push_back(seg[e][i++]);
		else
			seg[no].push_back(seg[d][j++]);
	}

}


int main(){
	optimize;
	int y, n;
	cin >> y >> n;

	vi anos (y);

	for(auto &x : anos) cin >> x;

	build(1, 1, y, anos);

	for(int i=0, a, p, f; i<n; i++)
	{
		cin >> a >> p >> f;
	
		if(p <= anos[a-1] ) cout << 0 << endl;
		else cout << query(1, 1, y, a, a+f, p) << endl;
	}
	

	return 0;	
}
