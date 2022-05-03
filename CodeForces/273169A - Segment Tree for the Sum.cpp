#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN (int)1e5 + 10
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;

//const int MAXN = 1e6 + 10;
int n, m;
ll lista[MAXN];
ll seg[4 * MAXN];

//p é a posição na seg tree, l e r são as ranges do array
ll build(int p, int l, int r) // pra cada pos do array chama uma build que coloca seus valores na seg tree
{
	if(l == r) return seg[p] = lista[l];

	int m = (l+r)/2; // divide o atual range em 2 metades

	return seg[p] = build(p*2, l, m) + build(p*2+1, m+1, r); //a soma dessa range é a soma de suas duas metades
}


ll update(int p, int l, int r, int i, int x) // mesma coisa, mas quero mudar o valor do indice i pra o valor x
{
	if(i < l || r < i) return seg[p];
	if( i==l && i==r ) return seg[p] = x;

	int m = (l+r)/2;

	return seg[p] = update(p*2, l, m, i, x) + update(p*2+1, m+1, r, i, x);
}


ll query(int p, int l, int r, int a, int b) //mesmo funcionamento anterior, mas eu quero a soma entre a range a e b
{
	if(b < l || r < a) return 0; //ta completamente fora da range, retorna elemento neutro
	if( a<=l && r<=b ) return seg[p]; //se tá dentro, retorna seu valor na seg tree

	int m = (l+r)/2;

	return query(p*2, l, m, a, b) + query(p*2+1, m+1, r, a, b);	//se tá na metade, me divido no meio e busco nos dois
}


int main(){
	optimize;
	cin>>n>>m;

	for(int i=0; i<n; i++)
	{
		cin>>lista[i];
	}

	build(1, 0, n-1); //faz build começando da pos 1 da segtree, da range 0 ao n-1 do array

	while(m--)
	{
		int op; cin>>op;

		if(op == 1)
		{
			int i, v;
			cin>>i>>v;
			update(1, 0, n-1, i, v);
		}
		else
		{
			int a, b;
			cin>>a>>b;
			b--; //b n é inclusivo
			cout<<query(1, 0, n-1, a, b)<<endl;
		}
	}


	return 0;	
}

//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A