#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 3e4 + 5;
using namespace std;

const int BLOCK_SZ = 700;

struct Query{
	int l, r, idx;

	Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
	
	bool operator < (Query q) const {
		if(l / BLOCK_SZ != q.l / BLOCK_SZ) return l < q.l;
		return (l / BLOCK_SZ &1) ? ( r < q.r ) : (r > q.r );
	}
};

int temp[MAXN];
int occ[MAXN];
map<int, int> mp;

void add(int idx){ 
	occ[++mp[temp[idx]]]++; 
}

void remove(int idx){
	occ[mp[temp[idx]]--]--;
}

int getAnswer(){ 
	int l=1, r=MAXN-10, m, ans=-1;

	while(l <= r)
	{
		m = (l+r)/2;

		if(occ[m] >= m)
		{
			ans = m;
			l = m+1;
		}
		else r = m-1;
	}

	return ans; 
}


vector<int> MO(vector<Query> &queries){
	vector<int> ans(queries.size());

	sort(queries.begin(), queries.end());

	int L = 0, R = 0;
	add(0);

	for(auto [l, r, idx] : queries)
	{
		while(l < L) add(--L);
		while(r > R) add(++R);
		while(l > L) remove(L++);
		while(r < R) remove(R--);
		
		ans[idx] = getAnswer();
	}

	return ans;
}


int main(){
	optimize;
	int n, q; cin >> n >> q;

	for(int i=0; i<n; i++) cin >> temp[i];

	vector<Query> que;

	for(int i=0, l, r; i<q; i++)
	{
		cin >> l >> r;
		que.emplace_back(--l, --r, i);
	}

	auto ans = MO(que);

	for(auto x : ans) cout << x << endl;
	
	return 0;	
}
