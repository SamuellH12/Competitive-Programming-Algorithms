#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 50010
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2021/f3/minhoca/
//Assunto: Diâmetro de árvores

int n;
vi grafo[MAXN];
pii resp;

void maxresp(int tam, int qtd)
{
	if(tam <  resp.first) return;
	if(tam == resp.first) resp.second += qtd;	//se for igual incremento a quantidade de vezes que ele aparece
	if(tam >  resp.first) resp = {tam, qtd};	//se o tam atual for maior que o guardado, troco
}

pii dfs(int u, int p)
{
	//pego a profundidade de todas as minhas subárvores
	vector<pii> sub; sub.push_back({0, 1});
	
	for(auto v : grafo[u]) 
		if(v != p) 
			sub.push_back(dfs(v, u));


	//defino a maior e a segunda maior profundidade (lembrando que tenho a profundidade e a qtd de ocorrências, pii)
	int fi=0, si=0;
	for(int i=0; i<sub.size(); i++)
		if(sub[i].first > sub[fi].first) si = fi, fi = i; else
		if(sub[i].first > sub[si].first) si = i;
	

	//junto todas as profundidades equivalentes a segunda maior num vetor auxiliar
	vector<pii> sec;
	for(auto x : sub) 
		if(x.first == sub[si].first) 
			sec.push_back(x);


	int per=0, qtd=0; 	//permutação dos caminhos, qtd de caminhos já calculados

	//Calcula a permutação dos caminhos
	if(sub[fi].first == sub[si].first)	//se o 1° e o 2° tiverem o mesmo tam (existem 2ou+ sub com esse tam) então pareamos todos eles
	{
		for(auto x : sec) //equivalente a uma permutação fatoreal, mas de trás pra frente (xf*0 -> x0*tudo)
		{	
			per += x.second * qtd;
			qtd += x.second;
		}
	}
	else 	//se não, devemos parear o maior com todos os segundo maiores
	{
		for(auto x : sec) 
			per += sub[fi].second * x.second;
		qtd = sub[fi].second;
	}


	maxresp(sub[fi].first + sub[si].first + 1, per); //calcula a maior resposta até agora

	return {sub[fi].first + 1, qtd}; //retorno a maior profundidade e a quantidade de vezes que ela aparece na subtree
}




int main(){

	cin >> n;

	for(int i=1, u, v; i<n; i++)
	{
		cin >> u >> v;
		grafo[v].push_back(u);
		grafo[u].push_back(v);
	}

	dfs(1, 0);
	
	cout << resp.first << endl << resp.second << endl; //qtd tá saindo dobrado

	return 0;	
}


/*

	Ok ok, logo após ler a questão já fica claro que o primeiro passo é encontrar o maior caminho entre dois vértices
quaisquer, isso, como vim a descobrir, é o *Diâmetro da Árvore*! E o algoritmo necessário para encontrar esse diâmetro
é relativamente simples.

	Existem dois algoritmos que encontrei nas minhas buscas que podem ser utilizados, um, mais fácil na minha opinião,
consiste em fazer uma busca pelo vértice mais profundo da árvore, enraizada arbitrariamente, e em seguida fazer outra 
busca enraizando a árvore nesse outro vértice, a maior distância encontrada será o diâmetro. Essa abordagem, apesar de 
simples e rápida para casos simples não seria muito boa neste caso em específico, isso porque teríamos de procurar
repetidamente para encontrarmos todos os maiores caminhos. Talves isso pudesse ser feito pegando uma lista de todos os
maiores possíveis e depois fazer uma busca pra cada um deles, mas para isso seria necessário ficar verificando na segunda
busca se os novos vértices encontrados não estariam repetidos. Mas vamos seguir para o próximo algoritmo e para a solução
implementada.

	Esse segundo algoritmo funciona da seguinte forma: eu pego uma raiz arbitrária e verifico qual a maior e a segunda 
maior profundidade que há na minha árvore, isso chamando uma recursão com a mesma coisa para as sub árvores de meus filhos, 
cada filho verificará qual o maior caminho que alcança somando a maior profundidade com a segunda maior encontrada. Cada
vez que se encontrar um possível caminho máximo faço um max(resp, novoCaminho), no fim terei encontrado o maior caminho.

	Apesar de parecer mais complexo que o anterior, pelo menos em explicação (não sei se consegui resumir bem o algoritmo,
pessoalmente recomendo que tente encontrar algum material sobre para entender melhor), esse algoritmo é melhor para 
trabalharmos com esse problema, isso porque podemos modificar ele para retornar além do tamanho da maior profundidade a
quantidade de vezes que essa profundidade ocorre na minha sub-árvore. Bem, com isso temos "apenas" de fazer um algoritmo de
permutação de caminhos, pois, se encontro três possíveis com a maior profundidade e 2 possíveis com a segunda maior temos
fazer essa multiplicação para encontrar o maior número possível. Mas temos mais um complicação nessa permutação, posso ter
econtrado 2 maiores nessa sub-árvore, mais 3 maiores nessa outra sub e outros 2 numa terceira sub-árvore, não podemos
simplesmente juntar como se todos esses fossem o mesmo, então temos de fazer uma permutação levando em contra as sub árvores.

	Só é preciso se atentar a mais um detalhe, se encontro várias sub-árvores com maiores profundidades tenho de permutar
maiores<->maiores, mas se encontro um maior e um ou mais segundo maiores tenho de permurtar maior<->segundosMaiores.

	Tendo feito tudo isso só temos de contar quantas vezes um maior caminho aparece, com um max(resp, ans) meio modificado,
mas isso é mais simples de se resolver. :)

	Ok ok, então acho que é isso! \(°W°)/

*/