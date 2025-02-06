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

bool ganhador(int d, int x)
{
	int op1 = d + 1, op2 = d + 2;
	if(op1 > 4) op1 -= 5;
	if(op2 > 4) op2 -= 5;

	return op1 == x || op2 == x;
}


int main(){

	int n; cin >> n;
	int pd = 0, px = 0;

	while(n--)
	{
		int d, x;
		cin >> d >> x;

		if( ganhador(d, x) ) pd++;
		else px++;
	}

	cout << (pd > px ? "dario" : "xerxes") << endl;
	
	return 0;	
}
