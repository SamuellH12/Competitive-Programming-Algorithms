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

#define FAST_HASH
#ifdef FAST_HASH
string strip_comments(const string &s){
	enum St{ NORMAL, POSSIBLE_COMMENT, LINE_COMMENT, BLOCK_COMMENT,
		IN_STR, IN_STR_ESC, IN_CHAR, IN_CHAR_ESC, IN_RAW
	};
	St st = NORMAL;
	string out, raw_delim, raw_end;
	out.reserve(s.size());

	size_t i = 0, n = s.size();
	while(i < n){
		char c = s[i];
		switch(st){
		case NORMAL:
			if (c == '/') st = POSSIBLE_COMMENT, i++;
			else if (c == '"')  out.push_back(c), st = IN_STR,  i++;
			else if (c == '\'') out.push_back(c), st = IN_CHAR, i++;
			else if (c == 'R' && i + 1 < n && s[i + 1] == '"')
			{
				size_t j = i + 2;
				string delim;
				while (j < n && s[j] != '(' && s[j] != '\n') delim.push_back(s[j++]);
				if(j < n && s[j] == '('){
					raw_delim = delim;
					raw_end = ")" + raw_delim + "\"";
					out.append(s, i, j - i + 1);
					i = j + 1;
					st = IN_RAW;
				}
				else out.push_back(c), i++;
			}
			else out.push_back(c), i++;
		break;
		case POSSIBLE_COMMENT:
			if(i >= n) out.push_back('/'), st = NORMAL;
			else {
				if (s[i] == '/') st = LINE_COMMENT, i++;
				else if (s[i] == '*') st = BLOCK_COMMENT, i++;
				else out.push_back('/'), st = NORMAL;
			}
		break;
		case LINE_COMMENT:
			if (c == '\n') out.push_back('\n'), st = NORMAL;
			i++;
		break;
		case BLOCK_COMMENT:
			if(c == '*' && i + 1 < n && s[i + 1] == '/') i += 2, st = NORMAL;
			else i++;
		break;
		case IN_STR:
			out.push_back(c);
			if (c == '\\') st = IN_STR_ESC;
			else if (c == '"') st = NORMAL;
			i++;
		break;
		case IN_STR_ESC:
			out.push_back(c);
			st = IN_STR;
			i++;
		break;
		case IN_CHAR:
			out.push_back(c);
			if (c == '\\') st = IN_CHAR_ESC;
			else if (c == '\'') st = NORMAL;
			i++;
		break;
		case IN_CHAR_ESC:
			out.push_back(c);
			st = IN_CHAR;
			i++;
		break;
		case IN_RAW: {
			size_t pos = s.find(raw_end, i);
			if (pos == string::npos) out.append(s, i, n - i), i = n, st = NORMAL;
			else out.append(s, i, pos - i + raw_end.size()), i = pos + raw_end.size(), st = NORMAL;
		} break;
		default:
			i++;
		break;
		}
	}

	if(st == POSSIBLE_COMMENT) out.push_back('/');
	return out;
}

#include <openssl/md5.h> 
// g++ -E -P -dD -fpreprocessed ./temp.cpp | tr -d '[:space:]' | md5sum > hsh.temp
string getHash_Fast(string s, int dig=3){
	
	// remove comments ~ g++ -E -P -dD -fpreprocessed
	s = strip_comments(s); 

	// remove whitespace ~ tr -d '[:space:]'
    string normalized;
    for(auto c : s) if(!isspace(c)) normalized.push_back(c); 

    // compute MD5 ~ md5sum
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<const unsigned char*>(normalized.data()), normalized.size(), digest);


    // convert MD5 to hex string
    char hex[MD5_DIGEST_LENGTH*2 + 1];
    for(int i = 0; i < MD5_DIGEST_LENGTH; ++i) sprintf(hex + i*2, "%02x", digest[i]);
    hex[MD5_DIGEST_LENGTH*2] = 0;

    string result = string(hex).substr(0, dig);

	for(auto&c : result) if('a'<=c) c^=32; //Make letters uppercase
    return result;
}

#else
string getHash_Fast(string s, int dig=3){ //getHash_fast_original
	ofstream ip("temp.cpp"); ip.sync_with_stdio(false);
	ip << s; ip.close();

	system("g++ -E -P -dD -fpreprocessed ./temp.cpp | tr -d '[:space:]' | md5sum > hsh.temp");
	
	ifstream f("hsh.temp"); f.sync_with_stdio(false); f.tie(NULL);
	f >> s;  f.close();
	
	for(auto&c:s)if('a'<=c) c^=32; //Make letters uppercase
	return s.substr(0, dig);
}
#endif

string _ESCAPE_ = "@";

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
		// assert(hs == getHash_fast_original(t, dig)); // OK! Was the same in all codes of this lib at 15/11/2025
        trimed = t;
        while(!trimed.empty() && isspace(trimed.back())) trimed.pop_back(); // remove trailing spaces
        if(trimed.empty() && st.size() == 100) for(hs = ""; hs.size()<dig; hs += " ");          //empty line -> no hash

		hcode += _ESCAPE_ + "" + hs + " " + _ESCAPE_;
        hcode += l + "\n";
		st.back() += t + "\n";
	}
    
    return hcode;
}
//LATEX_IGNORED_END
