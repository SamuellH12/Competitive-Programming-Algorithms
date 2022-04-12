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

string frase;

int main(){

	//cout<< (int)'A' << " " << (int)'Z' << " - " << (int)'a' << " " << (int)'z';

	optimize;

	while( getline(cin, frase) && frase != "*")
	{
		bool tauto = true;
		char prim = frase[0];
		char Prim = (prim >= 65 && prim <= 90 ? prim + 32 : prim - 32);
		
		for(int i=0; i<frase.length() - 1; i++)
		{
			while(frase[i] != ' ' && i<frase.length() - 1) i++;

			if(i >= frase.length() - 1) break;

			if(frase[i+1] != prim && frase[i+1] != Prim && frase[i+1] != ' ')
			{
				tauto = false;
				break;
			}

		}

		cout<<(tauto ? "Y" : "N")<<endl;
	}

	return 0;	
}

//https://www.beecrowd.com.br/judge/pt/problems/view/1140