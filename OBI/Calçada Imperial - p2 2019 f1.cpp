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
//https://olimpiada.ic.unicamp.br/pratique/p2/2019/f1/imperial/

int main(){
	int n; cin>>n;
	int c[n]; 

	for(int i=0; i<n; i++)
		cin >> c[i];
	
	int resp = 1;

	int a, b;
	for(int i=0; i<n; i++)
	{
		for(int e=i+1; e<n; e++)
		{
			a = c[i];
			b = c[e];
			if(a == b) continue;
			
			int x=e+1, seq=2;
			while(x < n)
			{
				if(c[x] == a)
				{
					swap(a, b);
					seq++;
				}
				x++;
			}

			resp = max(resp, seq);
		}
	}

	cout << resp << endl;
	
	return 0;	
}
