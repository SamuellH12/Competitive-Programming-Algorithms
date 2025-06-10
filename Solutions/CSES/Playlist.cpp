#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1141

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
    int n; cin >> n;

    map<int, int> mp;

    int l=1, ans=1;

    for(int i=1, x; i<=n; i++)
    {
        cin >> x;
        
        l = max(l, mp[x]+1);
        ans = max(ans, i-l+1);
        mp[x] = i;
    }

    cout << ans << '\n';

	return 0;	
}
