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
//https://www.beecrowd.com.br/judge/pt/problems/view/1683


int main(){

	int n;
	while(cin >> n && n)
	{

		int hist[n];

		for(int i=0; i<n; i++) cin >> hist[i];

		stack<ll> pilha;
		ll resp = 0;

		for(int i=0; i < n; i++)
		{
			while(!pilha.empty() && hist[pilha.top()] > hist[i])
			{
				int tp = pilha.top();
				pilha.pop();


				resp = max(resp, hist[tp] * (i - 1 - (pilha.empty() ? -1 : pilha.top())) );
			}

			pilha.push(i);
		}

		while(!pilha.empty())
		{
			int tp = pilha.top();
			pilha.pop();

			resp = max(resp, hist[tp] * (n - 1 - (pilha.empty() ? -1 : pilha.top())) );
		}


		cout << resp << endl;
	}

	
	return 0;	
}
