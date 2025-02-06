#include <bits/stdc++.h>
using namespace std;



int main(){
	int n, k;
	cin >> n >> k;
	
	vector<int> fila (n);

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
