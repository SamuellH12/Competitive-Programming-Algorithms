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

	int n, l;
	cin >> n >> l;

	vector<int> resp (n+1, 0);
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > fila;


	for(int i=1; i<=n; i++) fila.push({0, i});


	for(int i=0, x; i<l; i++)
	{
		cin >> x;

		auto atendente = fila.top();
		fila.pop();

		resp[atendente.second]++;
		atendente.first += x;

		fila.push(atendente);
	}

	
	for(int i=1; i<=n; i++)
		cout << i << " " << resp[i] << endl;
	
	
	return 0;	
}
