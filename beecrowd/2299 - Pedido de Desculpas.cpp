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
int lim, qtd;
pii frases[55];
int mem[55][1010];
bool memo[55][1010];

int mochileiroDasGalaxias(int atual, int cha){
	if(cha > lim ) return -INF;
	if(atual == qtd) return 0;
	if(memo[atual][cha]) return mem[atual][cha];
	   memo[atual][cha] = true;
	
	int com = mochileiroDasGalaxias(atual+1, cha + frases[atual].first) + frases[atual].second;
	int sem = mochileiroDasGalaxias(atual+1, cha);

	return mem[atual][cha] = max(com, sem);
}
  

int main(){
	optimize;
	int teste = 1;

	while(cin>>lim>>qtd && (lim+qtd) )
	{   cout<<"Teste "<<teste<<endl;
		
		memset(memo, false, sizeof memo);

		for(int i=0; i<qtd; i++){
			int tam, desc;
			cin>>tam>>desc;
			frases[i] = {tam, desc};
		}

		int resp = mochileiroDasGalaxias(0, 0);

		cout<<resp<<endl<<endl;
		teste++;
	}


	return 0;	
}
