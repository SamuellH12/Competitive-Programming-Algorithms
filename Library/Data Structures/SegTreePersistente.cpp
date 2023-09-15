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


int kth(Node *Left, Node *Right, int l, int r, int k){
	if(l == r) return l;

	int sum = Right->L->val - Left->L->val;
	int m = (l+r)/2;

	if(sum >= k) return kth(Left->L, Right->L, l, m, k);

	return kth(Left->R, Right->R, m+1, r, k - sum);
}


int main(){
	cout << "Segment Tree - Persistent" << endl;
	return 0;	
}

/******************************************************

-> Segment Tree Persistente com:
	- Query em Range
	- Update em Ponto


Build(1, N) -> Cria uma Seg Tree completa de tamanho N;	RETORNA um *Ponteiro pra Raíz
Update(Root, 1, N, pos, v) 	-> Soma +V na posição POS; RETORNA um *Ponteiro pra Raíz da nova versão;
Query(Root, 1, N, a, b) 	-> RETORNA o valor calculado no range [a, b];
Kth(RootL, RootR, 1, N, K) 	-> Faz uma Busca Binária na Seg; Mais detalhes abaixo;

[ Root -> Nó Raiz da Versão da Seg na qual se quer realizar a operação ]

Para guardar as Raízes, use: 
-> vector<Node*> roots; ou
-> Node* roots [MAXN];


Build:  O(N)
Query:  O(log N)
Update: O(log N)
Kth:	O(Log N)


Comportamento do K-th(SegL, SegR, 1, N, K):
	-> Retorna índice da primeira posição i cuja soma de prefixos [1, i] é >= k 
	na Seg resultante da subtração dos valores da (Seg R) - (Seg L).
	-> Pode ser utilizada para consultar o K-ésimo menor valor no intervalo [L, R] de um array. 
	Para isso a Seg deve ser utilizada como um array de frequências. Comece com a Seg zerada (Build). 
	Para cada valor V do Array chame um update(roots.back(), 1, N, V, 1) e guarde o ponteiro da seg.
	Para consultar o K-ésimo menor valor de [L, R] chame kth(roots[L-1], roots[R], 1, N, K);

IMPORTANTE! Cuidado com o Kth ao acessar uma Seg que está esparsa (RTE). Nesse caso, 
chame o Build antes ou garanta criar os nós L e R antes de acessá-los (como na query).

*******************************************************/