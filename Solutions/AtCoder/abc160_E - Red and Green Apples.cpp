#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define all(x) x.begin(), x.end()

//https://vjudge.net/contest/539684#problem/E
//https://atcoder.jp/contests/abc160/tasks/abc160_e

//guloso
int main(){

    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vi red (a), green(b), color(c);

    for(int i=0, x; i<a; i++){
        cin >> x;
        red[i] = x;
    }
    for(int i=0, x; i<b; i++){
        cin >> x;
        green[i] = x;
    }
    for(int i=0, x; i<c; i++){
        cin >> x;
        color[i] = x;
    }
    //ordena as maçãs pelo maior valor
    sort(all(red),   greater<int>());
    sort(all(green), greater<int>());
    sort(all(color), greater<int>());

    priority_queue<int, vi, greater<int>> fila;
    ll sum = 0;

    //pega todas as maçãs red e green que eu puder e coloca elas na priority_queue
    for(int i=0; i<x; i++){
        sum += red[i];
        fila.push(red[i]);
    }
    for(int i=0; i<y; i++){
        sum += green[i];
        fila.push(green[i]);
    }

    //A priority já vai ordenar e nos devolver no top o menor valor 
    //agora é só substituir esse valor por uma sem cor de tamanho maior
    //acontece que, se a que removemos for uma verde ela vai virar verde
    //e se for vermelha vira vermelha e assim não precisamos nos preucupar 
    //mais com isso e pronto!
    int i=0;
    while( i < c && fila.top()<color[i] )
    {
        sum -= fila.top();
        sum += color[i];
        fila.pop();
        i++;
    }
        
    cout << sum << endl;

    return 0;
}