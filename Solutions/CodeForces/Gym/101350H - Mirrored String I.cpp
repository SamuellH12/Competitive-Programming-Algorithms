#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;
//https://codeforces.com/gym/101350/problem/H

int n;
set<char> let = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

bool espelho(string w)
{
	int i=0, f=w.size()-1;

	while(i <= f)
	{
		if(w[i] != w[f]) return false;
		if( !let.count(w[i]) ) return false;
		i++; f--;
	}

	return true;
}

int main(){
	cin >> n;
	string w;

	while(n--)
	{
		cin >> w;

		cout << (espelho(w) ? "yes" : "no") << endl;
	}
	
	return 0;	
}
