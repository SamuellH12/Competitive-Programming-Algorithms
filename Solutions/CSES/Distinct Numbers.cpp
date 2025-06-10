#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1621/


int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	vector<int> sla(n);
	for(auto &x : sla) cin >> x;
	
	sort(begin(sla), end(sla));

	cout << unique(begin(sla), end(sla)) - begin(sla) << '\n';

	return 0;	
}
