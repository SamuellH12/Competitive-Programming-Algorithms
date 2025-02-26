#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define iii array<int, 3>
#define pii pair<int, int>
#define upper(v, x) (upper_bound(begin(v), end(v), x) - begin(v)) 
using namespace std;
// https://www.spoj.com/problems/ADACABAA/

struct BIT2D {
	vector<int> ord;
	vector<vector<int>> bit, coord;

	BIT2D(){}

	BIT2D(vector<pii> pts){
		sort(begin(pts), end(pts));
		
		for(auto [x, y] : pts)
			if(ord.empty() || x != ord.back())
				ord.push_back(x);

		bit.resize(ord.size() + 1);
		coord.resize(ord.size() + 1);

		sort(begin(pts), end(pts), [&](pii &a, pii &b){
			return a.second < b.second;
		});

		for(auto [x, y] : pts)
			for(int i=upper(ord, x); i < bit.size(); i += i&-i)
				if(coord[i].empty() || coord[i].back() != y)
					coord[i].push_back(y);

		for(int i=0; i<bit.size(); i++) bit[i].assign(coord[i].size()+1, 0);
	}

	void update(int X, int Y, int v){
		for(int i = upper(ord, X); i<bit.size(); i += i&-i)
			for(int j = upper(coord[i], Y); j < bit[i].size(); j += j&-j)
				bit[i][j] += v;
	}

	int query(int X, int Y){
		int sum = 0;
		for(int i = upper(ord, X); i > 0; i -= i&-i)
			for(int j = upper(coord[i], Y); j > 0; j -= j&-j)
				sum += bit[i][j];
		return sum;
	}
};

vector<iii> sla;
BIT2D bit;

int solve(int l, int r){
	if(l == r) return 0;
	
	int ans = 0, m = (l+r)/2;
	ans += solve(l, m);
	ans += solve(m+1, r);
	
	int i, j, s=0;
	for(i=m+1, j=l; i<=r; i++)	
	{
		while(j <= m && sla[j][0] < sla[i][0]) bit.update(sla[j][1], abs(sla[j][2]), 1), j++;

		if(sla[i][2] > 0 && bit.query(sla[i][1], sla[i][2]) > 0 )
		{
			ans++;
			sla[i][2] = -sla[i][2];
		}
	}

	i = l;
	while(i<j) bit.update(sla[i][1], abs(sla[i][2]), -1), i++;
	
	sort(sla.begin()+l, sla.begin()+r+1);
	
	return ans;
}

int main(){
	optimize;
	int n; cin >> n;

	sla.resize(n);
	vector<pii> pts;

	for(int i=0, a, b, c, d; i<n; i++)
	{
		cin >> a >> b >> c >> d;
		sla[a-1] = iii({b, c, d});
		pts.emplace_back(c, d);
	}
	
	bit = BIT2D(pts);

	cout << n - solve(0, n-1) << "\n";

	return 0;	
}