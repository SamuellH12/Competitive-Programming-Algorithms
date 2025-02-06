//Samuell H C P C - OBI 2022 - IFPI
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 35
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;

int c, l, k;
bool matriz[MAXN][MAXN]; //l c

void sec(int la, int ca, int d)
{
	matriz[la][ca] = 1;
	if( d == 0 ) //cima
	{
		if(la > 0) sec(la-1, ca, d);
	}
	else if( d == 1 ) //baixo
	{
		if(la < l) sec(la+1, ca, d);
	}
	else if( d == 2 ) //dir
	{
		if(ca < c) sec(la, ca+1, d);
	}
	else // esq 
	{
		if(ca > 0) sec(la, ca-1, d);
	}
}

bool bfs()
{
	queue<pii> fila;
	fila.push({1, 1});	//l c

	while( !fila.empty() )
	{
		int la = fila.front().first;
		int ca = fila.front().second;
		fila.pop();


		if(matriz[la][ca]) continue;
		matriz[la][ca] = 1;

		if(la == l && ca == c) return true;


		if(la < l) fila.push({la + 1, ca});
		if(la > 1) fila.push({la - 1, ca});
		if(ca < c) fila.push({la, ca + 1});
		if(ca > 1) fila.push({la, ca - 1});
	}

	return false;
}


int main(){
	cin >> c >> l >> k;

	for(int i=0; i<k; i++)
	{
		int cc, lc; string d;
		cin >> cc >> lc >> d;

		int dir; 
		if( d[0] == 'N') dir = 0; else
		if( d[0] == 'S') dir = 1; else
		if( d[0] == 'L') dir = 2; else
		if( d[0] == 'O') dir = 3;
		
		sec(lc, cc, dir);
	}
	
	cout << ( bfs() ? "S" : "N" ) << endl;
	
	return 0;	
}
