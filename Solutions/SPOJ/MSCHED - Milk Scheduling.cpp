#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

//https://www.spoj.com/problems/MSCHED/en/

int main(){

    int n; cin >> n;

    //time gallon
    vii cow (n);

    for(int i=0, g, d; i<n; i++){
        cin >> g >> d;
        cow[i] = {d, g};
    }

    sort(all(cow)); //ordeno pela deadline

    ll sum = 0;
    priority_queue<int, vi, greater<int>> fila; //armazenar quais e quantos valores estou usando

    for(int i=0; i<n; i++){
        
        sum += cow[i].second;  //adiciono as vacas com a menor deadline primeiro
        fila.push(cow[i].second); //coloco o valor na fila pra comparar depois

        //se há mais elementos na fila que o tamanho da deadline removo os de menor valor para ficar com espaço pros maiores
        //nesse caso, como se esta colocando as vacas sempre o mais cedo possível o tamanho vai ser igual ao tempo
        while(fila.size() > cow[i].first){ 
            sum -= fila.top();
            fila.pop();
        }

    }

    cout << sum << endl;

    return 0;
}
