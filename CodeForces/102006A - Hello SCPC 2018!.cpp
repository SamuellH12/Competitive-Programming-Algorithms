#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<long long>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;
//https://codeforces.com/gym/102006/problem/A


int main(){
	optimize;

	freopen("hello.in", "r", stdin);

	int casos; cin>>casos;


	while(casos--)
	{
		vi original;
		vi sorted;

		for(ll i=0, x=0; i<12; i++)
		{
			cin>>x;
			original.push_back(x);
			sorted.push_back(x);
		}

		sort(ALL(sorted));

		int resp = 0;
		for(int i=0; i<4; i++)
			if(original[i] == sorted[i]) resp++;
		
		cout<<(resp == 4 ? "yes" : "no" )<<endl;

	}



	return 0;	
}
