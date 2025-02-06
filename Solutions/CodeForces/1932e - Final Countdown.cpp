#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e3 + 5;
using namespace std;
// https://codeforces.com/contest/1932/problem/E

int main(){
	optimize;
	int t; cin >> t;
	while(t--){
		int n;
		cin >> n;

		string s, ans = ""; 
		cin >> s;
		vi ps(1, 0);
		
		for(int i=0; i<n; i++) ps.push_back(s[i]-'0'  + ps.back() );

		reverse(ALL(ps));

		for(int i=0; i<ps.size(); i++)
		{
			ans += ps[i]%10 + '0';

			if(ps.size() <= i+1 && ps[i]/10 > 0) ps.push_back(0); //cuidado com o overflow

			ps[i+1] += ps[i]/10;
		}


		while(ans.back() == '0') ans.pop_back();
		reverse(ALL(ans));
		
		cout << ans << endl;
	}
	
	return 0;	
}



/*
	//quanto o char atual contribui para a resposta?
	//o mais significativo a apenas a*1 vezes  (ou a*10^0)
	//o segundo mais b conttribui b*10 vezes (ou b*10^1) e assim por diante

12345
 1234
  123
   12
	1

*/