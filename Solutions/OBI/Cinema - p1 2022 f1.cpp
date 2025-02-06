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
	int a, b, resp = 0;
	cin >> a >> b;

	if(a < 18) resp += 15; else
	if(a < 60) resp += 30;
	else 	   resp += 20;
	
	if(b < 18) resp += 15; else
	if(b < 60) resp += 30;
	else 	   resp += 20;
	
	cout << resp << endl;

	return 0;	
}
