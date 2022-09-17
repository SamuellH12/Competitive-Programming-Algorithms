#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;


int main(){
	int n, m;
	cin >> n >> m;

	vi lista (min(n, 10000));
	for(int i=1; i<=min(n, 10000); i++) 
		lista[i-1] = i;


	int t [m];
	for(int i=0; i<m; i++)
		cin >> t[i];


	int tam = lista.size();	
	for(int i=m-1; i>=0; i--)
	{	
		for(int e=0; e<tam; e++)
			lista[e] += (lista[e]-1)/(t[i]-1);

		while(lista[tam-1] > n) tam--;
	}


	for(int i=0; i<tam && i < 10000; i++) 
		cout << lista[i] << endl;
	
	return 0;	
}

/*

uhmmm, depois de pensar sobre essa solução (do noic, aliás (*^w^) ) acho que comecei a 
entender. É um processo cumulativo, da seguinte maneira:

Vamos primeiro supor apenas um m=1 e depois progredimos o raciocínio;
Digamos que tenho um t=3, ou seja, quero remover todos os números das posições múltiplas de 3
Então tenho 1 2 3 4 5 6 7 8 9 10 e quero só 1 2 4 5 7 8 10, ou seja, três números foram removidos aqui
Pense assim agora, quantas casas o 1 teve de se descolcar? nenhuma, certo? Ok, e o 2? nenhuma tb!
Mas o 4 sim, o 4 teve de "voltar" uma casa! OU, também podemos pensar que o 3 teve de se aumentar em 1 pra virar 4!!!!
E esse é o pensamento. Ok, mas como o 3 teve de ser acrescido de 1, todos os próximos tb precisarão ser,
isso inclui o 4, que +1 será 5. Mas o 5, se adicionarmos +1 nele ele então se tornaria 6, o que não queremos que aconteça
Então o 5 precisa ser acrescido de 2 ao invés, e todos os próximos números tb. O 5 vira 7 e o 6 vira 8. Mas esbarramos
no mesmo problema de novo, se adicionarmos 7+2 teremos 9, que é múltiplo de 3, e não queremos isso,
então adicionamos +3 ao 7 e temos então 10! Ao 8 adicionamos +3 tb, e agora temos 11! Mas espera! 11 já passou de N!!! 
Então vamos ignorar os números maiores que n, pq eles claramente não fazer parte de nossa resposta.
Agora temos a seguinte sequência: 1 2 4 5 7 8 10 !!! O que é exatamente o que queríamos!!!
Mas vamos fazer uma nova observação aqui agora, qual foi a sequência de soma que tivemos?
0 0 1 1 2 2 3 3 [...]
Espera... Talvez haja um padrão aqui!!!

Para verificarmos a existência desse suposto padrão, vamos testar outro caso, em que t=5
Então temos 1 2 3 4 5 6 7 8 9 10 e queremos 1 2 3 4 6 7 8 9
Certo, então até o 4 a soma é simplesmente 0, depois, a partir do 5, temos de pular um número, e isso se acumula para os próximos
Então somamos +1 até chegar em 9, quando percebemos que 9+1 é 10 e não queremos 10, então agora temos 9+2, e seguimos adicionando +2
É claro que 11 já é maior que 10, então ignoramos ele na resposta, mas vejamos novamente o padrão da soma
0 0 0 0 1 1 1 1 2 2 2 2
Uhmmm, talvez realmente tenhamos um padrão aqui!

Observe que quando t=3 a cada 2 números aumentamos nossa soma, quando t=5 amentamos a cada 4 números. E se você testar
isso para qualquer número perceberá que nossa soma incrementa em 1 a cada t-1 números! Uhmm, como podemos saber que é
hora de trocar sem necessariamente usar um contador de posições? :thinking_emoji:
Uma divisão! Qual o resultado da divisão de 3/4 ?  0 !!! Então vamos colocar 3+0; E 5/4 ? 1, então 5+1! Resolvemos uma 
parte do enigma. Mas observe, 4/4 = 1, mas não queremos 4+1, queremos 4+0 ainda! Isso pode ser contornado assim: 
(4-1)/4 = 1  observe que para os demais números, como (5-1)/4 = 1 , tudo continua funcionando normalmente!

Bem, é dessa observação que temos a fórmula: l[i] += (l[i]-1) / (t-1);  (Lembrando que isso para M=1)


Então resolvemos o problema para M=1! Mas, e para os demais M's? Bem, teremos de fazer uma nova observação aqui
Imagine que temos m=2 e t=[2, 3]
Queremos algo como essa sequência de ações:
1 2 3 4 5 6 7 8 9 10
1   3   5   7   9 
1   3       7   9
Certo, vamos tentar fazer isso com nossa fórmula encontrada na explicação anterior! Mas agora fazendo repetindo para cada t
1+0 2+1 3+2 4+3 5+4 6+5 7+6 8+7 [...]
 1   3   5   7   9  11  13  15  [...]

Ok, até agora tudo como o esperado, vamos adicionar o t=3 agora! [lembrando que estamos fazendo (l[i]-1)/(t-1), portando (7-1)/(3-1) = 3]
1+0 3+1 5+2 7+3 9+4 
 1   4   7  10  13

Bem... Não era exatamente isso que queríamos. Mas o que aconteceu???
Então, o t=3 foi formado por cima da lista do t=2, e pelo que vimos isso não era o pretendido,
o processamento feito com o t=2 fez com que o t=3 "corrompesse" seu resultado. Mas temos de 
fazer o processamente de todos os t's!!! Como podemos fazer isso se ao colocar nessa ordem
não obtemos nosso resultado???

Certo, mas agora vamos pensar em algo, talvez, meio estranho: Se o t=3 não deve ser feito por cima
do t=2, talvez devêssemos fazer o processo contrário. Primeiro vamos executar para t=3 e depois para t=2:
t=3:
1+0 2+0 3+1 4+1 5+2 6+2 7+3 8+3 9+4 10+4
 1   2   4   5   7   8  10  11  13  14

Ok, até agora temos um resultado esperado, vamos agora fazer o processamento pra t=2 por cima dessa nova lista:
1+0 2+1 4+3 5+4 7+8 8+9 10+11
 1   3   7   9  15  17  21

/(°O°)\ Funcionou!!!! Por algum motivo obtemos a resposta correta ao realizar esse "pensamento reverso".
Mas por quê funcionou???

Bem, imagine de outra forma, pensemos que temos nossa resposta final e queremos retornar para a situação inicial
Qual seria o primeiro passo?
Bem, re-adicionar todos os números removidos no passo anterior(assumindo a ordem direta de remoção, conforme o enunciado),
ou seja, adicionarmos todos os números removidos no t=3, depois retornamos mais um passo e então adicionamos todos os 
números que foram removidos pelo passo em que t=2; Com isso temos de volta nossa lista! Tá, mas o que uma coisa tem a ver 
com a outra?
Como estamos processando os números com base nestes em si (sua posição inicial na lista), e não em sua posição atual, 
se somarmos os elementos conforme o t=2 e depois fizermos a soma do t=3 estamos fazendo o oposto! Isso porque nossa
solução já assume que está fazendo uma regressão, ou seja, nosso cálculo só faz sentido se quando calcularmos a "remoção"
do t=2 já tivermos calculado do t=3; Assim, se calcularmos o t=3 depois podemos, na verdade, re-adicionar à nossa lista
números que antes foram removidos pelo t=2, como visto, e nesse caso precisaríamos passar o t=2 de novo para revomermos
esses números, o que corresponderia a ter feito o processo ao contrário, como fizemos.

Ok, não sei se a explicação dessa parte final ficou convincente de porque isso funciona e deve ser feito ao contrário,
mas recomendo que leia a explicação da resolução no site oficial da NOIC e tenta entender por si mesma(o) o que 
acontece aqui: 
# https://noic.com.br/materiais-informatica/comentario/obi-2021/fase3-p2/ #


Exemplo:
-----------------------+--------------------------------------------------
 1 2 3 4 5 6 7 8 9 10  |   1 2 3 4 5 6 7 8 9 10  
 	t2                 |t3 1+(1-1)/(3-1) 2+(2-1)/(3-1) 3+(3-1)/(3-1) [...]
  1 x 3 x 5 x 7 x 9 x  |   1+0 2+0 3+1 4+1 5+2 6+2 7+3 8+3 9+4 10+4
-----------------------+--------------------------------------------------
  1 3 5 7 9   	       |   1 2 4 5 7 8 10 ][ 11 13 14
     t3	               |t2 1+0/(2-1) 2+1/(2-1) 4+3/1 5+4/1 [...]
  1 3 x 7 9            |   1+0 2+1 4+3 5+4 7+8 8+9 10+11
-----------------------+--------------------------------------------------
R  1 3 7 9             | R  1 5 7 9 15 17 21
-----------------------+--------------------------------------------------


( Sério que alguém conseguiu pensar nisso durante a prova??? )
*/