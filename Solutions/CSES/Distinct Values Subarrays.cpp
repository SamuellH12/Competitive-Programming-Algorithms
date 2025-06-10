#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/3420

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
    int n; cin >> n;

    map<int, int> mp;

    int l=1;
    long long ans=0;

    for(int i=1, x; i<=n; i++)
    {
        cin >> x;
        
        l = max(l, mp[x]+1);
        ans += i-l+1LL;
        mp[x] = i;
    }

    cout << ans << '\n';

	return 0;	
}
