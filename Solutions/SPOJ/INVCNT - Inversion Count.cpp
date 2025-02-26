#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define ll long long
using namespace std;

vi sla;
vi aux;

ll solve(int l, int r){
	if(l == r) return 0;

	int m = (l+r)/2;

	ll ans = 0;
	ans += solve(l, m);
	ans += solve(m+1, r);

	for(int i=l, j=m+1; i<=m; i++)
	{
		while(j <= r && sla[j] < sla[i]) j++;
		ans += j - (m+1);
	}

	for(int i=l; i<=r; i++) aux[i] = sla[i];
	
	int i=l, j=m+1, k=l;
	while(i <= m && j <= r) sla[k++] = aux[i] < aux[j] ? aux[i++] : aux[j++];
	while(i <= m) sla[k++] = aux[i++];
	while(j <= r) sla[k++] = aux[j++];

	return ans;
}


int main(){ 
	optimize;
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		sla.resize(n);
		aux.resize(n);

		for(auto &x : sla) cin >> x;

		cout << solve(0, n-1) << '\n';
	}
	
	
	return 0;	
}
