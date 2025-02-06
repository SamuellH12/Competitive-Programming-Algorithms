#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t; cin >> t;

    while(t--)
    {
        int l, m;
        cin >> l >> m;
		l *= 100;

        queue<int> esq;
        queue<int> dir;

        string lado;
        for(int i=0, carro; i<m; i++)
        {
            cin >> carro >> lado;

            if(lado == "left") esq.push(carro);
            else dir.push(carro);
        }

        bool direito = false;
        int soma = 0;
        int resp = 0;

        while(!esq.empty() || !dir.empty() || soma)
        {
            // barca do lado direito
            if(direito){
                if( dir.empty() || soma + dir.front() > l  )
				{
                    resp++;
                    direito = false;
                    soma = 0;
                }
                else 
				{
                    soma += dir.front();
                    dir.pop();
                }
            }
            else // barca do lado esquerdo
            {   

                if( esq.empty() || soma + esq.front() > l ) {
                    resp++;
                    direito = true;
                    soma = 0;
                }
                else {
                    soma += esq.front();
                    esq.pop();
                }

            }
        }
        
        cout << resp << endl;

    }
    

    return 0;
}