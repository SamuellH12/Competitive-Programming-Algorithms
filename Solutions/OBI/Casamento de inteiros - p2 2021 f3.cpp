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
//https://olimpiada.ic.unicamp.br/pratique/p2/2021/f3/casamento/


int main(){

	string a, b;
	cin >> a >> b;

	if(a.length() < b.length()) swap(a, b);
	while(a.length() > b.length())	b = '0' + b;

	string x = "", y = "";
	
	for(int i=0; i<a.length(); i++)
		if(a[i] < b[i]) y += b[i];
		else
		if(a[i] > b[i]) x += a[i];
		else {
			x += a[i]; y += b[i]; 
		}

	int w = (x.length() ? stoi(x) : -1);
	int z = (y.length() ? stoi(y) : -1);

	if(w > z) swap(w, z);

	cout << w << " " << z << endl;

	return 0;	
}
