#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF (int)(0x3f3f3f3f3f3f3f3f)
const int MAXN = 1e6 + 5;
using namespace std;
// https://codeforces.com/contest/1996/problem/F

#define int ll


int32_t main(){
	optimize;
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;

		vi a(n), b(n);
		for(auto &x : a) cin >> x;
		for(auto &x : b) cin >> x;

		int l=0, r=1e9+10, mid;
		int lim = 0;
		while(l <= r)
		{
			mid = (l+r)>>1LL;

			int op = 0;
			for(int i=0; i<n; i++)
				if(a[i] > mid)
					op += (a[i] - mid  +b[i]-1LL) / b[i];

			if(op <= k) lim = mid, r = mid-1;
			else l = mid+1;
		}

		int pontos = 0;
		for(int i=0; i<n; i++)
		{
			if(a[i] <= lim) continue;

			int opt = (a[i] - lim  +b[i]-1LL) / b[i];        //quantidade TOTAL de operações que vou fazer
			int op  = opt - (a[i]-(opt-1)*b[i]<lim ? 1 : 0 );//quantidade de operações "completas" que vou fazer (maiores que b)
			int sg  = a[i] / b[i];        		             //quantidade de operações POSSIVEIS (maiores que b)
			int ig  = sg-op;					             //quantidade de operações que não vou fazer
			int tot = ((sg*(sg+1LL))>>1LL) - ((ig*(ig+1LL))>>1LL);

			pontos += tot*b[i] + opt*(a[i]%b[i]);
			a[i] = a[i] - b[i]*opt;
			k -= opt;
		}


		priority_queue<pii> pq;
		for(int i=0; i<n; i++)  if(a[i] > 0) pq.emplace(a[i], b[i]);

		while(k-- && !pq.empty())  // k < n
		{
			auto [aa, bb] = pq.top();
			pq.pop();

			pontos += aa;
			aa -= bb;
			if(aa > 0) pq.emplace(aa, bb);
		}

		cout << pontos << endl;
	}	
	
	return 0;	
}
