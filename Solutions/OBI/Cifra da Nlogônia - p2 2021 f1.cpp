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

string alfa = " abcdefghijklmnopqrstuvxz";
int vogPos[] = {1, 5, 9, 15, 21};

char vogalMaisProxima( char x )
{
	int xp = x - 'a' + 1;

	for(int i=0; i<5; i++)
	{
		if(xp < vogPos[i])
		{
			if( abs(xp - vogPos[i]) < abs(xp - vogPos[i - 1]))
			return alfa[vogPos[i]];
			else return alfa[vogPos[i - 1]];
		}
		else if(xp > 21)
		{
			return 'u';
		}
	}
	

	return 'a';
}

int main(){

	string o, c = ""; 
	cin>>o;

	for(int i=0; i<o.length(); i++)
	{
		c += o[i];

		if(o[i] == 'a' || o[i] == 'e' || o[i] == 'i' || o[i] == 'o' || o[i] == 'u')
		continue;

		c += vogalMaisProxima(o[i]);

		if(o[i] == 'z')
		{
			c += 'z';
			continue;
		}
		if(o[i] == 'x')
		{
			c += 'z';
			continue;
		}//°_° Serio isso OBI??? Meia hora me batendo pq o "alfabeto" de vcs não tem w nem y?!?!!!!?!
		

		if(o[i]+1 == 'a' || o[i]+1 == 'e' || o[i]+1 == 'i' || o[i]+1 == 'o' || o[i]+1 == 'u')
			c += o[i] + 2;
		else c += o[i] + 1;
	}

	cout<<c<<endl;

	return 0;	
}
