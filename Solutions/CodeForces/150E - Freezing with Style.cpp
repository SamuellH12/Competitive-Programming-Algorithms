#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define pii pair<int,int>
#define iii tuple<int, int, int>
const int INF = 1e7;
const int MAXN = 1e5 + 5;
using namespace std;
// https://codeforces.com/contest/150/problem/E

template<typename T> struct SegTree {
	int n;
	vector<T> seg;
	T join(T&l, T&r){ return max(l, r); }

	void init(int _n){
		n = _n;
		if((int)seg.size() < 2*n) seg.resize(2*n);
		for(int i=0; i<n; i++) seg[i+n] = {-INF, -1};
		for(int i=n-1; i; i--) seg[i] = join(seg[i*2], seg[i*2+1]);
	}

	T query(int l, int r){ //[L, R] & [0, n-1]
		T ans = {-INF, -INF}; //NEUTRO	//if order matters, change to l_ans, r_ans
		for(l+=n, r+=n+1; l<r; l/=2, r/=2){
			if(l&1) ans = join(ans, seg[l++]);
			if(r&1) ans = join(seg[--r], ans);
		}
		return ans;
	}

	void update(int i, T v){
		for(seg[i+=n] = v; i/=2;) seg[i] = join(seg[i*2], seg[i*2+1]);
	}
};
SegTree<pii> seg;

int MID, LL, RR, UU=-1, VV=-1;
vector<pii> grafo[MAXN];

bool rem[MAXN];
int szt[MAXN];

vector<iii> db;
void getDist(int u, int p, int d=0, int bt=0){
	for(auto& [v, b] : grafo[u])
		if(v != p && !rem[v])
			getDist(v, u, d+1, bt + (b >= MID ? +1 : -1));
	db.emplace_back(iii{d, bt, u});
}

int getSz(int u, int p){
	szt[u] = 1;
	for(auto& [v, b] : grafo[u])
		if(v != p && !rem[v])
			szt[u] += getSz(v, u);
	return szt[u];
}

bool dfsc(int u=0, int p=-1, int f=-1, int sz=-1){
	if(sz < 0) sz = getSz(u, -1); //starting new tree
	if(sz < LL) return false;
	
	for(auto& [v, b] : grafo[u])
		if(v != p && !rem[v] && szt[v]*2 >= sz)
			return dfsc(v, u, f, sz);

	rem[u] = true;
	// getDist(u, -1, 0); //get subtree dists to centroid
	for(auto& [v, b] : grafo[u])
		if(!rem[v]){
			db.clear();
			getDist(v, u, 1, (b >= MID ? +1 : -1));

			for(auto& [d, bt, vv] : db)
			{
				if(LL <= d && d <= RR && bt >= 0){
					UU = u, VV=vv;
					return true;
				}

				if(d <= RR){
					auto [bt2, uu] = seg.query(max(0, LL-d), RR-d);
					if(bt2 + bt >= 0){
						UU = uu, VV=vv;
						return true;
					}
				}
			}
			
			for(auto& [d, bt, vv] : db)
				if(seg.seg[d+seg.n].first <= bt)
					seg.update(d, {bt, vv});
		}

	for(int i=1; i<sz; i++)
		seg.update(i, {-INF, -1});

	
	for(auto& [v, b] : grafo[u])
		if(!rem[v] && dfsc(v, u, u, -1))
				return true;
	return false;
}

int main(){
	optimize;
	int n;
	cin >> n >> LL >> RR;

	vector<int> sla(n);

	for(int i=1, u, v, b; i<n; i++)
	{
		cin >> u >> v >> b;
		u--, v--;
		grafo[u].emplace_back(v, b);
		grafo[v].emplace_back(u, b);
		sla[i] = b;
	}

	sort(ALL(sla));
	sla.resize(unique(ALL(sla)) - sla.begin());

	int l=0, r=sla.size()-1, mid;
	while(l <= r)
	{
		mid = (l+r)/2;
		MID = sla[mid];
		seg.init(n);
		memset(rem, 0, n+1);

		if(dfsc()) l = mid+1;
		else r = mid-1;
	}

	cout << UU+1 << " " << VV+1 << endl;

	return 0;	
}
