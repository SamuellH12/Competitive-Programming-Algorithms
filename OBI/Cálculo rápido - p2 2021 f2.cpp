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
//https://olimpiada.ic.unicamp.br/pratique/p2/2021/f2/calculo/

int sd(int x)
{
	int soma = 0;
	while(x > 0)
	{
		soma += x%10;
		x /= 10;
	}
	return soma;
}

int main(){

	int s, a, b;
	cin >> s >> a >> b;

	int resp = 0;

	for(int i=a; i <= b; i++)
		if( sd(i) == s)resp++;

	cout << resp << endl;
	
	return 0;	
}
