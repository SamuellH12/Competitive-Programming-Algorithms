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
// https://codeforces.com/gym/104767/problem/L

string cd = ".X";

int main(){
	optimize;
	int r, g; cin >> r >> g;
	string s, t; 
	cin >> s;
	s = '.' + s + '.';
	t = s;
	

	for(int i=0; i<g; i++)
	{
		for(int i=1; i<s.size()-1; i++)
		{
			int code = (1<<2)*(s[i-1]=='X') + (1<<1)*(s[i]=='X') + 1*(s[i+1]=='X');

			cout << (t[i] = cd[bool(r&(1<<code))]);
		}
		cout << endl;
		swap(t, s);
	}
	
	return 0;	
}
