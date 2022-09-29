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
	int n, p, ref = 0, sub = 0; 
	cin >> n;

	while(n--)
	{
		cin >> p;
		if( p < 50 ) sub++;
		else if( p >= 50 && p < 85) ref++;
	}

	cout << sub << " " << ref << endl;
	
	return 0;	
}
