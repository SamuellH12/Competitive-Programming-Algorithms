//Samuell H C P C - OBI 2022 - IFPI
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
//subcadeias

bool palin(string a)
{

	for(int i=0, f=a.size()-1; i < f; i++, f--)
		if(a[i] != a[f]) return false;

	return true;
}

int main(){
	int n; cin >> n;
	string a; cin >> a;

	for(int i=n; i>0; i--) //tam da sub
	{

		for(int j=0; j<=n-i; j++) //inicio
		{
			if( palin( string(a.begin()+j, a.begin()+j+i) ) )
			{
				cout << i << endl;
				return 0;
			}	
		}
		
	}

	cout << 1 << endl;
	
	return 0;	
}
