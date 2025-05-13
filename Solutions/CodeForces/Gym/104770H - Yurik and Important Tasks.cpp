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
// https://codeforces.com/group/yc7Yxny414/contest/104770/problem/H

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

Node* update(Node *node, int l, int r, int pos, int v){
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

int kth(Node *Left, Node *Right, int l, int r, int k){
	if(l == r) return l;

	int sum = Right->L->val - Left->L->val;
	int m = (l+r)/2;

	if(sum >= k) return kth(Left->L, Right->L, l, m, k);

	return kth(Left->R, Right->R, m+1, r, k - sum);
}



int main(){	optimize;

	int n, m, k;
	cin >> n >> m >> k;

	vector<Node*> seg;
	seg.emplace_back(build(1, n));
	map<int, int> sla;
	
	for(int i=0, x; i<n; i++)
	{
		cin >> x;
		seg.emplace_back(update(seg.back(), 1, n, x, 1));
		sla[x] = i;
	}
	
	vector<pii> q(m);
	for(auto &[l, r] : q) cin >> l >> r;

	while(!q.empty())
	{
		auto [l, r] = q.back();
		q.pop_back();

		if(k < l || r < k) continue;

		int p = k-l+1;
		
		k = l +  sla[kth(seg.front(), seg[r-l+1], 1, n, p)];
	}

	cout << k << endl;
	
	return 0;	
}
