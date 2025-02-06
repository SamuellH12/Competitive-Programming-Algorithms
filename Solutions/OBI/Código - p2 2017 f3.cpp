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



int main(){
	optimize;
	int n; cin >> n;

	vector<string> txt(n);
	map<string, pii> pref, suf;
	set<string> st;

	int id=0;
	for(auto &s : txt){
		cin >> s;
		
		if(st.count(s))
		{
			cout << s << endl;
			return 0;
		}
		st.insert(s);


		
		string pf = s, sf = "";
		
		for(int i=0; i<9; i++)
		{
			sf = pf.back() + sf;
			pf.pop_back();

			auto pmp = pref[sf];
			auto smp = suf[pf];
			//if(s == "wuhcprvezo") cerr << pf << " / " << sf << " | " << pmp.first << "occ id" << pmp.second << " | " << smp.first << "occ id" << smp.second << endl;
			
			bool ok = pmp.first > 0  && smp.first > 0;
			ok = ok && (pmp.first > 1  || smp.first > 1 || pmp.second != smp.second);
			if(pmp.first == 1 && pmp.second == id) ok = false;
			if(smp.first == 1 && smp.second == id) ok = false;

			if(ok)
			{
				cout << s << endl;
				return 0;
			}

			pref[pf].first++;
			pref[pf].second = id;
			suf[sf].first++;
			suf[sf].second = id;
		}

		id++;
	}
	
	cout << "ok" << endl;

	return 0;	
}


/*

	id=0;
	for(auto &s : txt)
	{

		string pf = s, sf = "";
		
		for(int i=0; i<9; i++)
		{
			sf = pf.back() + sf;
			pf.pop_back();

			auto pmp = pref[sf];
			auto smp = suf[pf];
			//if(s == "wuhcprvezo") cerr << pf << " / " << sf << " | " << pmp.first << "occ id" << pmp.second << " | " << smp.first << "occ id" << smp.second << endl;
			
			bool ok = pmp.first > 0  && smp.first > 0;
			ok = ok && (pmp.first > 1  || smp.first > 1 || pmp.second != smp.second);
			if(pmp.first == 1 && pmp.second == id) ok = false;
			if(smp.first == 1 && smp.second == id) ok = false;

			if(ok)
			{
				cout << s << endl;
				return 0;
			}
		}

		id++;
	}

*/