#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int>& nums){
	vector<int> lis;

	for(auto x : nums)
	{
		auto it = lower_bound(lis.begin(), lis.end(), x);

		if(it == lis.end()) lis.push_back(x);
		else *it = x;
	}

	return (int) lis.size();
}
/****************************
LIS - Longest Increasing Subsequence

Complexity: O(N Log N)
* For ICREASING sequence, use lower_bound()
* For NON DECREASING sequence, use upper_bound()
*****************************/