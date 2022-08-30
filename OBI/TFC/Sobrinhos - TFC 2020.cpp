#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;



int main(){
	int n, k;
	cin >> n >> k;
	
	vi fila (n);

	//lê a fila
	for(int i=0, x, y; i < n; i++)
	{
		cin >> x >> y;
		fila[i] = x % y;
	}
	
	//e ordena a fila
	sort(fila.begin(), fila.end());

	cout << fila[k-1] << endl;

	return 0;	
}
