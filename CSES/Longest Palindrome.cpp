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

// https://cses.fi/problemset/task/1111

vi manacher(string &st)
{
	string s = "$_";
	for(char c : st){ s += c; s += "_"; }
	s += "#";

	int n = s.size()-2;

	vi p(n+2, 0);
	int l=1, r=1;

	for(int i=1, j; i<=n; i++)
	{	
		p[i] = max(0, min(r-i, p[l+r-i]) );	//atualizo o valor atual para o valor do palindromo espelho na string ou para o total que está contido
		
		while( s[i-p[i]] == s[i+p[i]] ) p[i]++;

		if( i+p[i] > r ) l = i-p[i], r = i+p[i];
	}

	for(auto &x : p) x--; //o valor de p[i] é igual ao tamanho do palindromo + 1

	return p;
}

int main(){
	optimize;
	string s; cin >> s;
	int n = s.size();

	vi p = manacher(s);

	//for(auto x : p) cerr << x << " "; cerr << endl;

	int mx=0, id=0;

	for(int i=1; i<=n*2; i++)
		if(p[i] > mx)
			mx = p[i],
			id = i-1;
	
	cout << s.substr( (id/2) - (mx/2)  , mx) << endl;

	return 0;	
}



/*

a   y   b   a   b   t   u 
1 0 1 0 1 0 3 0 1 0 1 0 1 
bab


z   y   b   a   a   b   f   a
1 0 1 0 1 0 1 4 1 0 1 0 1 0 1
baab

*/