#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXLOG = 31 - __builtin_clz(MAXN) + 1;
typedef int NodeId;
typedef int STp; 

const STp NEUTRO = 0;
int IDN, LSEG, RSEG;
extern struct Node NODES[];

struct Node	{
	STp val;
	NodeId L, R;
	Node(STp v = NEUTRO) : val(v), L(-1), R(-1) {}
	Node& l(){ return NODES[L]; }
	Node& r(){ return NODES[R]; }
};

Node NODES[4*MAXN + MAXLOG*MAXN]; //!!!CUIDADO COM O TAMANHO (aumente se necessário)
pair<Node&, NodeId> newNode(STp v = NEUTRO){ return {NODES[IDN] = Node(v), IDN++}; }

STp join(STp lv, STp rv){ return lv + rv; }

NodeId build(int l, int r, bool root=true){
	if(root) LSEG = l, RSEG = r;
	if(l == r) return newNode().second;

	int m = (l+r)/2;
	auto [node, id] = newNode();

	node.L = build(l,   m, false);
	node.R = build(m+1, r, false);
	node.val = join(node.l().val, node.r().val);

	return id;
}

NodeId update(NodeId node, int l, int r, int pos, int v){
	if( pos < l || r < pos ) return node;
	if(l == r) return newNode(NODES[node].val + v).second;

	int m = (l+r)/2;
	auto [nw, id] =newNode();

	nw.L = update(NODES[node].L, l,   m, pos, v);
	nw.R = update(NODES[node].R, m+1, r, pos, v);

	nw.val = join(nw.l().val, nw.r().val);

	return id;
}
NodeId update(NodeId node, int pos, STp v){ return update(node, LSEG, RSEG, pos, v); }

int query(Node& node, int l, int r, int a, int b){
	if(b <  l || r <  a) return NEUTRO;
	if(a <= l && r <= b) return node.val;
	
	int m = (l+r)/2;
	
	return join(query(node.l(), l, m, a, b), query(node.r(), m+1, r, a, b));
}
int query(NodeId node, int a, int b){ return query(NODES[node], LSEG, RSEG, a, b); }

int kth(Node& Left, Node& Right, int l, int r, int k){
	if(l == r) return l;

	int sum =Right.l().val - Left.l().val;
	int m = (l+r)/2;

	if(sum >= k) return kth(Left.l(), Right.l(), l, m, k);
	return kth(Left.r(), Right.r(), m+1, r, k - sum);
}
int kth(NodeId Left, NodeId Right, int k){ return kth(NODES[Left], NODES[Right], LSEG, RSEG, k); }

/*LATEX_DESC_BEGIN***************************
-> Segment Tree Persistente: (2x mais rápido que com ponteiro)
Build(1, N) -> Cria uma Seg Tree completa de tamanho N;	RETORNA o NodeId da Raiz
Update(Root, pos, v) -> Soma +V em POS; RETORNA o NodeId da nova Raíz;
Query(Root, a, b) -> RETORNA o valor do range [a, b];
Kth(RootL, RootR, K) -> Faz uma Busca Binária na Seg de diferença entre as duas versões.
[ Root -> Nó Raiz da Versão da Seg na qual se quer realizar a operação ]

Build:  O(N)  !!! Sempre chame o Build
Query:  O(log N)
Update: O(log N)
Kth:	O(Log N)
*****************************LATEX_DESC_END*/