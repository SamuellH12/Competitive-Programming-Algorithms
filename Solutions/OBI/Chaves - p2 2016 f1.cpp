#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;



int main(){
	int l; cin >> l;

	string cod = "";

	while(l-- >= 0)
	{
		string gt;	
		getline(cin, gt);

		cod += gt;
	}

	stack<int> pilha;

	for(int i=0; i<cod.length(); i++)
	{
		if(cod[i] == '{') pilha.push(1);
		else
		if(cod[i] == '}')
			if(pilha.empty()){
				cout<<"N"<<endl;
				return 0;
			}
			else pilha.pop();
	}

	if(pilha.empty()) cout << 'S' << endl;
	else cout << "N" << endl;
	
	return 0;	
}
