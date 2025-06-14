#include <bits/stdc++.h>
// #include <openssl/evp.h>
using namespace std;

const string code_dir = "../Library";
const string title = "SamuellH12 - ICPC Library";

const vector<string> IGNORED_LINES = {
    "#include <bits/stdc++.h>",
    "using namespace std;",
    "#define pii pair<int, int>",
    "#define pii pair<int,int>",
    "#define ll long long",
    "/*LATEX IGNORED LINE*/",
    "Credits: ",
    "/********",
    "********/",
    " \t \t \t \t ", //pra ocultar linhas sem chamar atenção no código
};

const vector<string> IGNORED_SUBSTRINGS = {
    "std::", //pra lib de tfg
    "/*LATEX_DESC_BEGIN*/",
    "/*LATEX_DESC_END*/",
};

bool ADD_DESC = true;
const string DESC_BGN = "/*LATEX_DESC_BEGIN*/";
const string DESC_END = "/*LATEX_DESC_END*/";
const string MY_DESC_BGN = "/********";
const string MY_DESC_END = "********/";

map<char32_t, char> char_changes = {
    {0x00E7, 'c'}/*ç*/, {0x00E3, 'a'}/*ã*/, {0x00E1, 'a'}/*á*/,
    {0x00E9, 'e'}/*é*/, {0x00ED, 'i'}/*í*/, {0x00F3, 'o'}/*ó*/, {0x00FA, 'u'}/*ú*/,
    {U'ç', 'c'}, {U'ã', 'a'}, {U'ä', 'a'}, {U'å', 'a'},
    {U'á', 'a'}, {U'à', 'a'}, {U'â', 'a'}, {U'ã', 'a'},
    {U'Á', 'A'}, {U'À', 'A'}, {U'Â', 'A'}, {U'Ã', 'A'},
    {U'é', 'e'}, {U'è', 'e'}, {U'ê', 'e'}, {U'ë', 'e'},
    {U'í', 'i'}, {U'ì', 'i'}, {U'î', 'i'}, {U'ï', 'i'},
    {U'ó', 'o'}, {U'ò', 'o'}, {U'ô', 'o'}, {U'õ', 'o'},
    {U'ú', 'u'}, {U'ù', 'u'}, {U'û', 'u'}, {U'ü', 'u'},
    {U'ñ', 'n'}, {U'ç', 'c'}, {U'ý', 'y'}, {U'ÿ', 'y'},
    {U'\x2019', '\''}, {U'\x3b1', 'a'}, {U'\x2013', '-'},
};

// hash incompleto - não usar
const bool USE_HASH = false;
const int HASH_LEN = 3;

void remove_ignored_substrings(string& s) {
    size_t pos = 0;
    for(const auto& substr : IGNORED_SUBSTRINGS)
        while((pos = s.find(substr, pos)) < s.size()) 
            s.erase(pos, substr.length());
}

void remove_invalid_char(string &line){ // Process UTF-8 characters
    for(size_t i = 0; i < line.size(); ){
        unsigned char c = line[i];
        
        if((c & 0x80) == 0){ // ASCII character
            if (char_changes.count(c)) line[i] = char_changes[c];
            i++;
        } else { //UTF-8 sequence
            char32_t codepoint = 0; int seq_len = 0;

            if((c & 0xE0) == 0xC0) codepoint = ((c & 0x1F) << 6)  | (line[i+1] & 0x3F), seq_len = 2; // 2-byte sequence
            else 
            if((c & 0xF0) == 0xE0) codepoint = ((c & 0x0F) << 12) | ((line[i+1] & 0x3F) << 6) | (line[i+2] & 0x3F), seq_len = 3; // 3-byte sequence
            else 
            if((c & 0xF8) == 0xF0) codepoint = ((c & 0x07) << 18) | ((line[i+1] & 0x3F) << 12) | ((line[i+2] & 0x3F) << 6) | (line[i+3] & 0x3F), seq_len = 4; // 4-byte sequence

            if(seq_len > 0 && char_changes.count(codepoint)) 
                line.replace(i, seq_len, 1, char_changes[codepoint]), i++;
            else i += seq_len > 0 ? seq_len : 1;
        }
    }
}


