#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define iii array<ll, 3>

struct BIT {
	vector<ll> bit;
	int N;

	BIT(){}
	BIT(int n) : N(n+1) {
		bit.assign(N, 0);
	}

	void update(int pos, ll val){
		for(; pos < N; pos += pos&(-pos))
			bit[pos] += val;
	}

	ll query(int pos){
		ll sum = 0;
		for(; pos > 0; pos -= pos&(-pos))
			sum += bit[pos];
		return sum;
	}
};

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> estacao(n);
	for(int i=0, x; i<m && cin >> x; i++) estacao[x-1].push_back(i+1);

	vector<ll> need(n);
	for(auto &x : need) cin >> x;

	int k; cin >> k;

	vector<iii> chuva(k);
	for(auto &[l, r, a] : chuva) cin >> l >> r >> a;
	
	vector<int> L(n, 0), R(n, k-1), ans(n, -1);
	vector<vector<int>> Mid(k);
	
	BIT bit;
	auto reset = [&](){ bit = BIT(m); };
	auto update = [&](int j){
		auto [l, r, a] = chuva[j];
		bit.update(l,    a);
		bit.update(r+1, -a);
		if(l > r) bit.update(1, a);
	};
	auto getVal = [&](int i){
		ll sum = 0;
		for(auto x : estacao[i]){
			if(sum >= need[i]) break;
			sum += bit.query(x);
		}
		return sum;
	};

	bool LACK; do {
		reset();
		for(int i=LACK=0; i<n; i++)
			if(L[i] <= R[i])
				Mid[(L[i]+R[i])/2].push_back(i),
				LACK = true;
		
		for(int mid=0; mid<k && LACK; mid++){
			update(mid);
			for(auto i : Mid[mid]){
				if(getVal(i) >= need[i]) ans[i] = mid, R[i] = mid-1;
				else L[i] = mid+1;
			}
			Mid[mid].clear();
		}
	} while(LACK);

	for(auto &x : ans) 
		if(~x) cout << x+1 << "\n";
		else cout << "NIE\n";
}
