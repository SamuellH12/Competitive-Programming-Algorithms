#include <bits/stdc++.h>
using namespace std;

//Essa questão usa a idea de EVENTOS
//não tenho nenhum material sobre, mas explico abaixo como funciona :)

bool comecou = false;
bool terminou = true;

int main(){
	int n; cin >> n;

	vector< pair<int, bool> > calendario; 	//int: dia | bool: tipo

	for(int i=0, c, t; i<n; i++)
	{
		cin >> c >> t;
		calendario.push_back({c, comecou});
		calendario.push_back({c+t-1, terminou});
	}

	sort( calendario.begin(), calendario.end() ); 

	int cont = 0, resp=0; 
	for(auto e : calendario)
	{
		if(e.second == comecou) cont++;
		else cont--;
		resp = max(cont, resp);
	}

	cout << resp << endl;
	
	return 0;	
}

/*
++===============++
|| +++EVENTOS+++ ||
++===============++

=======
#Ideia#
=======

	Quando alguma coisa nova ou diferente acontece chamamos de evento. Na programação podemos
abstrair a ideia de eventos para muitos problemas, como este. 

	Imagine sua resposta, o único momento que ela pode mudar é quando Carol começa ou termina
de ler um livro, assim chamamos esses momentos em que algo novo acontece de evento!

	Neste caso temos DOIS tipos de eventos, um de INÍCIO, quando Carol *começa* a ler um livro,
e um evento de FIM, quando Carol *termina* o livro. Assim, sempre que o evento é de início a 
quantidade atual de livros que ela está lendo aumenta em 1, quando o evento é de fim essa 
quantidade decresce em 1. Então a nossa resposta é simplesmente pegar o dia com a maior quantidade
de livros sendo lidos.


===============
#Implementação#
===============

	Quais as informações importantes para um evento? O dia em que ele ocorre e o tipo de evento, certo?
nesse caso podemos representar um evento com um	||  pair<int, bool>   ||, em que o int representa o dia
e o booleano o tipo do evento, false(0) se for um evento de início ou true(1) se for um evento de fim.

	Ok, mas precisamos de mais de um evento, então, como podemos armazenar vários elemento? Com um vector!
assim criamos nosso vector de eventos assim: ||   vector< pair<int, bool> > listaDeEventos;   ||

	Em seguida, precisaremos analizar os eventos pela ordem em que ocorreram, pra isso vamos ordenar nosso
vetor com um sort(), passamos o início e o fim do nosso vetor e temos isso: 
||  sort(listaDeEventos.begin(), listaDeEventos.end());   || assim ordenaremos ele pelo dia e em caso de empate
pelo tipo do evento. [Vide "IMPORTANTE" no fim do texto]

	Nosso algoritmo está quase pronto! Agora só precisamos olhar nossos eventos, isso pode ser feito com um
||for|| comum ou com um || for(auto evento : listaDeEventos ) ||, que não possui  diferenças do for normal, é
apenas mais prático mesmo. Além disso precisamos guardar a quantidades de livros que estão sendo lidos atualmente
em uma variável, vamos chamá-la de "contador" ou || cont = 0; ||. Agora só precisamos verificar o tipo do nosso 
evento, se for um evento de início aumentamos nosso contador em 1, || cont++; ||, caso contrário decrescemos em 1,
|| cont--; ||. Para guardar nossa resposta podemos simplesmente fazer um || resp = max(resp, cont); ||, que assim
sempre iremos pegar o maior valor possível, ou seja, o dia em que Carol leu mais livros!!!

	Para finalizar o algoritmo imprimimos nossa respota || cout << resp << endl; ||.

--------------------------------------------------------------------------------------------
IMPORTANTE: começou(0) precisa sem menor que terminou (1), pra que se ordene corretamente.
Pois, se ela começou a ler um livro e terminou outro no mesmo dia, ela leu 2 livros, mas
se processarmos ao contrário, ela temina um livro e começa outro e a resp seria apenas 1.
--------------------------------------------------------------------------------------------


\(°W°)/ Bons estudos!
*/