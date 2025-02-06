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

//https://codeforces.com/gym/102861/problem/F

int main(){

	string jogo;
	cin>>jogo;

	int i=0;

	int gl=0, gr=0, pl=0, pr=0;
	bool saque = 0;
	while(i < jogo.size())
	{

		if(jogo[i] == 'S')
		{
			if(saque == 0) pl++;
			else pr++;

		}
		else
		if(jogo[i] == 'R')
		{
			if(saque == 0) pr++;
			else pl++;
			saque = !saque;
		}
		else
		{
			if(i < jogo.size() - 1)
			{
				if(saque == 0)
					cout<<gl<<" ("<<pl<<"*) - "<<gr<<" ("<<pr<<")"<<endl;
				else
					cout<<gl<<" ("<<pl<<") - "<<gr<<" ("<<pr<<"*)"<<endl;
			}
			else
			{
				if(gl > gr)
					cout<<gl<<" (winner) - "<<gr<<endl;
				else
					cout<<gl<<" - "<<gr<<" (winner)"<<endl;
			}
			i++;
			continue;
		}

		if( (pl >= 5 && pl - pr >= 2) || pl == 10 )
		{
			gl++;
			pl = 0;
			pr = 0;
		}
		else
		if( (pr >= 5 && pr - pl >= 2) || pr == 10 )
		{
			gr++;
			pl = 0;
			pr = 0;
		}

		i++;
	}


	return 0;	
}
