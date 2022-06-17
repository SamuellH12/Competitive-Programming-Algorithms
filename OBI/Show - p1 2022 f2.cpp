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
	int a, h, l, resp = -1;
	cin >> a >> h >> l;

	for(int i=h, x; i>0; i--)
	{
		for(int e=l, cont = 0; e>0; e--)
		{
			cin >> x;

			if(x == 0) cont++;
			else cont = 0;

			if(cont >= a)
			{
				resp = i;
			}
		}
	}

	cout << resp << endl;
	
	return 0;	
}
