#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;



int main(){
	optimize;
	int casos; cin>>casos;

	while(casos--)
	{
		map<int, int> votos;
		int qtdV; cin>>qtdV;

		int N=-1, V=0;

		for(int i=0, num; i<qtdV; i++)
		{
			cin>>num;
			votos[num]++;
			if( votos[num] > V || (votos[num] == V && num < N) )
			{
				N = num;
				V = votos[num];
			}
		}

		cout<<N<<endl;
	}


	return 0;	
}
