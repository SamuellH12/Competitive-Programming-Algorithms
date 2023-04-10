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

struct BIT {
	int bit[MAXN];

	void update(int pos, int val){
		for(; pos < MAXN; pos += pos&(-pos))
			bit[pos] += val;
	}

	int query(int pos){
		int sum = 0;
		for(; pos > 0; pos -= pos&(-pos))
			sum += bit[pos];
		return sum;
	}

	void init(){
		memset(bit, 0, sizeof bit);
	}

} Bit;


int main(){
	cout << "Binary Indexed Tree - Fenwick Tree" << endl;
	return 0;	
}

/*

Syntax:

Bit.init();				//Seta tudo como 0
Bit.update(i, x);		//Adiciona +x na posição i da BIT
Bit.update(2, 5);
cout << Bit.query(i) << endl; //Retorna o somatório de [0, i]

Query: O(log n)
Update: O(log n)

*/

