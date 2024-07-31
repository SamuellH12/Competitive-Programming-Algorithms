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
// https://codeforces.com/contest/1932/problem/D

string cores = "CDHS";

inline int id(char c){
	for(int i=0; i<4; i++)
		if(cores[i] == c)
			return i;
	cerr << c << endl;
	return -1;
}


int main(){
	optimize;
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		char m; cin >> m;

		string temp;
		vector<vector<string>> cards(4);

		for(int i=0; i<2*n; i++)
		{
			cin >> temp;
			cards[id(temp[1])].push_back(temp);
		}

		vector<string> ans;

		bool ok = true;
		int mi = id(m);


		for(int i=0; i<4; i++)
		{
			sort(ALL(cards[i]));
			reverse(ALL(cards[i]));

			if(i == mi) continue;

			while(cards[i].size() >= 2)
			{
				temp = cards[i].back();
				cards[i].pop_back();
				
				temp += ' ';
				
				temp += cards[i].back();
				cards[i].pop_back();

				ans.push_back(temp);
			}

			if(!cards[i].empty())
			{
				if(cards[mi].empty()){ ok = false; break; }

				temp = cards[i].back();
				cards[i].pop_back();
				
				temp += ' ';
				
				temp += cards[mi].back();
				cards[mi].pop_back();

				ans.push_back(temp);
			}
		}



		while(cards[mi].size() >= 2)
		{
			
			temp = cards[mi].back();
			cards[mi].pop_back();
			
			temp += ' ';
	
			temp += cards[mi].back();
			cards[mi].pop_back();

			ans.push_back(temp);
		}


		ok &= cards[mi].empty();



		if(!ok)
		{
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		for(auto a : ans) cout << a << endl;

	}
	
	return 0;	
}
