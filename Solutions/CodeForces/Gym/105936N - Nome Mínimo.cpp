#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
const int MAXN = 1e6 + 5;
using namespace std;
// https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/N

const ll MOD1 = 131'807'699;
const ll MOD2 = 1e9 + 7;
const ll base = 157;
 
ll expb1[MAXN], expb2[MAXN];
 
void precalc(){ 
    expb1[0] = expb2[0] = 1;
    
	for(int i=1;i<MAXN;i++)
        expb1[i] = expb1[i-1]*base % MOD1,
        expb2[i] = expb2[i-1]*base % MOD2;
}

struct StringHash{
    vector<pair<ll,ll>> hsh;
	string s;

    StringHash(string& s) : s(s) {
        hsh.assign(s.size()+1, {0,0});

        for (int i=0;i<s.size();i++)
            hsh[i+1].first  = ( hsh[i].first *base % MOD1 + s[i] ) % MOD1,
            hsh[i+1].second = ( hsh[i].second*base % MOD2 + s[i] ) % MOD2;
    }
 
    ll gethash(int a,int b){
        ll h1 = (MOD1+hsh[b+1].first  - hsh[a].first *expb1[b-a+1] % MOD1) % MOD1;
        ll h2 = (MOD2+hsh[b+1].second - hsh[a].second*expb2[b-a+1] % MOD2) % MOD2;
        return (h1<<32) | h2;
    }
};

int firstDiff(StringHash& a, int la, int ra, StringHash& b, int lb, int rb)
{
	int l=0, r=min(ra-la, rb-lb), diff=r+1;	
	while(l <= r){	
		int m = (l+r)/2;
		if(a.gethash(la, la+m) == b.gethash(lb, lb+m)) l = m+1;
		else r = m-1, diff = m;
	}
	return diff;
}

int hshComp(StringHash& a, int la, int ra, StringHash& b, int lb, int rb){
	int diff = firstDiff(a, la, ra, b, lb, rb);
	if(diff > ra-la && ra-la == rb-lb) return 0; //equal
	if(diff > ra-la || diff  >  rb-lb) return ra-la < rb-lb ? -2 : +2; //prefix of the other
	return a.s[la+diff] < b.s[lb+diff] ? -1 : +1;
}


int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	precalc();

	string s; cin >> s;
	
	reverse(begin(s), end(s));
	
	map<char, int> occ;
	for(auto &c : s) occ[c]++;
	
	string ans = "";
	while(!s.empty() && occ.begin()->first == s.back())
	{
		ans += s.back();
		if(--occ[s.back()] == 0) occ.erase(occ.begin());
		s.pop_back();
	}
	
	int n = s.size();
	StringHash hsh(s);
	reverse(begin(s), end(s));
	StringHash shs(s);

	int bst = 0;

	for(int i=1; i<n; i++)
	{
		int cmp = hshComp(hsh, i, n-1, hsh, bst, n-1);
		if(cmp == -1) bst = i;
		else 
		if(abs(cmp) == 2) //atual é prefixo da anterior
		{
			int szi = n-i, szb = n-bst, szdif = szb - szi;

			int dsp = hshComp(shs, szi, szi+szdif-1, hsh, bst+szi, bst+szi+szdif-1); 
			if(dsp == -1) bst = i;
		}
	}
	
	bst = n-bst-1;
	int i=0;

	while(i<bst && s[i] <= s[bst]) ans += s[i++];
	for(int j=bst; j>=i; j--) ans += s[j];
	for(i=bst+1; i<n; i++) ans += s[i];
	
	cout << ans << endl;

	return 0;	
}
