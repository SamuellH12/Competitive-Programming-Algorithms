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
	int n; cin >> n;

	int lista[n], resp = 0;
	for(int i=0; i<n; i++)
		cin >> lista[i];
	
	for(int e=0, d=n-1; e < d; )
	{
		int somae = lista[e], somad = lista[d];

		while( somae != somad && e != d)
		{
			if(somae < somad){
				e++;
				somae += lista[e];
			}
			else
			{
				d--;
				somad += lista[d];
			}

			resp++;
		}

		if( somae == somad)
			e++; d--;
	}
	

	cout << resp << endl;
	
	return 0;	
}
