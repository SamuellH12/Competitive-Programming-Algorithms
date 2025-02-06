//URI - 1301 - Produto do Intervalo
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 100010
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;

int n, k, arvore[4 * MAXN];

void update(int no, int l, int r, int pos, int val){
	if(r<pos || pos < l) return;
	if(l == r){ arvore[no] = val; return; }

	int meio = (l + r)/2;
	int esq = 2 * no;
	int dir = esq + 1;

	update(esq, l, meio, pos, val);
	update(dir, meio+1, r, pos, val);

	arvore[no] = arvore[esq] * arvore[dir];
}

ll query(int no, int l, int r, int a, int b){
	if( l > b || a > r) return 1;
	if( a <= l && r <= b) return arvore[no];

	int meio = (l + r)/2;
	int esq = 2 * no;
	int dir = esq + 1;

	return query(esq, l, meio, a, b) * query(dir, meio+1, r, a, b);
}

int main(){
	optimize;

	while(cin>>n>>k)
	{
		memset(arvore, 1, sizeof arvore);

		for(int i=1, v; i<=n; i++)
		{
			cin>>v;
			if(v != 0) v = (v > 0 ? 1 : -1);
			update(1, 1, n, i, v);
		}

		for(int i=0; i<k; i++)
		{
			char comando;
			cin>>comando;

			if(comando == 'C')
			{
				int i, v;
				cin>>i>>v;
				if(v != 0) v = (v > 0 ? 1 : -1);
				update(1, 1, n, i, v);
			} 
			else
			{
				int i, j;
				cin>>i>>j;

				ll resp = query(1, 1, n, i, j);

				if(resp == 0) cout<<0;
				else cout<<(resp > 0 ? '+' : '-');
			}

		}

		cout<<endl;
	}

	return 0;	
}
