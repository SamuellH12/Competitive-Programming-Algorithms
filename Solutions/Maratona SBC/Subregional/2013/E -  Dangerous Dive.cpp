#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	if(n == m){
		cout << "*\n";
		return 0;
	}

    vector<bool> p(n+1, false);

	for(int i=0, x; i<m; i++){
		cin >> x;
		p[x] = 1;
	}

	for(int i=1; i<=n; i++)
		if(!p[i]) 
            cout << i << " ";
	
    cout << "\n";
	
	return 0;	
}
