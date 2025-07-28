#include <bits/stdc++.h>
#define ll long long
using namespace std;
#ifdef MAINFILE //LATEX_IGNORED_LINE

string getHash(string s){
	ofstream ip("temp.cpp"); ip << s; ip.close();
	system("g++ -E -P -dD -fpreprocessed ./temp.cpp | tr -d '[:space:]' | md5sum > hsh.temp");
	ifstream fo("hsh.temp"); fo >> s; fo.close();
	return s.substr(0, 3);
}

int main(){ 
	string l, t;
	vector<string> st(10);
	while(getline(cin, l)){
		t = l;
		for(auto c : l)
			if(c == '{') st.push_back(""); else 
			if(c == '}') t = st.back() + l, st.pop_back();
		cout << getHash(t) + " " + l + "\n";
		st.back() += t + "\n";
	}
    return 0; //LATEX_IGNORED_LINE
}

#endif //LATEX_IGNORED_LINE
/*LATEX_DESC_BEGIN
Call
BLOCK_DESC_BEGIN g++ hash.cpp -o hash \\ ./hash < code.cpp BLOCK_DESC_END to get the hash of the code.

The hash ignores comments and whitespaces.
The hash of a line whith } is the hash of all the code since the { that opens it. (is the hash of that context) 

(Optional) To make letters upperCase: for(auto&c:s)if('a'<=c) c^=32;
LATEX_DESC_END*/

//LATEX_IGNORED_BEGIN
string _ESCAPE_ = "@";

string getHash_Fast(string s, int dig=3){
	ofstream ip("temp.cpp"); 
	
	ip.sync_with_stdio(false);
	
	ip << s; 
	ip.close();

	system("g++ -E -P -dD -fpreprocessed ./temp.cpp | tr -d '[:space:]' | md5sum > hsh.temp");
	
	ifstream f("hsh.temp"); 
	f >> s; 
	f.close();
	
	for(auto&c:s)if('a'<=c) c^=32; //Make letters uppercase
	
	return s.substr(0, dig);
}


string getCodeHash(const string& code, int dig=3){
    string hcode, l, t, hs, trimed;
    stringstream ss(code);

	vector<string> st(100);
	while(getline(ss, l)){
		t = l;
		
        for(auto c : l)
			if(c == '{') st.push_back(""); else 
			if(c == '}') t = st.back() + l, st.pop_back();
        
        hs = getHash_Fast(t, dig);
        trimed = t;
        while(!trimed.empty() && isspace(trimed.back())) trimed.pop_back(); // remove trailing spaces
        if(trimed.empty()) for(hs = ""; hs.size()<dig; hs += " ");          //empty line -> no hash

		hcode += _ESCAPE_ + "" + hs + " " + _ESCAPE_;
        hcode += l + "\n";
		st.back() += t + "\n";
	}
    
    return hcode;
}
//LATEX_IGNORED_END
