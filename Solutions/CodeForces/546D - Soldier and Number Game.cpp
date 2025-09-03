#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int MAXN = 5e6 + 4;
ll ps[MAXN];

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for(int i=2; i<MAXN; i++) if(!ps[i]){
		ps[i]++;
		for(int j=i+i, k; j<MAXN; j+=i){
			k = j;
			do {
				ps[j]++;
				k/=i;
			} while(k%i == 0); 
		}
	}

	// for(int i=0; i<20; i++) cerr << ps[i] << " "; cerr << endl;
	for(int i=1; i<MAXN; i++) ps[i] += ps[i-1];

	int tt; cin >> tt;
	while(tt--)
	{
		int a, b;
		cin >> a >> b;


		cout << ps[a] - ps[b] << endl;
	}
	
	return 0;	
}