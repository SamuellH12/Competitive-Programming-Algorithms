#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 2e3 + 5;
using namespace std;

struct exam {
	int s, p, e, a;
	exam(int s, int p, int e, int a) : s(s), p(p), e(e), a(a) {}
};

vector<exam> prova;

int intervalo(int i, bool prep){ return prova[i+1].s - (prep ?  prova[i].p : prova[i].e); }
int custo(int i){ return prova[i].a; }

int dp[MAXN][MAXN];

int solve(int i, int lft){
	if(i == 0 && lft == 0) return intervalo(0, 0);
	if(i == 0 || lft < 0) return -INF;
	if(~dp[i][lft]) return dp[i][lft];

	//dont study
	int r1 = solve(i-1, lft);
	if(r1 >= 0) r1 += intervalo(i, false);	// consegue completar os lft
	else r1 = -INF;	// não consegue completar os lft 
	
	// study
	int r2 = solve(i-1, lft-1);
	if(r2 >= custo(i)) r2 += intervalo(i, true) - custo(i); //consegue estudar
	else r2 = -INF;	//não consegue estudar

	return dp[i][lft] = max(r1, r2);
}


int main(){
	optimize;
	memset(dp, -1, sizeof dp);
	prova.emplace_back(0, 0, 0, 0);
	

	int n; cin >> n;

	for(int i=0, s, p, e, a; i<n; i++)
	{
		cin >> s >> p >> e >> a;
		prova.emplace_back(s, p, e, a);
	}
	
	prova.emplace_back(INF, 0, 0, 0);


	int ans = 0;
	for(int i=1; i<=n; i++)
		if(solve(n, i) >= 0) 
			ans = i;

	cout << ans << endl;

	return 0;	
}
