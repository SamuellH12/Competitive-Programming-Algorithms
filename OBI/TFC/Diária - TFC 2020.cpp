#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Vide *Prefix Sum*
//Sugestão de material -> https://youtu.be/dYt4O_U3AUo (^-^) Meu canal do Youtube

int main(){
	int n, q;
	cin >> n;

	ll sum[100010]; //ATENÇÃO: necessário usar long long (ll)
	sum[0] = 0;

	for(int i=0, k, p, id=1; i < n; i++)
	{
		cin >> k >> p;
		for(int j=0; j<k; j++)
		{
			sum[id] = sum[id-1] + p;
			id++;
		}
	}

	cin >> q;

	for(int i=0, x, y; i<q; i++)
	{
		cin >> x >> y;
		cout << sum[y] - sum[x-1] << endl;
	}
	
	return 0;	
}
