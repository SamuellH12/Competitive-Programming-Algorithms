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
	int ia, ib, fa, fb, resp = 0;
	cin>>ia>>ib>>fa>>fb;

	if( ia == fa && ib == fb ){ resp = 0; }
	else
	if( ia == ib && fa == fb ){ resp = 1; }
	else
	if( ia == ib && fa != fb ){ resp = 2; }
	else
	if( ia != ib && fa == fb ){ resp = 2; }
	else
	if( ia != ib && fa != fb ){ resp = 1; }

	cout << resp << endl;	

	/*
	---OU---
	resp = 0;

	if(ib != fb){ resp++; ia = !ia;  }
	if(ia != fa){ resp++; }
	
	cout << resp << endl;
	*/
	
	return 0;	
}
