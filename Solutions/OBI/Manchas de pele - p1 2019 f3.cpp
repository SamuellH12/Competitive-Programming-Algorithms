#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 1010
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;

int m, n, resp;
int matriz[MAXN][MAXN];

void limp(int x, int y)
{
	matriz[x][y] = 0;

	if(x!=0 && matriz[x-1][y] == 1) limp(x-1, y);
	if(x<m-1&& matriz[x+1][y] == 1) limp(x+1, y);
	if(y!=0 && matriz[x][y-1] == 1) limp(x, y-1);
	if(y<n-1&& matriz[x][y+1] == 1) limp(x, y+1);
}

void lab(int x, int y)
{
	if(matriz[x][y] == 1)
	{
		resp++;
		limp(x, y);
	}

	if(y==n-1)
	{ 
		if(x==m-1) return;
		lab(x+1, 0);
	} 
	else
		lab(x, y+1);
}

int main(){
	cin>>m>>n;

	for(int i=0; i<m; i++)
		for(int e=0; e<n; e++)
			cin>>matriz[i][e];
	
	lab(0, 0);

	cout<<resp<<endl;

	return 0;	
}
