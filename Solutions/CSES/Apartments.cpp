#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1084

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> p(n), ap(m);

	for(auto &x : p) cin >> x;
	for(auto &x : ap) cin >> x;

	sort(begin(p), end(p));
	sort(begin(ap), end(ap));

	int ans = 0;

	for(int i=0, j=0; i<m; i++)
	{
		while(j < n && p[j] < ap[i]-k) j++;
		
		if(j < n && ap[i]-k <= p[j] && p[j] <= ap[i]+k) ans++, j++;
	}

	cout << ans << '\n';

	return 0;	
}
