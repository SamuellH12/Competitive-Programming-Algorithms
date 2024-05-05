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
// https://codeforces.com/gym/104767/problem/F

vi ordem = vi(0);
set<int> ignora = {11, 13, 17, 19, 1};
int n; 

pair<int, vi> dp [(1<<16)][21];

pair<int, vi> solve(int mask, int lst){
	if(__builtin_popcount(mask) == ordem.size()) return make_pair(0, vi());
	if(dp[mask][lst].second.size() > 0) return dp[mask][lst];

	auto ans = make_pair(-INF, vi());

	for(int i=0, id; i<ordem.size(); i++){
		id = ordem[i];
		if(mask&(1<<i)) continue;

		auto tmp = solve(mask|(1<<i), id);
		tmp.first += __gcd(lst, id);
		tmp.second.push_back(id);

		if(tmp.first > ans.first) ans = tmp;
	}

	return dp[mask][lst] = ans;
}


int main(){
	optimize;
	cin >> n;

	vi num(n); 
	for(auto &x :  num){
		cin >> x;
		if(!ignora.count(x)) ordem.push_back(x);
	}

	sort(ALL(ordem));
	ordem.resize(unique(ALL(ordem)) - ordem.begin());

	auto sla = solve(0, 1).second;
	for(auto x : ignora) sla.push_back(x);


	ordem = vi(25, -1);
	for(int i=0; i<sla.size(); i++) ordem[sla[i]] = i;


	sort(ALL(num), [&](int a, int b){ return ordem[a] < ordem[b]; });

	int ans = 0;
	for(int i=1; i<num.size(); i++) ans += __gcd(num[i], num[i-1]);
	
	cout << ans << endl;
	
	return 0;	
}