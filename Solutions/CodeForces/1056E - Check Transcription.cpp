#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;
//https://codeforces.com/problemset/problem/1056/E

const ll MOD = 1200000961; //WA? Muda o MOD e a base
const ll base = 153;

ll expBase[MAXN];


void precalc(){
	expBase[0] = 1;
	for(int i=1; i<MAXN; i++) 
		expBase[i] = (expBase[i-1]*base)%MOD;
}


struct StringHash{
	vector<ll> hsh;
	int size;

	StringHash(string &_s){
		hsh = vector<ll>(_s.size()+1, 0);
		size = _s.length();
		for(int i=0; i<_s.size(); i++)
			hsh[i+1] = ((hsh[i]*base) % MOD +_s[i]) % MOD;
	}
	
	ll gethash(int l, int r){
		return (MOD + hsh[r+1] - (hsh[l]*expBase[r-l+1]) % MOD ) % MOD;
	}
};


int main(){
	precalc();

	string bin, pat;
	cin >> bin >> pat;

	int f0 = -1, f1 = -1, tot0 = 0;
	int n = bin.size(), m=pat.size();

	for(int i=0; i<n; i++){
		if(bin[i] == '1' && f1 == -1) f1 = i;
		else 
		if(bin[i] == '0' && f0 == -1) f0 = i;

		if(bin[i] == '0') tot0++;
	}


	StringHash hsh(pat);

	int sz0, sz1, ans = 0;

	for(sz0 = 1; sz0 * tot0 < m; sz0++)
	{
		if(( m - sz0*tot0 ) % (n-tot0)) continue;
		sz1 = ( m - sz0*tot0 ) / (n-tot0);


		ll h1 = hsh.gethash( f1*sz0,  f1*sz0 + sz1 - 1 );
		ll h0 = hsh.gethash( f0*sz1,  f0*sz1 + sz0 - 1 );


		if(h1 == h0) continue;

		bool ok = true;
		int st = 0;
		for(int i=0; i<n && ok; i++)
		{
			if(bin[i] == '0')
			{
				if(hsh.gethash(st, st+sz0-1) != h0) ok = false;
				st += sz0;
			}
			else
			{
				if(hsh.gethash(st, st+sz1-1) != h1) ok = false;
				st += sz1;
			}
		}

		if(ok) ans++; 
	}

	cout << ans << endl;
	
	return 0;	
}
