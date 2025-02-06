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
//https://codeforces.com/gym/102861/problem/G


int main(){

	int n; cin>>n;

	int maxi = 100, atual = 100;

	for(int i=0, x; i<n; i++)
	{
		cin>>x;
		atual += x;
		maxi = max(maxi, atual);
	}

	cout<<maxi<<endl;

	return 0;	
}
