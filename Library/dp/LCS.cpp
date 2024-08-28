#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5*1e3 + 5;
int memo[MAXN][MAXN];

string s, t;

inline int LCS(int i, int j){
	if(i == s.size() || j == t.size()) return 0;
	if(memo[i][j] != -1) return memo[i][j];

	if(s[i] == t[j]) return memo[i][j] = 1 + LCS(i+1, j+1);

	return memo[i][j] = max(LCS(i+1, j), LCS(i, j+1));
}

int LCS_It(){	
	for(int i=s.size()-1; i>=0; i--)
		for(int j=t.size()-1; j>=0; j--)
			if(s[i] == t[j]) 
				memo[i][j] = 1 + memo[i+1][j+1];
			else 
				memo[i][j] = max( memo[i+1][j], memo[i][j+1] );

	return memo[0][0];
}

string RecoverLCS(int i, int j){
	if(i == s.size() || j == t.size()) return "";

	if(s[i] == t[j]) return s[i] + RecoverLCS(i+1, j+1);

	if(memo[i+1][j] > memo[i][j+1]) return RecoverLCS(i+1, j);

	return RecoverLCS(i, j+1);
}
/****************************
LCS - Longest Common Subsequence

Complexity: O(N^2)

* Recursive:
memset(memo, -1, sizeof memo);
LCS(0, 0);

* Iterative:
LCS_It();

* RecoverLCS
  Complexity: O(N)
  Recover one of all the possible LCS
*****************************/