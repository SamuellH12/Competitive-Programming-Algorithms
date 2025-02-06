#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;



int main(){
	int n; cin >> n;
	int pp=0, mp=0;

	for(int i=0, j; i<n; i++)
	{
		cin>>j;
		if(j==1)pp++;
		else mp++;
	}

	int p, m; cin>>p>>m;

	if( p >= pp && m >= mp) cout<<"S"<<endl;
	else cout << "N" << endl;
	
	return 0;	
}
