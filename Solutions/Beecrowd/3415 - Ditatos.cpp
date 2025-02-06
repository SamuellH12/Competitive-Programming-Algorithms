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
// https://judge.beecrowd.com/pt/problems/view/3415

int pontos[5];
int edit[5];

int dp[25][25];

int solve(string &s, string &t){
	int n = s.size(), m = t.size();

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(s[i-1] == t[j-1])
				dp[i][j] = dp[i-1][j-1];
			else 
				dp[i][j] = 1 + min({
					dp[i][j-1],  // deletar
					dp[i-1][j],  // inserir
					dp[i-1][j-1] // substituir
				});
		
	return dp[n][m];
}

void initDp(){ for(int i=0; i<25; i++) dp[0][i] = dp[i][0] = i; }


int main(){
	initDp();
	int n; cin >> n;
	string s, t;

	while(n--)
	{
		cin >> s;
		int mn = INF;

		for(int i=0; i<5; i++)
		{
			cin >> t;
			edit[i] = solve(s, t);
			mn = min(mn, edit[i]);
			// cerr << edit[i] << " ";
		}
		// cerr << endl;

		for(int i=0; i<5; i++)
			if(edit[i] == mn)
				pontos[i] += 1 + (mn == 0);
	}

	int mx = -INF;
	for(int i=0; i<5; i++) mx = max(mx, pontos[i]);

	cout << mx/2 << "." << (mx&1)*5 << endl;


	vi sla;

	for(int i=0; i<5; i++)
		if(pontos[i] == mx)
			sla.emplace_back(i+1);


	for(int i=0; i<sla.size()-1; i++) cout << sla[i] << " ";
	cout << sla.back() << endl;
	
	return 0;	
}
