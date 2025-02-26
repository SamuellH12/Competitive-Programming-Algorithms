#include <bits/stdc++.h>
using namespace std;

void solve(int i){
	if(i == 0) return;

	solve(i-1);
	putchar('A'+i-1);
	solve(i-1);
}


int main(){
	int n; cin >> n;
	solve(n);
	return 0;	
}
