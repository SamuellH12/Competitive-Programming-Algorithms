#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;
// https://codeforces.com/gym/104767/problem/B

bool submasks[MAXN];


int main(){
	optimize;
	int n; 
	cin >> n;
	string s;

	for(int i=0; i<n; i++)
	{
		int mask = 0;
		cin >> s;

		for(auto c : s) mask |= (1<<(c-'a'));	

		submasks[mask] = true;
	}

	for(int i=0; i<17; i++)
		for(int mask=0; mask<(1<<17); mask++)
			if(mask&(1<<i))
				submasks[mask] |= submasks[mask^(1<<i)];

	cin >> s;

	vi freq(20, 0);
	ll ans = 0;

	for(int i=0, j=0, mask=0; i<s.size(); i++)
	{
		while(j < s.size() && !submasks[mask])	mask |= (1<<(s[j] - 'a')), freq[s[j++] - 'a']++;

		if(submasks[mask]) ans += ((s.size()-j)+1)*1LL;

		if(--freq[s[i]-'a'] == 0) mask ^= (1<<(s[i]-'a'));
	}
	
	cout << ans << endl;
	
	return 0;	
}

/*
SoS DP - Calcular uma propriedade pra uma mask com base em todas as suas submasks assume que submasks[casosBase] já estão definidos

- versão iterativa:
	for(int mask = 0; mask < (1<<N); ++mask)
		for(int i = 0;i < N; ++i)
			if(mask & (1<<i)) dp[mask][i] = dp[mask][i-1] + dp[mask^(1<<i)][i-1];
			else dp[mask][i] = dp[mask][i-1];
	

Pelo que eu entendi:

SoS DP calcula uma propriedade pra cada mask com base em todas as suas submasks.

Eu itero por cada mask e por cada bit dessa mask (assumindo que os casos base já estão definidos).

Eu posso calcular o valor da DP de uma mask, considerando as submasks que diferem nos primeiros i-bits considerando a união das respostas entre: 
   +  o conjunto que difere apenas os primeiros (i-1)-bits com o i-ésimo bit desligado (uma submask); e 
   +  o conjunto que difere apenas os primeiros (i-1)-bits com o i-ésimo bit ligado (se a mask atual tiver o i-ésimo bit ligado e, portanto, esse for uma submask).

Se eu calculo isso com i de 0 até B (#bits da mask), eu tenho no fim a resposta considerando todas as submaks. Complexidade final O(B * 2^B).
(Como a interseção entre esses dois conjuntos é vazia, não é preciso se preocupar com isso)

Pra não precisar de memória extra, eu ainda posso iterar com o primeiro for para cada bit e com o segundo for para cada mask, já que a resp só depende das masks anteriores e dos bits anteriores da mask atual. 

*/