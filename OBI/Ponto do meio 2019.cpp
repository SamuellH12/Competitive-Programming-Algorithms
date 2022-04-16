#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;

  

int main(){

	int n;
	unsigned ll p = 3;

	cin>>n;

	for(int i=1; i<n; i++)
		p = p*2 - 1;

	cout<<p*p<<endl;

	return 0;	
}
