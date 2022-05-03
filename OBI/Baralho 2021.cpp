#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;

int c[14], e[14], u[14], p[14];

int main(){

	string cartas;
	cin>> cartas;

	for(int i=0; i<cartas.length(); i+=3)
	{
		int n = (cartas[i] - '0')*10  + (cartas[i+1] - '0');
		char t = cartas[i+2];
		
		if(t == 'C') c[n]++; else
		if(t == 'E') e[n]++; else
		if(t == 'U') u[n]++;
		else		 p[n]++;
	
	}

	int cq = 0;
	for(int i=1; i<14; i++)
		if(c[i] == 1) cq++; else
		if(c[i]  > 1){ cq = -1; break; }

	if(cq == -1) cout << "erro" << endl;
	else cout << 13 - cq << endl;


	int eq = 0;
	for(int i=1; i<14; i++)
		if(e[i] == 1) eq++; else
		if(e[i]  > 1){ eq = -1; break; }

	if(eq == -1) cout << "erro" << endl;
	else cout << 13 - eq << endl;


	int uq = 0;
	for(int i=1; i<14; i++)
		if(u[i] == 1) uq++; else
		if(u[i]  > 1){ uq = -1; break; }

	if(uq == -1) cout << "erro" << endl;
	else cout << 13 - uq << endl;

	int pq = 0;
	for(int i=1; i<14; i++)
		if(p[i] == 1) pq++; else
		if(p[i]  > 1){ pq = -1; break; }

	if(pq == -1) cout << "erro" << endl;
	else cout << 13 - pq << endl;
	
	return 0;	
}
