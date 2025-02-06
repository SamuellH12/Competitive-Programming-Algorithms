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
	int x, y, v, st=0, sf=0; 
	//x, y, valor, soma total e soma faltante
	

	for(int i=1; i<=n; i++)
	{
		int s = 0, z; //soma da linha, var aleatória pra leitura
		bool zero = false; //se encontrou o faltante aqui ou não

		for(int e=1; e<=n; e++)
		{
			cin >> z;
			s += z;

			if(z == 0)
			{
				zero = true;
				x = i;
				y = e;
			}
		}

		if(zero) sf = s;
		else st = s;

		if(st > 0 && sf > 0){
			v = st - sf;
			break;
		}
	}

	cout << v << endl << x << endl << y << endl;
	
	return 0;	
}
