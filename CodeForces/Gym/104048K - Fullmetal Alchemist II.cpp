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


const ll MOD = 1e9 + 9;//1200000961; //WA? Muda o MOD e a base
const ll base = 153;

ll expBase[MAXN];


void precalc(){
	expBase[0] = 1;
	for(int i=1; i<MAXN; i++) 
		expBase[i] = (expBase[i-1]*base)%MOD;
}

int cnt = 0;

struct StringHash{
	vector<ll> hsh;
	string str = "";
	int size;
	int id;

	StringHash(string &_s){
		hsh = vector<ll>(_s.size()+1, 0);
		size = _s.length();
		str = _s;
		id = cnt++;
		for(int i=0; i<_s.size(); i++)
			hsh[i+1] = ((hsh[i]*base) % MOD +_s[i]) % MOD;
	}

	void addChar(char a){
		hsh.push_back( ((hsh.back()*base) % MOD + a) % MOD );
		size++;
		str += a;
	}
	
	ll gethash(int l, int r){
		return (MOD + hsh[r+1] - (hsh[l]*expBase[r-l+1]) % MOD ) % MOD;
	}

	bool operator < (const StringHash &b) const {
		return id < b.id;
	}
};


int main(){
	precalc();

	int n; cin >> n;
	string s;

	vector<StringHash> hsh;
	for(int i=0; i<n; i++)
	{
		cin >> s;
		hsh.push_back(StringHash(s));
	}

	int ans = INF;

	int comb[20][20];

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i == j){	 /*cerr << "- ";*/ continue; }

			auto &a = hsh[i];
			auto &b = hsh[j];

			int get = 0;
			for(int z=1; z<=b.size; z++){
				if(a.size < z) break;

				if(a.gethash(a.size-z,  a.size-1) == b.gethash(0, z-1) ) get = z;
			}

			for(int z=0; z+b.size<=a.size && get < b.size; z++)
				if(a.gethash(z, z+b.size-1) == b.gethash(0, b.size-1) )
					get = b.size;

			comb[a.id][b.id] = get;

			// cerr << comb[a.id][b.id] << " ";
		}

		// cerr << endl;
	}


	sort(ALL(hsh));
	do {
		int sz = hsh[0].size;
		int cmp = 0;

		for(int i=1; i<n; i++){
			sz += hsh[i].size - comb[hsh[cmp].id][hsh[i].id];
			if(comb[hsh[cmp].id][hsh[i].id] != hsh[i].size) cmp = i;
		}

		ans = min(ans, sz);
	} 
	while(next_permutation(ALL(hsh)));
	

	cout << ans << endl;

	return 0;	
}
