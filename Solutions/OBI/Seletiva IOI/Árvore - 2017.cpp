#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 5 * 1e5 + 5;
using namespace std;

// https://neps.academy/br/exercise/377

struct Node {
	int val = 0;

	Node *L = NULL, *R = NULL;

	Node(int v=0) : val(v), L(NULL), R(NULL) {}
};


Node* update(Node *node, int l, int r, int pos, int v)
{
	if( pos < l || r < pos ) return node;
	if(l == r) return new Node(node->val + v);

	int m = (l+r)/2;

	if(!node->L) node->L = new Node();
	if(!node->R) node->R = new Node();

	Node *nw = new Node();

	nw->L = update(node->L, l,  m, pos, v);
	nw->R = update(node->R, m+1,r, pos, v);

	nw->val = nw->L->val + nw->R->val;

	return nw;
}


int query(Node *node, int l, int r, int a, int b){
	if(b <  l || r <  a) return 0;
	if(a <= l && r <= b) return node->val;

	int m = (l+r)/2;

	if(!node->L) node->L = new Node();
	if(!node->R) node->R = new Node();

	return query(node->L, l, m, a, b) + query(node->R, m+1, r, a, b);
}


int kth(Node *U, Node *V, Node *A, Node *P, int l, int r, int k)
{
	if(l == r) return l;


	int sum = (U->L->val - A->L->val) + (V->L->val - P->L->val);
	int m = (l+r)/2;

	if(sum >= k) return kth(U->L, V->L, A->L, P->L, l, m, k);

	return kth(U->R, V->R, A->R, P->R, m+1, r, k - sum);
}

const int MAXLG = 20;


vector<int> grafo[MAXN];

int bl[MAXLG][MAXN], lvl[MAXN], val[MAXN];
int n;

Node* nos [MAXN];


void dfs(int u, int p){
	lvl[u] = lvl[p] + 1;
	bl[0][u] = p;

	nos[u] = update(nos[p], 1, MAXN, val[u], 1);

	for(auto v : grafo[u])
		if(v != p)
			dfs(v, u);
}


void buildBl(){
	for(int i=1; i<MAXLG; i++)
		for(int u=1; u<=n; u++)
			bl[i][u] = bl[i-1][bl[i-1][u]];
}

int lca(int u, int v)
{
	if(lvl[u] < lvl[v]) swap(u, v);

	for(int i=MAXLG-1; i>=0; i--)
		if(lvl[u] - (1<<i) >= lvl[v])
			u = bl[i][u];

	if(u == v) return u;

	for(int i=MAXLG-1; i>=0; i--)
		if(bl[i][u] != bl[i][v])
			u = bl[i][u],
			v = bl[i][v];

	return bl[0][u];
}


int main(){
	optimize;
	int q;
	cin >> n >> q;

	for(int i=1; i<=n; i++) cin >> val[i];

	for(int i=1, u, v; i<n; i++)
	{
		cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}

	nos[0] = new Node();


	dfs(1, 0);
	buildBl();


	int k, u, v;
	while(q--)
	{
		cin >> k >> u >> v;

		int a = lca(u, v);

		cout << kth(nos[u], nos[v], nos[a], nos[bl[0][a]], 1, MAXN, k) << endl;
	}
	
	
	return 0;	
}
