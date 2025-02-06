#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2019/f3/mesa/


int main(){
	int a, b; 
	cin >> a >> b;

	a %= 3;
	b %= 3;

	if(b == a) b = (b+1)%3;
	if(a > b) swap(a, b);

	if(a == 0) cout << (b == 1 ? 2 : 1) << endl;
	else 	   cout << 0 << endl;

	return 0;	
}
