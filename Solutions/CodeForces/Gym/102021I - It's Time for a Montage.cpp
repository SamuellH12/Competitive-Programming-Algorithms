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
//https://codeforces.com/gym/102021


int main(){
	int n; cin>>n;

	int h [n];
	int v [n];

	for(int i=0; i<n; i++)
		cin>>h[i];

	int resp = 0;
	for(int i=0; i<n; i++)
	{
		cin>>v[i];

		if( v[i] > h[i] + resp && i == 0) 
			resp = v[i] - h[i];
		else if(v[i] < h[i] + resp)
			break;
		else if(v[i] == h[i] + resp && i == n-1)
			break;
		else if( v[i] > h[i] + resp )
		{
			resp++;
			break;
		}
	}

	cout<<resp<<endl;

	return 0;	
}

//https://vjudge.net/contest/479100#problem/I