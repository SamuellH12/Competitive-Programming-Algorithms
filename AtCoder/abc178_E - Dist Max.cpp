#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

//https://atcoder.jp/contests/abc178/tasks/abc178_e?lang=en

int main(){


	int n; cin >> n;

	int Ms = -INF,
	    ms =  INF, 
	    Md = -INF, 
	    md =  INF;


	for(int i=0, x, y; i<n; i++){
		cin >> x >> y;
		Ms = max(Ms, x+y);
		ms = min(ms, x+y);
		Md = max(Md, x-y);
		md = min(md, x-y);
	}

	cout << max( Md-md, Ms-ms ) << endl;

	return 0;
}


/*
------------------------------------------------------------------------
Ok, acho que agora entendi o pq isso funciona.
Pelo que peguei da ideia, como eu tô sempre somando dois 
valores absolutos na fórmula inicial \\ dist = |X-x| + |Y-y| \\
Isso significa que o valor de |X-x| = max(X-x, x-X), isso pq 
ambas as subtrações têm valor igual, mas com sinais opostos. 
O mesmo vale para o |Y-y|. Assim, se "soubermos" qual valor é
maior que qual, podemos "colocar eles" na ordem correta e o valor
vai estar sempre positivo. Mas não sabemos antes de comparar os 
dois pontos, então o que podemos fazer é testar as duas possibilidades
e a maior das duas será a correta, isso pelo motivo inicial.
Presumindo que X > x e Y > y, podemos chegar a essa fórmula
\\ X + Y - x - y \\, contudo pode ocorrer ainda um segundo caso, 
em que X > x mas Y < y, nesse caso a fórmula deveria ser:
\\X - x - y - Y \\, fazendo um agrupamente mais conveniente para 
o problema temos:

 X - x + Y - y  =>  X + Y - x - y  =>  (X+Y) - (x+y)
 X - x + y - Y  =>  X - Y - x + y  =>  (X-Y) - (x-y)

Então conseguimos as duas possíveis fórmulas, a diferença das 
somas e a diferença das diferenças. Como não sabemos qual caso
vamos usar, se X>x, Y>y ou se X>x, Y<y, podemos calcular então 
as duas possibilidades e guardar num vetor, por exemplo.

Mas isso ainda não resolve o problema da complexidade dessa 
solução, mas a segunda parte é bem mais intuitiva. Como a questão
pede a maior distância possível, podemos chegar a conclusão lógica 
de que esse nada mais é que o Máximo - mínimo, para os dois casos.
E isso podemos resolver com meras quatro variáveis! :)
------------------------------------------------------------------------
*/
