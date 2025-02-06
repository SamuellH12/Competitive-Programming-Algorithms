#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<long long>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2021/f2/retangulo/
ll n;
vi bit;

ll segmento(int a, int b)
{
	return ( bit[b] - bit[a] );
}


int main(){
	cin >> n;
	bit = vi(n+1);
	bit[0] = 0;

	for(int i=1, x; i<=n; i++){
		cin >> x;
		bit[i] = bit[i-1]+x;
	}
	
	int ans = 0, d = bit[n];

	for(int i=1; i<=n && ans < 2; i++)
	{

		int l=i+1, r = n, mid;
		while( l <= r)
		{
			mid = (l+r)/2;

			if(segmento(i, mid)*2 > d) r = mid - 1;
			else
			if(segmento(i, mid)*2 < d) l = mid + 1;
			
			if(segmento(i, mid)*2 == d){ ans++; break;}
		}

	}

	cout << (ans >= 2 ? "S" : "N") << endl;
	
	return 0;	
}


/*
Solução Lenta
Pontos: 40 de 100

ll segfinal(int a, int b)
{
	return bit[b-1] + bit[n] - bit[a-1];
}

bool lados(int i)
{
	ll  ss, bs, ds;

	//pego um segmento arbitrário
	for(int j=i+1; j <= n - 2; j++)
	{
		ss = segmento(i, j);

		if(ss > soma/2) break;

		//pego mais um segmento
		for(int k=j+1; k <= n - 1; k++)
		{
			ds = segmento(j, k);

			if(ds > soma/2) break;

			// o ultimo seg com o for; esse seg tem de ser igual ao primeiro
			for(int e=k+1; e <= n; e++)
			{
				bs = segmento(k, e);
				if(bs < ss) continue;
				if(bs > ss) break;
				//se esse segmento for igual ao de cima, pra ser retangulo só precisa do último

				if(segfinal(e, i) == ds) return true;
			}
		}
	}

	return false;
}

*/