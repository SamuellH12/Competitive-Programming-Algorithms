#include <bits/stdc++.h>
using namespace std;

vector<int> Zfunction(string &s){ // O(N)
	int n = s.size();
	vector<int> z (n, 0);

	for(int i=1, l=0, r=0; i<n;  i++){
		if(i <= r) z[i] = min(z[i-l], r-i+1);
		
		while(z[i] + i < n && s[z[i]] == s[i+z[i]]) z[i]++;

		if(r < i+z[i]-1) l = i, r = i+z[i]-1;
	}

	return z;
}