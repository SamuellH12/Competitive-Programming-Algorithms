//Samuell H C P C - OBI 2022 - IFPI
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



int main(){

	int n, m, s;
	cin >> n >> m >> s;

	int resp = -1;
	for(int i=m; i >=n; i--)
	{
		int x = i, t = 0; 

		while(x > 0)
		{
			t += x%10;
			x /= 10;
		}

		if(t == s){ resp = i; break; }
	}
	
	cout << resp << endl;
	
	return 0;	
}
