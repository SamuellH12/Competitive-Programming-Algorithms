#include <bits/stdc++.h>
#define endl "\n"
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
 
int main() {

    optimize;
    
    int n;   cin>>n;

    int alt[n], maxi = 0, maiorI=0;
    
    // TRECHO DE CÓDIGO QUE ENCONTREI PESQUISANDO SOLUÇÕES: O(N)
    
    for(int i=0; i<n; i++){

        cin>>alt[i];

        maxi = max(maxi, maiorI + alt[i] + i);

        maiorI = max(maiorI, alt[i] - i);

    }

    
    cout<<maxi<<endl;
    
    return (0);

}



/* TRECHO ORIGIANL DO MEU CÓDIGO: O(N^2)
    +---------------------------------------------------+
    | É possível visualizar que a formula está correta, |
    | porém não esta sendo usada de forma otimizada, |  |
    | abaixo eu explico a diferença da otimização.   V  |
    +---------------------------------------------------+

    for(int i=0; i<n; i++) cin>>alt[i];

    for(int i=0; i<n; i++){
        for(int e=i+ 1; e<n; e++){

            int atual = alt[i] + alt[e] + e - i;
            
            if(atual > maxi) maxi = atual;

        }
    } 
    */

/*

Então, o meu erro foi não perceber que, apesar de, sim, a distância ser bastante relativa
a maior distancia entre o |início e um ponto E| pode ser menor que a distância entre
esse mesmo |ponto E e um ponto I < E e > o inicio| , então realmente não faz sentido eu 
testar todas as possibilidades partindo do ponto 0 se assim que eu testar eu tb posso saber
se a |distância entre o predio 0 é um predio E | é menor ou maior que a
a | distância do predio E ao ponto E | ou seja, eu me pergunto: a ditancia do topo do ultimo prédio armazenado
pra cá é menor que a distância do topo do predio atual até o terrio? Se for, qual o sentido de eu
calcular o valor deste se os valores que eu vou conseguir com esse segundo são, obviamente, maiores?
Agora tb é necessario se atentar ao valor da responta que tem que ser armazenado em uma variável separada
e tambem só substituido se o novo valor for maior.

assim temos duas variáveis principais: 
    a = maior valor de     alt[i] - i
    b = maior valor de a + alt[e] + e
Sendo que I e E são a mesma variavel, só separei para não confundir,
pois nunca se deve comparar um prédio com ele mesmo, apenas com os que virão
em seguida.


Bom, então fica a dica:

    Da próxima vez, tente reestruturar a fórmula, 
agrupando os valores referentes a um mesmo ciclo for em uma variável e
os outros valores em outras variaveis, a partir desse ponto, verifique 
como você pode prosseguir simplificando o código, neste caso, removendo
dois for, o de leitura, pois os valores já são processados na ordem que 
são lidos, e um for interno de outro, pois não é necessario processar 
valores que serão, claramente, menores que o atual inúteis para a questão.

*/