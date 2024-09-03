#include <bits/stdc++.h>
#define ll long long 
#define vi vector<ll>
#define pii pair<ll, ll>
using namespace std;
// https://codeforces.com/gym/105327/problem/C

vector<ll> buildSa(vi& in) {
  int n = in.size(), c = 0;
  vector<ll> temp(n), posBucket(n), bucket(n), bpos(n), out(n);
  for (int i = 0; i < n; i++) out[i] = i; 
  sort(out.begin(), out.end(), [&](int a, int b) { return in[a] < in[b]; });
  for (int i = 0; i < n; i++) {
    bucket[i] = c;
    if (i + 1 == n || in[out[i]] != in[out[i + 1]]) c++;
  }
  for (int h = 1; h < n && c < n; h <<= 1) {
    for (int i = 0; i < n; i++) posBucket[out[i]] = bucket[i];
    for (int i = n - 1; i >= 0; i--) bpos[bucket[i]] = i;
    for (int i = 0; i < n; i++) {
      if (out[i] >= n - h) temp[bpos[bucket[i]]++] = out[i];
    }
    for (int i = 0; i < n; i++) {
      if (out[i] >= h) temp[bpos[posBucket[out[i] - h]]++] = out[i] - h;
    }
    c = 0;
    for (int i = 0; i + 1 < n; i++) {
        int a = (bucket[i] != bucket[i + 1]) || (temp[i] >= n - h)
            || (posBucket[temp[i + 1] + h] != posBucket[temp[i] + h]);
        bucket[i] = c;
        c += a;
    }
    bucket[n - 1] = c++;
    temp.swap(out);
  }
  return out;
}
vector<ll> buildLcp(vi s, vector<ll> sa) {
  int n = (int) s.size();
  vector<ll> pos(n), lcp(n, 0);
  for(int i = 0; i < n; i++) {
    pos[sa[i]] = i;
  }
  int k = 0;
  for(int i = 0; i < n; i++) {
    if (pos[i] + 1 == n) {
      k = 0;
      continue;
    }
    int j = sa[pos[i] + 1];
    while(i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
    lcp[pos[i]] = k;
    k = max(k - 1, 0);
  }
  return lcp;
}

int32_t main(){

    ll n; cin >> n;
    
    vi sla(n);
    for(auto &x : sla) cin >> x;

    vi lcp = buildLcp(sla, buildSa(sla));
    
    vector<pii> st(1, {0, 0});

    ll ans = n*(n+1LL)/2LL;
    ll sum = 0;

    for(auto x : lcp)
    {
        ll cnt = 1;

        while(st.back().first > x)
        {
            cnt += st.back().second;
            sum -= st.back().first * st.back().second;
            st.pop_back();
        }  

        if(st.back().first != x) st.emplace_back(x, 0);
        st.back().second += cnt;

        sum += cnt * x;
        ans += 2LL*sum;
    }

    ll gc = gcd(ans, n*n);

    cout << ans/gc << "/" << (n*n)/gc;

    return 0;
}

/*
7 0 1 0 3 0 1
0 6 0 0 0 2 0
1 0 5 0 1 0 1
0 0 0 4 0 0 0
3 0 1 0 3 0 1
0 2 0 0 0 2 0
1 0 1 0 1 0 1

7
1 2 1 3 1 2 1

1               1   0
1 2 1           3   1
1 2 1 3 1 2 1   7   5
1 3 1 2 1       5   2
2 1             2   0
2 1 3 1 2 1     6   2
3 1 2 1         4   0

1 0 1 0 1 0 1   1
3 0 1 0 3 0 1   3
7 0 1 0 3 0 1   7
1 0 5 0 1 0 1   5
0 2 0 0 0 2 0   2
0 6 0 0 0 2 0   6
0 0 0 4 0 0 0   4




*/