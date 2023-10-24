#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// https://www.spoj.com/problems/RMQSQ/

const int MAXN = 1e5 + 5;
const int MAXLG = 31 - __builtin_clz(MAXN) + 1;

int N;
int value[MAXN];
int table[MAXN][MAXLG];

void calc()
{
	for(int i=0; i<N; i++) table[i][0] = value[i];

	for(int p=1; p < MAXLG; p++)
		for(int i=0; i + (1 << p) <= N; i++)
			table[i][p] = min(table[i][p-1], table[i+(1 << (p-1))][p-1]);
}

int flog(int x){
	return 31 - __builtin_clz(x);
}

int query(int l, int r){
	int p = flog(r - l + 1);

	return min(table[l][p], table[ r - (1<<p) + 1 ][p]);
}


int main(){

	cin >> N;

	for(int i=0; i<N; i++) cin >> value[i];
	calc();

	int q, l, r; 
	
	cin >> q;

	while (q--)
	{
		cin >> l >> r;

		cout << query(l, r) << endl;
	}
	


	return 0;	
}
