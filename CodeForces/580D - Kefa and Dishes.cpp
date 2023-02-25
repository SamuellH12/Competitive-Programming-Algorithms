#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define int long long

//https://codeforces.com/problemset/problem/580/D

int n, m, k;
vi dish;
map<pair<int, int>, int> rule;
int memo[600000][20];

//      get - pegos, last, 
int solve(int g,  int l)
{
    if(__builtin_popcount(g) == m) return 0;
    if(memo[g][l] != -1) return memo[g][l];


    int resp = 0;
    for(int i=1; i<=n; i++)
    {
        if((1<<i & g)) continue;

        int ans = solve(g | 1<<i, i) + dish[i];
        if(rule.find({l, i}) != rule.end()) ans += rule[{l, i}]; 


        resp = max(resp, ans);
    }

    return memo[g][l] = resp;
}


int32_t main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;

    dish = vi(n+1);

    for(int i=1, x; i<=n; i++){
        cin >> x; dish[i] = x;
    }

    for(int i=0, x, y, c; i<k; i++){
        cin >> x >> y >> c;
        rule[ {x, y} ] = c; //1<<x | 1<<y
    }

    memset(memo, -1, sizeof(memo));
    cout << solve(0, 0) << endl;


    return 0;
}

