#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;
// https://codeforces.com/contest/1899/problem/G

struct Node	{
	int val = 0;
	Node *L = NULL, *R = NULL;
	Node(int v = 0) : val(v), L(NULL), R(NULL) {}
};


Node* update(Node *node, int l, int r, int pos, int v)
{
	if( pos < l || r < pos ) return node;
	if(l == r) return new Node(node->val + v);

	int m = (l+r)/2;

	if(!node->L) node->L = new Node();
	if(!node->R) node->R = new Node();

	Node *nw = new Node();

	nw->L = update(node->L, l,   m, pos, v);
	nw->R = update(node->R, m+1, r, pos, v);

	nw->val = nw->L->val + nw->R->val;

	return nw;
}


int query(Node *nl, Node *nr, int l, int r, int a, int b){
	if(b <  l || r <  a) return 0;
	if(a <= l && r <= b) return nr->val - nl->val;

	int m = (l+r)/2;

	if(!nl->L) nl->L = new Node();
	if(!nl->R) nl->R = new Node();
	if(!nr->L) nr->L = new Node();
	if(!nr->R) nr->R = new Node();

	return query(nl->L, nr->L, l, m, a, b) + query(nl->R, nr->R, m+1, r, a, b);
}


int idx[MAXN];
int tin[MAXN], tout[MAXN], val[MAXN], tim=1;
vi grafo[MAXN];

void dfs(int u, int p){
	tin[u] = val[idx[u]] = tim++;

	for(auto v : grafo[u])
		if(v != p) 
			dfs(v, u);
	
	tout[u] = tim++;
}

int main(){
	optimize;
	int t; cin >> t;
	while(t--){

		int n, q; cin >> n >> q;
		tim = 1;

		for(int i=0; i<=n; i++) grafo[i].clear();

		for(int i=1,u, v; i<n; i++){ 
			cin >> u >> v;
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}

		for(int i=1, p; i<=n; i++)
		{
			cin >> p;
			idx[p] = i;
		}

		dfs(1, -1);

		vector<Node*> vers; 
		vers.push_back(new Node());

		n *= 2;
		for(int i=1; i<=n; i++) vers.push_back(update(vers.back(), 1, n, val[i], 1));


		int l, r, x;
		while(q--)
		{
			cin >> l >> r >> x;

			cout << (query(vers[l-1], vers[r], 1, n, tin[x], tout[x]) ? "YES" : "NO") << endl;
		}

		cout << endl;
	}
	
	return 0;	
}
