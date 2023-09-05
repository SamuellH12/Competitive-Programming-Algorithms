#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<pair<int, int>,int>
#define ff first.first
#define sc first.second
#define td second
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;
#define mkp make_pair

// https://cses.fi/problemset/task/1140

bool order(piii a, piii b){ return a.sc < b.sc; }

int main(){
	int n; cin >> n;

	vector<piii> job(n);
	for(int i=0; i<n; i++) cin >> job[i].ff >> job[i].sc >> job[i].td;
	
	sort(ALL(job), order);


	vector<ll> dp (n+1, 0);

	for(int i=0; i<n; i++){

		int j = lower_bound(ALL(job), mkp(mkp(0, job[i].ff), 0), order) - job.begin();

		dp[i+1] = max(dp[i], dp[j] + job[i].td);
	}

	cout << dp[n] << endl;

	return 0;	
}

/*
	// ~= O(N log N) ?
	for(int i=0; i<n; i++)
	{
		//primeiro elemento com final >= que meu inicio						  v- Não sabia que podia passar o order aqui tb
		int j = lower_bound(ALL(job), make_pair(make_pair(0, job[i].ff), 0), order) - job.begin();

		//(como a dp é 1 indexado) dp é o max entre 
		//pegar o valor antes de eu pegar esse job + meu valor 
		//e o valor pra eu não pegar (que é o valor logo "atrás")
		dp[i+1] = max(dp[i], dp[j] + job[i].td);
	}
*/