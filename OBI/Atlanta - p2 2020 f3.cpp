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
//https://olimpiada.ic.unicamp.br/pratique/p2/2020/f3/atlanta/resultado/


int main(){
	int a, b, x=-1, y=-1;
	cin >> a >> b;

	for(int i=3; i<1010 && i < a; i++)
	{
		int aux = (a+b)/i;
		if(aux*i == a+b && 2*aux+2*(i-2) == a ) 
		{
			x = aux; y = i;
			break;
		}
	}
	
	if(x > y) swap(x, y);

	cout << x << " " << y << endl;
	
	return 0;	
}
