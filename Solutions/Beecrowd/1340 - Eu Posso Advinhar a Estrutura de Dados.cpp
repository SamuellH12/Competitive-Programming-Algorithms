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

	int n;

	while(cin >> n){

		bool ehfila = true, ehpilha = true, ehpriori = true;

		queue<int> fila;
		stack<int> pilha;
		priority_queue<int> priori;


		int o, x;

		while(n--)
		{
			cin >> o >> x;

			if(o == 1){
				fila.push(x);
				pilha.push(x);
				priori.push(x);
			}
			else
			{
				if(fila.front() != x) ehfila   = false;
				if(pilha.top()  != x) ehpilha  = false;
				if(priori.top() != x) ehpriori = false;

				fila.pop();
				pilha.pop();
				priori.pop();
			}

		}


		if(!ehfila && !ehpilha && !ehpriori) cout << "impossible" << endl;
		else
		if( ehfila && !ehpilha && !ehpriori) cout << "queue" << endl;
		else
		if(!ehfila &&  ehpilha && !ehpriori) cout << "stack" << endl;
		else
		if(!ehfila && !ehpilha &&  ehpriori) cout << "priority queue" << endl;
		else 
			cout << "not sure" << endl;



	}

	
	
	return 0;	
}
