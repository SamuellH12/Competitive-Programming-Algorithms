#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;

int matriz[15][15], resp = 0;

bool verif(int x, int y, int go, int r, int d)
{
	if(x>14 || y>14) return false;
	if(x<0  || y<0 ) return false;

	if(matriz[x][y] == go) r++;
	else return false;

	if(r >= 5){
		resp = go;
		return true; 
	}

	int base = false;
	if(d==0) base = true;

	//diagonal / 1
	if( (base || d == 1) && verif(x-1, y+1, go, r, 1) ) return true;
	//diagonal \ 2
	if( (base || d == 2) && verif(x+1, y+1, go, r, 2) ) return true;
	//horizontal 3
	if( (base || d == 3) && verif(x  , y+1, go, r, 3) ) return true;
	//vertical   4
	if( (base || d == 4) && verif(x+1, y  , go, r, 4) ) return true;

	return false;
}

void solve(int x, int y)
{
	if( matriz[x][y] != 0 && verif(x, y, matriz[x][y], 0, 0) ) return;

	if(y < 14) solve(x, y+1);
	else 
	if(x < 14) solve(x+1, 0);
	
	return;
}

int main(){

	for(int i=0; i<15; i++)
		for(int e=0; e<15; e++)
			cin>>matriz[i][e];
	
	solve(0, 0);

	cout<<resp<<endl;

	return 0;	
}
