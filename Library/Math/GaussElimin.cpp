#include <bits/stdc++.h>
using namespace std;

template<typename T> struct Gauss {
	int n, m = 0;
	vector<vector<T>> mat;
	Gauss(int n) : n(n){}

	void addLine(vector<T> l = vector<T>()){
		l.resize(n, T(0));
		mat.push_back(l); m++;
	}
	void solve(){
		for(int c=0, i=0, g; c<n && i < m; c++, i+=!g){
			for(int j=i; j<m && mat[i][c] == T(0); j++)
				swap(mat[j], mat[i]);
			
			if(g = mat[i][c] == T(0)) continue;
			for(int j=n-1; j>=0; j--) mat[i][j] /= mat[i][c];

			for(int j=0; j<m; j++) if(i != j && mat[j][c] != T(0)){
				T alpha = mat[j][c];
				for(int k=i; k<n; k++) 
					mat[j][k] -= mat[i][k] * alpha;
			}
		}
	}
	int isValid(){
        int pivos = 0;
        for(int i=0, c; i<m; i++){
			for(c=0; c<n-2; c++) if(mat[i][c] != T(0)) break;
            if(mat[i][c] != T(0)){ pivos++;
                for(int j=c+1; j<n-1; j++) 
                    if(mat[i][j] != T(0))
                        pivos = -2*n;
            }
			else if(mat[i][n-1] != T(0)) return 0; // 0 = 1
		}
        return pivos == n-1 ? +1 : -1; // 1 - Solucao unica // 0 - Sem solucao // -1 - Infinitas solucoes
    }
	void printSolution(){ // OPTIONAL / FOR DEBUG
		for(int i=0, c; i<m; i++){
			for(c=0; c<n-2; c++) if(mat[i][c] != T(0)) break;
			if(mat[i][c] != T(0)) cout << "X" << c << " = ";
			else cout << "0  = ";
			for(int j=c+1; j<n-1; j++) if(mat[i][j] != T(0)) 
				cout << mat[i][j]*T(-1) << " * X" << j << "   +   ";
			cout << mat[i][n-1] << endl;
		}
	}
	void print(){ for(auto v : mat){ for(auto x:v) cout<<x<<"\t"; cout<<"\n"; } }
};


/*LATEX_DESC_BEGIN***************************
Eliminação Gaussiana - O(N*N*M)

Resolve um sistema de equacoes lineares, escalonando a matriz;

Entrada       || Saida        || interpretacao
1  4  6   80  || 1  0  0  76  || X0 = 76
2  0  6  140  || 0  1  0  4   || X1 = 4
1  2  12  60  || 0  0  1  -2  || X2 = -2

Entrada       || Saida        || interpretacao
1  4  6  18   || 1  4  0  -6  || X0 = -4 * X1  - 6
0  0  6  24   || 0  0  1   4  || X2 =  4
1  4  3   6   || 0  0  0   0  || 0  =  0

* Se 0 != 0, o sistema nao tem solucao
* Variaveis do lado direito da equacao tem valor livre
*****************************LATEX_DESC_END*/

// LATEX_IGNORED_BEGIN 
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	Gauss<double> g(n);

	for(int i=0; i<m; i++){
		g.addLine();
		for(auto &x : g.mat.back()) cin >> x;
	}

	g.print();
	cout << endl;

	g.solve();

	g.print();

	cout << endl;
	g.printSolution();
}
// LATEX_IGNORED_END