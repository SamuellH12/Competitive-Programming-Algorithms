#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e3 + 5;
using namespace std;

// 2023 Argentinian Programming Tournament (TAP)
// https://codeforces.com/gym/104603/problem/H

int n;
pii coor[MAXN*MAXN];
int mxcol[MAXN], mxlin[MAXN];

int main(){
	optimize;
	
	cin >> n;

	for(int i=1; i<=n; i++)
		for(int j=1, x; j<=n; j++)
			cin >> x, coor[x] = {i, j};

		

	int ans = -1;

	// eu começo olhando pro maior valor de todos e vou diminuindo
	for(int i=n*n; i>0; i--)
	{
		auto [x, y] = coor[i];

		// se eu tô no quadradinho X Y
		// eu posso escolher virar pra uma linha saindo de uma coluna
		// ou virar pra uma coluna saindo de uma linha

		int htov = mxcol[x] + 1;	//eu tô vindo horizontalmente, então eu pego a melhor resp dessa coluna em que eu tô virando
		int vtoh = mxlin[y] + 1;	//eu tô vindo verticalmente, então eu pego a melhor resp dessa linha em que eu tô virando

		// agora eu atualizo os valores da minha coluna e linha com os valores que eu consigo virando na minha linha e coluna
		mxcol[x] = max(mxcol[x], vtoh);		// atenção que a ideia é ir invertendo, pq é a ideia de simular a cada passo virar para um lado diferente
		mxlin[y] = max(mxlin[y], htov);

		ans = max({ans, mxcol[x], mxlin[y]});
	}


	cout << ans << endl;

	return 0;	
}




/*
Pra Debugar

// int memo[MAXN][MAXN][2];

		// memo[x][y][0] = htov;
		// memo[x][y][1] = vtoh;


	// cerr << "L\\C|";
	// for(int i=1; i<=n; i++) cerr << mxcol[i] << "   ";
	// cerr << endl;

	// for(int i=1; i<=n; i++){
	// 	cerr << mxlin[i] << "| ";
		
	// 	for(int j=1; j<=n; j++) cerr << memo[i][j][0] << "/" << memo[i][j][1] << " ";
		
	// 	cerr << endl;
	// }




	for(int i=n*n; i>0; i--)
	{
		auto [x, y] = coor[i];

		mxcol[x] = max(mxcol[x], mxlin[y] + 1);
		mxlin[y] = max(mxlin[y], mxcol[x] + 1);

		ans = max({ans, mxcol[x], mxlin[y]});
	}

*/