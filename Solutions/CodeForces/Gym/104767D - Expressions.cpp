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

// https://codeforces.com/gym/104767/problem/D

#define int ll

int seg[4*MAXN];

void update(int no, int l, int r, int pos, int v){
	if(pos < l || r < pos) return;
	if(l == r){seg[no] = v; return; }

	int m=(l+r)/2, e=no*2, d=no*2+1;

	update(e, l,   m, pos, v);
	update(d, m+1, r, pos, v);

	seg[no] = min(seg[e], seg[d]);
}

int query(int no, int l, int r, int a, int b){
	if(b <  l || r <  a) return INF;
	if(a <= l && r <= b) return seg[no];

	int m=(l+r)/2, e=no*2, d=no*2+1;

	return min(query(e, l, m, a, b), query(d, m+1, r, a, b));
}

string ode[] = {"even", "odd"};

int32_t main(){
	optimize;
	int n, m;
	cin >> n >> m;

	vector<pii> sla;

	pii at(1, 1);
	int x; 
	char c;

	cin >> x;
	update(1, 1, n, 1, x%2);

	for(int i=0, j=2; i<(n-1)*2; i++)
	{
		if(i&1)
		{
			cin >> x;
			update(1, 1, n, j++, x%2);
		}
		else
		{
			cin >> c;
			if(c != '*')
			{
				at.second = j-1;
				sla.push_back(at);
				at.first = j;
			}
		}
	}
	

	at.second = n;
	sla.push_back(at);
	sort(ALL(sla));
	
	
	int sum = 0;
	for(auto [l, r] : sla) sum += query(1, 1, n, l, r);
	bool odd = (sum%2) != 0;


	cout << ode[odd] << endl;

	int y;
	while(m--)
	{
		cin >> x >> y;
		y %= 2;

		int L = -1, R = -1;
		int l=0, r=sla.size()-1, m; 
		while(l <= r)
		{
			m = (l+r) / 2;
			
			if(x < sla[m].first) r = m-1;
			else 
			if(x > sla[m].second) l = m+1;
			else{ 
				L = sla[m].first, 
				R = sla[m].second;
				break;
			}
		}

		//cerr << L << " " << R << endl;
		assert(L != -1);

		int old = query(1, 1, n, L, R);
		update(1, 1, n, x, y);
		int nw = query(1, 1, n, L, R);

		if(old != nw) odd = !odd;

		cout << ode[odd] << endl;
	}

	return 0;	
}
