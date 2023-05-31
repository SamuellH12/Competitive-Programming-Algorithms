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

//https://codeforces.com/problemset/problem/4/C

int main(){

	int n;
	cin >> n;

	unordered_map<string, int> mp;

	string s;
	while(n--)
	{
		cin >> s;

		if(mp[s] == 0)
			cout << "OK" << endl;
		else
			cout << s << mp[s] << endl;
		
		mp[s]++;
	}
	
	
	return 0;	
}
