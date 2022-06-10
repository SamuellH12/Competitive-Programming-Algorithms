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

int matriz[105][105], n;

int empilhadeira(int i, int f)
{
	int soma = 0;
	int linha = f - i + 1;
	if(!linha) return 0;

	for(int x=i; x <=f; x++)
		soma += matriz[linha][x];

	return soma + min(  empilhadeira(i+1, f), empilhadeira(i, f-1)  );
}

int main(){
	cin >> n;

	for(int l=1; l<=n; l++)
		for(int c=1; c<=n; c++)
			cin >> matriz[l][c];
	
	int ans = empilhadeira(1, n);

	cout << ans << endl;	
	
	return 0;	
}
