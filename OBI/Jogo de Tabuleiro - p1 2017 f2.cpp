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

int n, tab[MAXN][MAXN];

int cor(int i, int j){

	if(tab[i-1][j] == 9)   tab[i-1][j]   = cor(i-1, j);
	if(tab[i-1][j-1] == 9) tab[i-1][j-1] = cor(i-1, j-1);
	if(tab[i][j-1] == 9)   tab[i][j-1]   = cor(i, j-1);

	return ( tab[i-1][j] + tab[i-1][j-1] + tab[i][j-1] < 2 ? 1 : 0);

}

int main(){

	cin>>n;

	for(int i=0; i<n; i++)
		for(int e=0; e<n; e++)
			cin>>tab[i][e];

	cout<<cor(n-1, n-1)<<endl;


	return 0;	
}
