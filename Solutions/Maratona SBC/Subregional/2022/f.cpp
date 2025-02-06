#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 5 * 1e6 + 5;
using namespace std;

// F. Multidimensional Hangman
// https://codeforces.com/gym/103960/problem/F


int trie[MAXN][26], z=1;
int n, c;

int leaf[26][MAXN];

int insert(string &p, int i, int cur)
{
	if(i == c) return 0;

	if(p[i] == '*')
	{
		int mx = 0; 
		for(int id=0; id<26; id++)
		{
			if(trie[cur][id] == -1)
			{
				memset(trie[z], -1, sizeof trie[z]);
				trie[cur][id] = z++;
			}

			leaf[id][cur] = max(leaf[id][cur], insert(p, i+1, trie[cur][id]));
	
			if(i == c-1) leaf[id][cur]++;

			mx = max(mx, leaf[id][cur]);
		}

		return mx;
	}


	int id = (p[i] - 'a');

	if(trie[cur][id] == -1)
	{
		memset(trie[z], -1, sizeof trie[z]);
		trie[cur][id] = z++;
	}			
	

	leaf[id][cur] = max(leaf[id][cur], insert(p, i+1, trie[cur][id]));
	
	if(i == c-1) leaf[id][cur]++;

	return leaf[id][cur];
}


inline pair<string, int> solve(int i, int cur)
{
	if(i == c) return make_pair("", INF);

	pair<string, int> ans = make_pair("", -1);

	int idb = 0, best = -1;

	for(int id=0; id<26; id++)
	{
		if(trie[cur][id] == -1) continue;
		if(leaf[id][cur] <= best) continue;

		best = leaf[id][cur];
		idb = id;

		// auto temp = solve(i+1, trie[cur][id]);

		// temp.second = min(temp.second, terminal[id][cur]);

		// if(temp.second > ans.second)
		// {
		// 	ans.first = char('a' + id) + temp.first;
		// 	ans.second = temp.second;
		// }
	}

	auto temp = solve(i+1, trie[cur][idb]);
	temp.second = min(temp.second, leaf[idb][cur]);
	temp.first = char('a' + idb) + temp.first;

	return temp;
}


int main(){
	optimize;
	cin >> n >> c;

	memset(trie[0], -1, sizeof trie[0]);

	string s;
	for(int i=0; i<n; i++)
	{
		cin >> s;
		insert(s, 0, 0);
	}

	auto ans =  solve(0, 0);
	
	cout << ans.first << " " << ans.second << endl;
	
	return 0;	
}