#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
//#define MAXN 110
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;

#define vll vector<long long>

const int MAXN = 1e6+10;
int MOD = 1e9 + 7;
int a, b, n;
ll fator[MAXN];

ll fpow(ll a, ll e)
{
	if(e == 0) return 1;

	if(e%2 == 0) return fpow(a*a%MOD, e/2);

	return a*fpow(a, e-1) % MOD;
}

ll inv(ll a)
{
	return fpow(a, MOD-2);
}

ll permuta(ll a, ll b)
{
	if(a < b) return 0;
	return fator[a] * inv(fator[b]) % MOD * inv(fator[a-b])  % MOD;
}

int main(){

	cin>>a>>b>>n;

	fator[0] = 1;

	for(int i=1; i<MAXN; i++) fator[i] = (fator[i-1] * i) % MOD;

	ll resp = 0;

	for(int i=0; i<=n; i++)
	{
		ll num = a*i + b*(n-i);
		bool exelent = true;

		while(num > 0)
		{
			int digito = num%10;

			if(digito != a && digito != b) exelent = false;

			num /= 10;
		}

		if(!exelent) continue;
		
		resp = (resp + permuta(n, i)) % MOD;
	}

	cout<<resp<<endl;

	return 0;	
}

//https://codeforces.com/problemset/status?my=on
//Depois tentar testar minha outra implementação, nas submissões do codeforces, mas prestando atenção em ll e int