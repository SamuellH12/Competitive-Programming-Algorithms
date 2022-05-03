//Samuell H C P C - IFPI SRN - OBI2021
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define sc second
#define ft first
#define debug cout<<"ate aqui ok\n"
using namespace std;
 
 
int main(){
 
	int n; cin>>n;
    bool tlast = false;
    int time = 0;
    
    map<int, int> tresp;
    map<int, bool> bresp;
    
    while(n--)
    {
		string c; int x, t = 1;
        cin >> c >> x;
        if(tlast){ tlast = false; t = 0; }
        
        
        if(c == "T")
        { 
         t = x; 
         tlast = true; 
        }
 
        
        for(auto &a : tresp)
        {
            if(t == 0) break;
            if(!bresp[a.first]) a.second += t;
        }
        
        
        if(c == "E")
        {
            bresp[x] = true;
        }
        else if(c == "R")
        {
            if(tresp[x] == 0) tresp[x] = 0;
            bresp[x] = false;
   		}
        
        time += t; 
    }
    
    
    for( auto a : tresp)
    {
		int demora = (bresp[a.first] ? a.second : -1);
        cout << a.first << " " << demora << endl;
    }
 
	return 0;	
}