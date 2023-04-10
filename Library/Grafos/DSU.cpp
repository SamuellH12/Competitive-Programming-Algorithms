#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int pai[MAXN], sz[MAXN];

inline int find(int u){ 
	return ( pai[u] == -1 ?  u  :  pai[u] = find(pai[u])  ); 
}

inline void join(int u, int v){
	u = find(u);
	v = find(v);

	if(sz[v] > sz[u]) swap(u, v);

	pai[v] = u;
	sz[u] += sz[v];
}

inline void resetDSU(){
	memset(pai, -1, sizeof pai);
	memset(sz, 1, sizeof sz);
}



int main(){
	cout << "Disjoint Set Union - Union Find" << endl;
	return 0;	
}

/*************************************************
-> Complexity:

 - Find: O( α(n) ) -> Inverse Ackermann function 
 - Join: O( α(n) ) -> Inverse Ackermann function 

α(n) <= 4 Para todos os casos práticos
*************************************************/