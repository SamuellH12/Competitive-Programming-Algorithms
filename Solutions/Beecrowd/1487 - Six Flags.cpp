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
#define temp first
#define pont second
int n, t;
pii brinq[MAXN];

int mem [MAXN][1000];
bool memo [MAXN][1000];



int mochileiro(int atual, int cronos)
{
	if(cronos > t) return -INF;
	if(atual == n ) return 0;

	if(memo[atual][cronos]) return mem[atual][cronos];
	   memo[atual][cronos] = true;


	int pontCom = mochileiro(atual+1, cronos + brinq[atual].temp) + brinq[atual].pont;
	int pontCont= mochileiro(atual,   cronos + brinq[atual].temp) + brinq[atual].pont;
	int pontSem = mochileiro(atual+1, cronos);

	return mem[atual][cronos] = max({pontCom, pontSem, pontCont});
}

int main(){
	optimize;
	int inst = 1;
	
	while(cin>>n>>t && (n+t) )
	{
		memset(memo, false, sizeof memo);
		cout<<"Instancia "<<inst<<endl;
		for(int i=0; i<n; i++)
		{
			int tempo, pontos;
			cin>>tempo>>pontos;
			brinq[i] = {tempo, pontos};
		}

		int resp = mochileiro(0, 0);

		cout<<resp<<endl<<endl;
		inst++;
	}

	return 0;	
}
