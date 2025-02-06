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



int main(){

	int n;
	cin >> n;

	while(n--){

		string exp;
		cin >> exp;

		stack<char> pilha;
		bool ok = true;

		for(auto c : exp)
		{
			if(c == '(' || c == '{' || c == '[')	
				pilha.push(c);
			else 
			if(!pilha.empty())
			{
				if(     c == ')' && pilha.top() == '(') pilha.pop();
				else if(c == '}' && pilha.top() == '{') pilha.pop();
				else if(c == ']' && pilha.top() == '[') pilha.pop();
				else 
				{
					ok = false;
					break;
				}
			}
			else
			{
				ok = false;
				break;
			}

		}

		if(!pilha.empty()) ok = false;

		cout << ( ok ? "S" : "N" ) << endl;
	}
	
	
	return 0;	
}
