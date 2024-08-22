#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;



int main(){
	optimize;
	string s; 
	cin >> s;

	int ans = 0, at = 0;
	char lst = 'z';

	for(auto c : s)
	{	
		if(c != lst) at = 0;
		lst = c;
		at++;
		ans = max(ans, at);
	}

	cout << ans << endl;

	return 0;	
}
