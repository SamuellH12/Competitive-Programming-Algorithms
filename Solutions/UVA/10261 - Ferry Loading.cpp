#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1202

int ferry, n;
vi fila;
int memo[15000][15000];

int solve(int i, int l, int r){
	if(i == n) return memo[i][l] = 0;
	if(memo[i][l] != -1) return memo[i][l];

	int resp = 0, ans=0;

	if(l-fila[i] >= 0)
		resp = 1 + solve(i+1, l-fila[i], r);
	
	if(r-fila[i] >= 0)
		ans = 1 + solve(i+1, l, r-fila[i]);
	

	return memo[i][l] = max(resp, ans);
}

void rec(int i, int l, int r){
	if(i == n) return;
	if(memo[i][l] <= 0) return;

	int resp = 0, ans=0;

	if(l-fila[i] >= 0)
		resp = 1 + solve(i+1, l-fila[i], r);
	
	if(r-fila[i] >= 0)
		ans = 1 + solve(i+1, l, r-fila[i]);
	
	if(resp == 0 && ans == 0) return;

	if(resp >= ans)
	{
		cout << "port" << endl;
		rec(i+1, l-fila[i], r);
	} 
	else 
	{
		cout << "starboard" << endl;
		rec(i+1, l, r-fila[i]);
	}

}

int main(){
	int t; cin >> t;

	while(t--){
		memset(memo, -1, sizeof(memo));
		fila.clear();

		cin >> ferry;
		ferry *= 100;

		int c;
		while(cin >> c && c != 0)
			fila.push_back(c);

		n = fila.size();

		cout << solve(0, ferry, ferry) << endl;
		rec(0, ferry, ferry);
		
		if(t > 0) cout << endl;
	}

	return  0;
}