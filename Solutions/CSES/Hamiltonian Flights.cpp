#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1690/

const int MOD = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }
    vector<vector<int>> dp(1<<n, vector<int>(n));
    dp[1][0] = 1;
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1<<i)) && dp[mask][i]) {
                for (int j : adj[i]) {
                    if ((mask & (1<<j)) == 0) {
                        dp[mask|(1<<j)][j] = (dp[mask|(1<<j)][j] + dp[mask][i]) % MOD;
                    }
                }
            }
        }
    }
    cout << dp[(1<<n)-1][n-1] << endl;
    return 0;
}
