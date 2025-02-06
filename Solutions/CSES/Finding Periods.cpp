#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;


const int MAXN = 1e6 + 5;

const ll MOD = 1e9 + 7; //Big Prime Number - 12'501'968'177
const ll base = 153;

ll expBase[MAXN];

void precalc(){
	expBase[0] = 1;
	for(int i=1; i<MAXN; i++) 
		expBase[i] = (expBase[i-1]*base)%MOD;
}


struct StringHash{
	vector<ll> hsh;

	StringHash(string &_s){
		hsh = vector<ll>(_s.size()+1, 0LL);

		for(int i=0; i<_s.size(); i++)
			hsh[i+1] = ((hsh[i]*base) % MOD +(_s[i]*1LL)) % MOD;
	}
	
	ll gethash(int l, int r){
		return (MOD + hsh[r+1] - (hsh[l]*expBase[r-l+1]) % MOD ) % MOD;
	}
};


int main(){
	precalc();
	string s;
	cin >> s;

	int n = s.size();

	vi ans;

	StringHash hsh(s);

	//testando possíveis tamanhos
	for(int i=1; i<=n; i++){
		bool ok = true;
		//cerr << "sz = " << i << endl;
		for(int j=i; j<n; j+=i)
		{
			int sz = min(i, n-j);
			//cerr << string(s.begin(), s.begin()+sz) << "  " << j << " " << j+sz-1 << "  " << string(s.begin()+j, s.begin()+j+sz) << endl;
			//cerr << hsh.gethash(0, sz-1) << " = " << hsh.gethash(j, j+sz-1) << endl;
			if(  hsh.gethash(0, sz-1) != hsh.gethash(j, j+sz-1) ){
				ok = false;
				break;
			}
		}

		if(ok) ans.push_back(i);
	}

	for(auto x : ans) cout << x << " ";
	cout << endl;

	return 0;	
}
