#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<ll,ll>
using namespace std;

// https://atcoder.jp/contests/abc325/tasks/abc325_d

int main(){

	int n; cin >> n;

	vector<pii> lista(n);


	for(int i=0; i<n; i++)
		cin >> lista[i].first >> lista[i].second, lista[i].second += lista[i].first;
	
	
	sort(ALL(lista));
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	// vou adicionando os caras na pq no time em que eles aparecem e vou pegar o com o menor time

	int i=0, ans = 0;

	for(ll tm = 0; ; tm++)
	{
		if(pq.empty() && i >= n) break;

		if(pq.empty() && i < n && tm < lista[i].first) tm = lista[i].first; 	//se já processei todo mundo até o momento e ainda tenho mais caras pra processar, eu dou um skip pro próximo tempo livre

		while(i < n && lista[i].first == tm) pq.push(lista[i++].second);		//adiciono os novos itens que posso pintar a partir de agora

		while(!pq.empty() && pq.top() < tm) pq.pop();							//removo os caras que já passaram do tempo

		if(!pq.empty()) 														//pego o item que tá dentro do range que vai acabar primeiro
		{
			pq.pop();
			ans++;
		}
	}

	cout << ans << endl;

	return 0;	
}
