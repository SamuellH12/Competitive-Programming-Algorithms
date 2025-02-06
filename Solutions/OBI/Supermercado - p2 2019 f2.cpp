#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
using namespace std;

//https://olimpiada.ic.unicamp.br/pratique/p2/2019/f2/supermercado/

int main(){

	int n; cin >> n;
	float resp = INF;

	while(n--)
	{
		float p, g;
		cin >> p >> g;
		resp = min(resp, (p*1000/g) );
	}

	cout << fixed << setprecision(2) << resp << endl;
	
	return 0;	
}
