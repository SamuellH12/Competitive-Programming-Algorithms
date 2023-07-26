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
//https://codeforces.com/gym/101350/problem/I
//DP

int n;
set<char> let = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};


int gorila(string w)
{
	int resp = 0, S = w.size();
	bool memo[S][S];
	memset(memo, 0, sizeof(memo));

	//computa pra s = 1
	for(int i=0; i<S; i++)
		if(let.count(w[i])){
			memo[i][i] = true;
			resp = 1;
		}
	
	//computa pra s = 2
	for(int i=0; i<S-1; i++)
		if(w[i] == w[i+1] && let.count(w[i])){
			memo[i][i+1] = true;
			resp = 2;
		}

	for(int s=3; s<=S; s++){
		for(int i=0, j; i+s<=S; i++)
		{
			j = i + s - 1;
			if( w[i] == w[j] && let.count(w[i]) && memo[i+1][j-1] )
			{
				memo[i][j] = true;
				resp = s;
			}
		}
	}

	return resp;
}	


int main(){

	cin >> n;
	string w;

	while(n--)
	{
		cin >> w;

		cout << gorila(w) << endl;
	}
	
	return 0;	
}