bool is_comment(string line) {
	while (line.size() and (line[0] == ' ' or line[0] == '\t'))
		line = line.substr(1);
	bool comment = line.size() == 0;
	if (line.size() >= 2 and line.substr(0, 2) == "//") comment = true;
	if (line.size() >= 2 and line.substr(0, 2) == "/*") comment = true;
	return comment;
}
 
bool convert_files(const string& input_path, const string& output_path, string& description, bool PRINT_HASH = false){
    ifstream in(input_path, ios::binary);
    if(!in){ cerr << "Error opening input file: " << input_path << endl; return false; }
    string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();

    bool can_begin = false, isInDesc = false;
    string processed_content, line;
    description = "";
    size_t pos = 0;

    // line by line
    while(pos < content.size()){
        size_t end = content.find('\n', pos);
        line = (end == string::npos) ? content.substr(pos) : content.substr(pos, end - pos);
        pos = (end == string::npos) ? content.size() : end + 1;

        bool ignore = false;
        while(!line.empty() && (line.back() == '\t' || line.back() == '\r')) line.pop_back();
        bool blank_line = line.empty();

        // pra pegar a descrição
        if(line.find(DESC_BGN) != string::npos) isInDesc = true; if(line.find(MY_DESC_BGN) != string::npos) isInDesc = true;

        if(!blank_line)
        for(const auto& pattern : IGNORED_LINES)
            if(line.find(pattern) != string::npos){
                ignore = true;
                break;
            }

        if(ADD_DESC && isInDesc && !ignore){ description += line + "\n"; continue; }
        if(line.find(DESC_END) != string::npos) isInDesc = false; if(line.find(MY_DESC_END) != string::npos) isInDesc = false;

        if(!ignore && !blank_line) can_begin = true;
        if(!can_begin || ignore) continue;

        remove_invalid_char(line);
        remove_ignored_substrings(line);

        processed_content += line + "\n";
    }

    while(!processed_content.empty() && (processed_content.back() == '\n' || processed_content.back() == '\t' || processed_content.back() == ' '))
        processed_content.pop_back();

    remove_invalid_char(description);
    remove_ignored_substrings(description);

    // if(PRINT_HASH) processed_content = get_file_hash(processed_content);

    // Ensure output directory exists
    filesystem::path out_path(output_path);
    filesystem::create_directories(out_path.parent_path());
    ofstream out(output_path, ios::binary);
    if(!out){ cerr << "Error creating output file: " << output_path << endl; return false; }

    out << processed_content;
    out.close();
    return true;
}

string get_style(const string& filename) {
    size_t dot_pos = filename.rfind('.');
    if (dot_pos == string::npos) return "txt";
    
    string ext = filename.substr(dot_pos + 1);
    transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    
    if (ext == "c" || ext == "cc" || ext == "cpp" || ext == "h") return "cpp";
    if (ext == "java") return "java";
    if (ext == "py") return "py";
    return "txt";
}

const string CODE_DESCRIPTION = 
R"(Este cadigo foi extraido da biblioteca de competicao.
Uso tipico: #include <arquivo.hpp>
Complexidade: O(log n))";

