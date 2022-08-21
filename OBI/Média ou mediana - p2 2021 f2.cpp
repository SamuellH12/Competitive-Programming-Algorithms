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

	int a, b, resp = INF;
	cin >> a >> b;
	
	if(a > b) swap(a, b);

	//A = mediana
	int c = 2*a - b;
	if(c <= a) resp = c;

	//B = mediana
	c = 2*b - a;
	if(c >= b && c < resp) resp = c;

	//C = mediana
	c = (a+b)/2;
	if(c >= a && c <= b && resp > c) resp = c;

	cout << resp << endl;
	
	return 0;	
}
