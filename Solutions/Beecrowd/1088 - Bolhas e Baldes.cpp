#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define ll long long
#define sc second
#define ft first
using namespace std;

int merge( vector <int> & ord ){
    if(ord.size() <= 1) return 0;

    vector <int> esq, dir;
    int inversoes = 0;

    for(int i=0; i<ord.size(); i++){
        if(i < ord.size() / 2) esq.push_back(ord[i]);
        else                   dir.push_back(ord[i]);
    }

    inversoes += merge(esq);
    inversoes += merge(dir);

    for(int i=0, e=0, d=0; i<ord.size(); i++){
        if     (e == esq.size())    ord[i] = dir[d++];
        else if(d == dir.size())    ord[i] = esq[e++]; 
        else if(esq[e] <= dir[d])   ord[i] = esq[e++];
        else   {                    ord[i] = dir[d++];  inversoes += esq.size() - e; }
    }

    return inversoes;
}

int main(){

    optimize;
	
    int n;

    while(cin>>n && n != 0){
        vector <int> lista;
        
        for(int i=0; i<n; i++){
            int aux; cin>>aux;
            lista.push_back(aux);
        }
        
        int invers = merge(lista);
        
        cout<< ( invers%2!=0 ? "Marcelo" : "Carlos")<<endl;

    }

	return 0;	
}