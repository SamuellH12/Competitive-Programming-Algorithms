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


struct Node	{
	int val = 0;

	Node *L = NULL, *R = NULL;

	Node(int v = 0) : val(v), L(NULL), R(NULL) {}
};


Node* build(int l, int r){
	if(l == r) return new Node();

	int m = (l+r)/2;

	Node *node = new Node();

	node->L = build(l,   m);
	node->R = build(m+1, r);

	node->val = node->L->val + node->R->val;

	return node;
}


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


int query(Node *node, int l, int r, int a, int b){
	if(b <  l || r <  a) return 0;
	if(a <= l && r <= b) return node->val;

	int m = (l+r)/2;

	if(!node->L) node->L = new Node();
	if(!node->R) node->R = new Node();

	return query(node->L, l, m, a, b) + query(node->R, m+1, r, a, b);
}


int kth(Node *Left, Node *Right, int l, int r, int k)
{
	if(l == r) return l;

	int sum = Right->L->val - Left->L->val;
	int m = (l+r)/2;

	if(sum >= k) 
		return kth(Left->L, Right->L, l, m, k);
	
	return kth(Left->R, Right->R, m+1, r, k - sum);
}



int main(){
	optimize;
	int n, m;
	cin >> n >> m;

	vector<Node*> versoes;
	vector<int> nums, coord;

	versoes.push_back(build(1, n));

	for(int i=1, v; i<=n; i++){
		cin >> v;

		coord.push_back(v);
		nums.push_back(v);
	}

	sort(ALL(coord));
	coord.resize(unique(ALL(coord)) - coord.begin());

	
	for(int i=1, id; i<=n; i++){
		
		id = lower_bound(ALL(coord), nums[i-1]) - coord.begin() + 1;

		versoes.push_back(update(versoes.back(), 1, n, id, 1));
	}


	int l, r, k;
	while(m--)
	{
		cin >> l >> r >> k;

		int id = kth(versoes[l-1], versoes[r], 1, n, k);
		cout << coord[id-1] << endl;
	}


	return 0;	
}