string get_tex(const vector<pair<string, vector<pair<string, string>>>>& sections, bool PRINT_HASH=false) {
    string tex, description;
    for(auto& [section_name, subsections] : sections) if(!subsections.empty()){
        tex += "\\section{" + section_name + "}\n";
        
        for(auto [filename, subsection_name] : subsections) {
            string full_path = code_dir + "/" + filename;
            cout << full_path << endl;

            string newpath = "./temp/" + filename;
            if(convert_files(full_path, newpath, description, PRINT_HASH)) 
                full_path = newpath;

            tex += "\\vspace{-1ex}\n";
            tex += "\\subsection{" + subsection_name + "}\n";
            
            if(!description.empty()){
                tex += "\\vspace{-3pt}\n";
                tex += "\\begin{lstlisting}[style=description]\n";
                tex += description + "\n";
                tex += "\\end{lstlisting}\n";
            } 
            
            tex += "\\vspace{-3pt}\n\n";
            tex += "\\raggedbottom\\lstinputlisting[style="+get_style(filename) + "]{" + full_path + "}\n";
            tex += "\\hrulefill\n\n";
        }
        tex += "\n";
    }
    return tex;
}

vector<pair<string, vector<pair<string, string>>>> get_sections() {
    vector<pair<string, vector<pair<string, string>>>> sections;
    
    ifstream f("contents.txt", ios::binary); // For UTF-16 handling on Windows

    if (!f.is_open()) { cerr << "Error opening contents.txt" << endl; return sections; }

    // Skip BOM for UTF-16 if present
    char bom[2];
    f.read(bom, 2);
    if (bom[0] != (char)0xFF || bom[1] != (char)0xFE){ f.seekg(0); }

    string line;
    while (getline(f, line)) 
    {
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        line.erase(remove(line.begin(), line.end(), 0), line.end());
        
        if(line.empty()) continue;
        if(line.find('#') < line.size()) continue;
        
        if(line[0] == '[') sections.emplace_back(line.substr(1, line.size() - 2), vector<pair<string, string>>());
        else {
            size_t tab_pos = line.find('\t');
            if (tab_pos >= line.size()) {
                cerr << "Subsection parse error {" << line << "} " << line.size() << endl;
                for(auto c : line) cerr << int(c) << '|'; cerr << endl;
                continue;
            }
            
            string filename = line.substr(0, tab_pos);  
            string subsection_name = line.substr(tab_pos + 1);
            
            if (sections.empty()) {
                cerr << "Subsection given without section {" << line << "} " << line.size() << endl;
                continue;
            }
            
            sections.back().second.emplace_back(filename, subsection_name);
        }
    }
    
    return sections;
}


int main(){
    cout << title << endl;
    
    auto sections = get_sections();
    string tex = get_tex(sections, USE_HASH);
    
    ofstream out("contents.tex");
    if(out.is_open()) out << tex;
    else {
        cerr << "Error writing contents.tex" << endl;
        return 1;
    }
    
    return 0;
}



/*

// compute MD5 hash of a string
string compute_md5_hash(const string& content, int size) {
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;

    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, EVP_md5(), nullptr);
    EVP_DigestUpdate(mdctx, content.c_str(), content.size());
    EVP_DigestFinal_ex(mdctx, digest, &digest_len);
    EVP_MD_CTX_free(mdctx);

    char mdString[33];
    for (unsigned int i = 0; i < 16; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

    mdString[32] = '\0';
    return string(mdString).substr(0, size);
}

string get_hash_arquivo(string &s, int size, int l = 0, int r = 1e9) {
    stringstream ss(s);
    string content = "", line;
    
    // Lê apenas o intervalo especificado
    for (int i = 0; i <= r; i++){
        if (!getline(ss, line)) break;
        if (i >= l) content += line + "\n";
    }
    return compute_md5_hash(content, size);
}


// Process content and add hashes
string get_file_hash(string& content){
    stringstream ss(content);
    string line, output = "";
	int depth = 0;
	stack<int> st;

	for(int line_idx = 0; getline(ss, line); line_idx++){
		int start_line = line_idx;

        for (char c : line)
			if (c == '{') depth++, st.push(line_idx); else
			if (c == '}') depth--, start_line = st.top(), st.pop();

        string hash = "";
        if(!is_comment(line)) hash = get_hash_arquivo(content, HASH_LEN, start_line, line_idx);
        else if(depth != 0) hash = string(HASH_LEN + 1, ' ');
        
        output += hash + " " + line + "\n";
    }

    return output;
}

*/