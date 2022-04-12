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

vi fatoreal(int n)
{
	vi resp;
	resp.push_back(1);

	for(int i=1; i<=n; i++)
	{
		int f = resp[resp.size()-1] * i;
		if(f >= n) break;
		resp.push_back(f);
		
	}

	return resp;
}

int main(){

	int n; cin>>n;

	vi fator = fatoreal(n);

	int qtd = 0, valor = 0;

	//for(auto a : fator) cout<<a<<" ";

	while(valor < n)
	{
		
		//cout<<fator[fator.size()-1]<<" "<<valor<<endl;
		if(valor + fator[fator.size()-1] <= n)
		{
			valor += fator[fator.size()-1];
			qtd++;
		}
		else fator.pop_back();
	}

	cout<<qtd<<endl;

	return 0;	
}

//1936 - Fatorial