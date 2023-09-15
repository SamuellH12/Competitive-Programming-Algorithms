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

// Codeforces Round 479 (Div. 3)
// https://codeforces.com/contest/977/problem/F

int main(){
	optimize;

	int n; 
	cin >> n;

	vi nums(n);
	for(auto &x : nums) cin >> x;

	int ans = 0, val = -1;
	map<int, int> len;


	for(int i=0; i<n; i++)
	{
		int x = nums[i];

		len[x] = max(len[x], len[x-1] + 1);

		if(len[x] > ans){
			ans = len[x];
			val = x;
		}
	}


	vi ids;

	for(int i=n-1; i>=0 ; i--)
		if(nums[i] == val)
		{
			ids.push_back(i);
			val--;
		}

	reverse(ALL(ids));


	cout << ans << endl;
	for(auto x : ids) cout << x+1 << " "; cout << endl;
	
	
	return 0;	
}
