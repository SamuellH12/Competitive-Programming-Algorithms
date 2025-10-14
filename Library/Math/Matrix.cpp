#include <bits/stdc++.h>
using namespace std;

template<typename T> struct Matrix {
	vector<vector<T>> mat;
	int n, m;

	Matrix(int N, int M=0) : n(N), m(M?M:N){ mat.assign(n, m); }

	Matrix operator* (const Matrix &a, const Matrix &b) const {
		assert(a.m == b.n);
		Matrix ans(a.n, b.m);
		for(int i=0; i<a.n; i++)
			for(int j=0; j<b.m; j++)
				for(int k=0; k<a.m; k++)
					ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
		return ans;
	}
};
