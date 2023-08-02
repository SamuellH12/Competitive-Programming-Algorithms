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


void getZarr(string str, int Z[])
{
    int n = str.length();
    int L, R, k;
 
    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        
        if (i > R)
        {
            L = R = i;
 
            while (R<n && str[R-L] == str[R])
                R++;

            Z[i] = R-L;
            R--;
        }
        else
        {
            k = i-L;
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
            else
            {
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}



int main(){

	string s;
	cin >> s;
	int t = s.size();

	int z[t];
	getZarr(s, z);
	z[0] = t;

	set<int> div;

	for(int i=2; i*i<=t; i++)
		if(t%i==0){
			div.insert(i);
			div.insert(t/i);
		}

	int resp = 1;

	for(auto x : div){

		bool ok = true;

		for(int i=x; i<t; i+=x)
			if(z[i] < x){
				ok = false;
				break;
			}

		if(ok) resp += t;
	}
	

	if(z[1] == t-1) resp += t;


	cout << resp << endl;
		
	return 0;	
}
