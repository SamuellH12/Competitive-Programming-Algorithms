#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1619

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
    int n; cin >> n;
    
    vector<pair<int, int>> sla;

    for(int i=0, a, b; i<n; i++){
        cin >> a >> b;

        sla.emplace_back(a, -1);
        sla.emplace_back(b, +1);
    }

    sort(begin(sla), end(sla));

    int sum = 0, ans = 0;

    for(auto [t, x] : sla)
    {
        sum -= x;
        ans = max(ans, sum);
    }

    cout << ans << '\n';

	return 0;	
}
