#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

//questão de Busca Binária
//Vídeo aula sobre -> https://youtu.be/dYt4O_U3AUo

int main(){
	int n; 		cin >> n;
	int a, d; 	cin >> a >> d;

	vector<int> lista (n);

	for(int i=0, x; i<n; i++){
		cin >> x;
		lista[i] = abs(x - a);			//calcula a distância para a casa
	}

	sort(lista.begin(), lista.end());	//ordena as distâncias


	//Busca binária
	
	int esq=0, dir=n-1, meio, resp = -1;  //obs: resp= 1 pq se não encontrar nenhuma casa a resp vai ser -1+1 = 0
	while(esq <= dir)
	{
		meio = (esq+dir)/2;

		if( lista[meio] <= d )
		{
			esq = meio + 1;
			resp=meio;
		}
		else dir = meio - 1;
	}

	cout << resp + 1 << endl;

	return 0;	
}
