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

struct Dado {
	int lado[7];

	Dado(int A, int B, int C, int D, int E, int F)
	{
		lado[1]=A; lado[2]=B; lado[3]=C; lado[4]=D; lado[5]=E; lado[6]=F;
	}

	int Oposto(int x)
	{
		if(x == 1) return lado[6]; //a-f
		if(x == 2) return lado[4]; //b-d
		if(x == 3) return lado[5]; //c-e
		if(x == 4) return lado[2]; //d-b
		if(x == 5) return lado[3]; //e-c
		if(x == 6) return lado[1]; //f-a
		return lado[0];
	}

	int Maior(int x){
		int y = Oposto(x);
		    x = lado[x];
		if(x != 6 && y != 6) return 6;
		if(x != 5 && y != 5) return 5;
		return 4;
	}

};


int n;
vector<Dado> dados;


int solve(int atual, int faceCima)
{
	if(atual == dados.size()) return 0;
	int ladoCima;

	for(int i=1; i<=6; i++)
	{
		if(dados[atual].lado[i] == faceCima){
			faceCima = dados[atual].Oposto(i);
			ladoCima = i;
			break;
		} 
	}

	int resp = solve(atual + 1, faceCima);
	resp += dados[atual].Maior(ladoCima);

	return resp;
}


int main(){
	cin>>n;

	for(int i=0; i<n; i++){
		int a, b, c, d, e, f;
		cin>>a>>b>>c>>d>>e>>f;
		dados.push_back(Dado(a, b, c, d, e, f));
	}

	int resp = 0;

	for(int i=1; i<=6; i++)
	{
		resp = max(solve(0, i), resp);
		if(resp == n*6) break;
	}

	cout<<resp<<endl;

	return 0;	
}
