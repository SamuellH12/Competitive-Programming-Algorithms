#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, c;
    cin >> n >> c;

    int t, s;
    cin >> t >> s;

    vector<int> pat(n);
    for(auto &x : pat) cin >> x;
    pat.emplace_back(c+pat[0]);

    auto solve = [&](){
        vector<int> dp(n+1, 0);

        for(int i=n-1; i>=0; i--){
            int pt = upper_bound(begin(pat), end(pat)-1, pat[i]+t) - begin(pat);
            int ps = upper_bound(begin(pat), end(pat)-1, pat[i]+s) - begin(pat);
            
            dp[i] = min(dp[pt] + t, dp[ps] + s);
        }

        return dp[0];
    };

    int ans = 1e9;

    for(int i=0; i<n; i++){
        int frst = pat[0];
        for(auto &x : pat) x -= frst;
        pat.back() = c;

        ans = min(ans, solve());

        rotate(begin(pat), begin(pat)+1, end(pat));
    }


    cout << ans << endl;

    return 0;
}
