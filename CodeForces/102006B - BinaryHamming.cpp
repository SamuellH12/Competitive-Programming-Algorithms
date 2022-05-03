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

//https://codeforces.com/gym/102006/problem/B

int main(){
	optimize;
	freopen("hamming.in", "r", stdin);

	int casos; cin>>casos;

	while(casos--)
	{
		int comp; cin>>comp;
		int zeros = 0, uns = 0;

		for(int i=0; i<comp; i++)
		{
			char x; cin>>x;
			if(x == '0') zeros++;
		}

		for(int i=0; i<comp; i++)
		{
			char x; cin>>x;
			if(x == '1') uns++;
		}

		cout<<comp - abs(zeros - uns)<<endl;
	}


	return 0;	
}
