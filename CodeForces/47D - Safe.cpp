#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define ll long long
//https://codeforces.com/problemset/problem/47/D

int n, m;
pair<string, int> cod [15];
ll resp = 0;


inline void solve(int i)
{	
	//se i == n e todos tiverem com a exata quantidade de erros e acerto, resp++;
	if(i == n){
		bool ok = true;

		for(int j=0; j<m; j++)
			if(cod[j].second != 0)
				ok = false;

		if(ok) resp++;
		return;
	}


	//posso considerar essa posicao 0?
	bool ok = true;
	for(int j=0; j<m; j++)
		if(cod[j].first[i] == '1')
		{
			cod[j].second--;
			if(cod[j].second < 0) ok = false;
		} 
	

	if(ok) solve(i+1);
	

	//posso considerar 1?
	ok = true;
	for(int j=0; j<m; j++)
	{
		if(cod[j].first[i] == '1')
			cod[j].second++; 		//recupero a resp do 1
		else 
		{
			cod[j].second--;
			if(cod[j].second < 0) ok = false;
		}
	}


	if(ok)	solve(i+1);
	

	//recupera o array original
	for(int j=0; j<m; j++)
		if(cod[j].first[i] == '0')
			cod[j].second++; 		//recupero a resp do 0

}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	string s;
	for(int i=0, x; i<m; i++){
		cin >> s >> x;
		cod[i] = {s, x};
	}

	solve(0);

	cout << resp << endl;

	return 0;
}
