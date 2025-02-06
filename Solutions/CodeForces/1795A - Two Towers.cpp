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

//https://codeforces.com/contest/1795/problem/A


int main(){
	//optimize;

	int test; cin >> test;

	while(test--)
	{
		int a, b;
		cin >> a >> b;

		string s, t;
		cin >> s >> t;

		reverse(ALL(t));

		s += t;

		//cerr << " -> " << s << endl;
 
		int q = 0;

		for(int i=0; i<s.size()-1; i++){
			if(s[i] == s[i+1]){
				q++;
			}
		}
				
		//cout << "TESTE " << test << ": ";
		cout << (q < 2 ? "YES" : "NO") << endl;
	}

	
	
	return 0;	
}
