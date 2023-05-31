#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int>& nums)
{
	vector<int> lis;

	for(auto x : nums)
	{
		auto it = lower_bound(lis.begin(), lis.end(), x);

		if(it == lis.end()) lis.push_back(x);
		else *it = x;
	}

	return (int) lis.size();
}


int main(){
	//sequence reading
	int n; cin >> n;
	vector<int> num (n);
	for(auto &x : num) cin >> x;


	cout << LIS(num) << endl;


	return 0;	
}

/****************************

LIS - Longest Increasing Subsequence

Complexity: O(N Log N)

* For ICREASING sequence, use lower_bound()
* For NON DECREASING sequence, use upper_bound()

To recover the answer, add an array that holds 
the index of the added element. (Replace and add 
indexes the same way you do with the LIS)

*****************************/