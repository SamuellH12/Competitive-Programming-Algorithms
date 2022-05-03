#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 210
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;

//https://codeforces.com/gym/101653

int main(){
	optimize;
	int casos; cin>>casos;

	while(casos--)
	{
		int qtd; cin>>qtd;

		vector< pair<float, float> > dimas;
		
		for(int i=0; i<qtd; i++)
		{
			float p, c; cin>>p>>c;
			dimas.emplace_back(p, c);
		}

		//LIS
		vi lis (qtd, 1);

		for(int i=1; i<qtd; i++)
			for(int j=0; j<i; j++)
				if(dimas[i].first > dimas[j].first && lis[i] < lis[j] + 1 /*<- LIS / questão ->*/ && dimas[i].second < dimas[j].second )
					lis[i] = lis[j] + 1; //isso com a verificação ^ acima
										//ou sem isso com um max(lis[i], lis[j] + 1); <- esse acho que é mais prático e didático, mas mais lento
		
		sort(ALL(lis));

		cout<<lis.back()<<endl;

	}

	return 0;	
}
