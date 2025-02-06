#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
int main() {
    optimize;

    int n, m; cin>>n>>m;

    unordered_map <int, int> qtdOp;
    queue<int> filaDeN;

    filaDeN.push(n);
    qtdOp[n] = 0;

    int qtdMinDeOp = 0;

    while (!filaDeN.empty()){
        int analizando = filaDeN.front();
        filaDeN.pop();

        if(analizando == m){ qtdMinDeOp = qtdOp[analizando]; break;}

        if(!qtdOp.count( 2 * analizando) ){
            qtdOp[analizando * 2] = qtdOp[analizando] + 1;
            filaDeN.push( analizando * 2);
        }

        if(!qtdOp.count(3 * analizando) ){
            qtdOp[analizando * 3] = qtdOp[analizando] + 1;
            filaDeN.push( analizando * 3);
        } 

        if(!qtdOp.count(analizando/2) ){
            qtdOp[analizando/2] = qtdOp[analizando] + 1;
            filaDeN.push( analizando / 2);
        }

        if(!qtdOp.count(analizando/3)){
            qtdOp[analizando/3] = qtdOp[analizando] + 1;
            filaDeN.push( analizando / 3);
        }

        if(!qtdOp.count(analizando + 7)){
            qtdOp[analizando + 7] = qtdOp[analizando] + 1;
            filaDeN.push(analizando + 7);
        }

        if(!qtdOp.count(analizando - 7)){
            qtdOp[analizando - 7] = qtdOp[analizando] + 1;
            filaDeN.push(analizando - 7);
        }

    }

    cout<<qtdMinDeOp<<endl;
    
    return (0);
}

/*

    Vou tentar explicar aqui o que eu entendi do funcionamento do código depois de "inspirar" no
código do Carlos ( miiintira! foi quase copiado mesmo, mas acho que entendi, então tá bom ).

    Então, as duas variaveis principais são o map e o queue, ou fila. O map vai "mapear" os valores
achados a partir das operacoes de um lado e do outro armazenar quantos passos foram necesários
pra chegar lá. A fila já vai guardar os próximos vaslores a serem analizados, os valores que já sofreram
alterações que depois vão ser alterados de novo.


    A execução propriamente dita vai começar em seguida, o primeiro valor que foi mapeado (0 operacoes) e agora
vai ser manipulado é o proprio N. Depois vão sendo analisados os "produtos" de N. O processo funciana assim:
se o valor analizado já modificado com uma outra operação NÂO estiver no map, ele é edicionado ao mapa , e sua 
qtd de operacoes se torna igual a do numero que o originou + 1, que é a operção que ele acabou de sofrer. Esse
processo é repetido pra cada uma das operações. Sempre no começo daquele processamento é verificado se o número
que esta sendo analizado é igual ao M, se for: BINGO! achamos a qtd de operações para transformar N em M, basta 
acessar a posição no mapa de M e imprimir a qtd de operações.

    Se não tiver ficado clara a explicação, pode me perguntar novamente que eu tento explicar melhor, se bem que 
você já sabe disso, já que, se esta lendo isso, é professor, o Carlos ou outro professor. Se for o Carlos, desculpe
escrever o código praticamente igual, posso dizer que foi para fins de aprendizagem, acredito que consegui 
compreender a lógica por trás desse algorítimo, então, obrigado!!! :) 

*/