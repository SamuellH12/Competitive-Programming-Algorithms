#include "GaussElimin.cpp" //LATEX_IGNORED_LINE
#include <bits/stdc++.h>
using namespace std;

template<typename T> struct Matrix {
	vector<vector<T>> mat;
	int n, m;

	Matrix(int N, int M=0) : n(N), m(M?M:N){ mat.assign(n, vector<T>(m, 0)); }

	friend Matrix operator* (const Matrix &a, const Matrix &b){
		assert(a.m == b.n);
		Matrix ans(a.n, b.m);
		for(int i=0; i<a.n; i++)
			for(int j=0; j<b.m; j++)
				for(int k=0; k<a.m; k++)
					ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
		return ans;
	}
};

template<typename T> Matrix<T> inverse(Matrix<T> mat){
	int n = mat.n; assert(n == mat.m); 
	Gauss<T> g(n+n);
	for(int i=0; i<n; i++){
		vector<T> line = mat.mat[i];
		line.resize(n+n, 0); line[n+i] = 1;
		g.addLine(line);
	}
	g.solve();
	for(int i=0; i<n; i++) 
		mat.mat[i] = {begin(g.mat[i])+n, end(g.mat[i])};
	return mat;
}