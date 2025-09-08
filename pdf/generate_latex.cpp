#include <bits/stdc++.h>
#include <regex>
#define t_section tuple<string, string, bool>
using namespace std;

const bool USE_HASH = true;
const int HASH_LEN = 3;

const vector<string> IGNORED_LINES = {
    "#include <bits/stdc++.h>",
    "using namespace std;",
    "#define pii pair<int, int>",
    "#define pii pair<int,int>",
    "#define ll long long",
    "LATEX_IGNORED_LINE",
    "Credits: ",
    "/********",
    "********/",
    " \t \t \t \t ", //pra ocultar linhas sem chamar atenção no código
    "LATEX_DESC_BEGIN",
    "LATEX_DESC_END",
    "\t//////////////////////",
};

const vector<string> IGNORED_SUBSTRINGS = {
    "std::", //pra lib de tfg
    "LATEX_DESC_BEGIN",
    "LATEX_DESC_END",
};

const string IGNORED_INTERVAL_BGN = "LATEX_IGNORED_BEGIN";
const string IGNORED_INTERVAL_END = "LATEX_IGNORED_END";

const bool ADD_DESC = true;
const string DESC_BGN = "LATEX_DESC_BEGIN";
const string DESC_END = "LATEX_DESC_END";

const bool BLOCK_DESC = true;
const string BLOCK_DESC_BGN = "BLOCK_DESC_BEGIN";
const string BLOCK_DESC_END = "BLOCK_DESC_END";

const bool USE_MARKDOWN_IN_DESC = true;

const bool IGNORE_EMPTY_LINES = false;

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

//// Code Start Here ///
#include "hash/md5hsh.cpp"    // Include another hash function if you want to use other
const string HASH_CODE = "./hash/md5hsh.cpp";  // Path to the hash code that will be used (To put on lib)
string _get_code_hash_(string code){
    return getCodeHash(code, HASH_LEN);
}

const string COMMENT_BLOCK_DESC_BGN = R"(/\*+\s*)" + BLOCK_DESC_BGN;
const string COMMENT_BLOCK_DESC_END = BLOCK_DESC_END + R"(\s*\*+/)";

void remove_whitespace(string& s){
    while(!s.empty() && isspace(s.back()))
        s.pop_back();
}

void remove_front_whitespace(string& s){
    int skp = 0;
    while(skp < s.size() && isspace(s[skp]))
        skp++;
    s.erase(0, skp);
}


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

string parse_markdown(const string& input, bool isBlockDesc = false){
    string output = input; bool ibd = isBlockDesc;

    // Negrito **texto**
    output = regex_replace(output, regex(R"(\*\*([^\n\r\t*]+)\*\*)"),  ibd ? "\\textbf{$1}" : "@\\textbf{$1}@"); 
    // Itálico _.texto_.
    output = regex_replace(output, regex(R"(_\.([^\n\r\t_]+)_\.)"), ibd ? "\\emph{$1}" : "@\\emph{$1}@");
    // Código inline (usando `texto`) // não tem boa formatação no pdf
    // output = regex_replace(output, regex(R"(`([^\n\r\t`]+)`)"), ibd ? "\\mintinline{cpp}{$1}" : "@\\texttt{$1}@"); 
    
    // Potências: x^k
    // output = regex_replace(output, regex(R"(([a-zA-Z])\^([a-zA-Z0-9]+))"), ibd ? "$ $1^{$2}$" : "@$ $1^{$2}$@");
    // Subscritos: x._k
    // output = regex_replace(output, regex(R"(([a-zA-Z])\._([a-zA-Z0-9]+))"), ibd ? "$ $1_{$2}$" : "@$ $1_{$2}$@");

    return output;
}

const string REMOVEENDL = ".\\";
string convert_description(const string& description, bool isBlockDesc = false) {
    string s = "", line;
    stringstream ss(description);
    bool lastSkip = false;

    while(getline(ss, line)){
        if(line.size() >= REMOVEENDL.size() && line.substr((int)line.size() - REMOVEENDL.size()) == REMOVEENDL){
            for(auto _ : REMOVEENDL) line.pop_back();
            while(!line.empty() && (line.back() == ' ' || line.back() == '\t')) line.pop_back();
            line += " ";
            lastSkip = true;
        } else line += "\n", lastSkip = false;

        if(lastSkip){
            int skp = 0;
            while(skp < line.size() && (line[skp] == ' ' || line[skp] == '\t')) skp++;
            line = line.substr(skp);
        }
        s += line;
    }

    return USE_MARKDOWN_IN_DESC ? parse_markdown(s, isBlockDesc) : s;
}

bool is_comment(string line) {
	while (line.size() and (line[0] == ' ' or line[0] == '\t'))
		line = line.substr(1);
	bool comment = line.size() == 0;
	if (line.size() >= 2 and line.substr(0, 2) == "//") comment = true;
	if (line.size() >= 2 and line.substr(0, 2) == "/*") comment = true;
	return comment;
}

const string BLOCK_DESC_MARK = "BLOCK_DESC_MARK\n";
bool convert_files(const string& input_path, const string& output_path, string& description, bool PRINT_HASH = false){
    ifstream in(input_path, ios::binary);
    if(!in){ cerr << "Error opening input file: " << input_path << endl; return false; }
    string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();

    bool can_begin = false, isInDesc = false, ignore_interval = false, isInBlckDesc = false;
    vector<string> block_descs, block_desc_desc;
    string processed_content, line, block_desc="";
    description = "";
    size_t pos = 0;

    // line by line
    while(pos < content.size()){
        size_t end = content.find('\n', pos);
        line = (end == string::npos) ? content.substr(pos) : content.substr(pos, end - pos);
        pos = (end == string::npos) ? content.size() : end + 1;

        bool ignore = false;
        remove_whitespace(line);

        // pra pegar a descrição
        if(line.find(DESC_BGN) != string::npos) isInDesc = true; //if(line.find(MY_DESC_BGN) != string::npos) isInDesc = true;
        if(line.find(IGNORED_INTERVAL_BGN) != string::npos) ignore_interval = true;
        if(ignore_interval) ignore = true;
        if(line.find(IGNORED_INTERVAL_END) != string::npos) ignore_interval = false;

        {
            size_t bgn = line.find(BLOCK_DESC_BGN);
            size_t end = line.find(BLOCK_DESC_END);

            if(isInBlckDesc && bgn != string::npos){ 
                cerr << "\n\n\n\n\nError: BLOCK_DESC_BGN found inside another BLOCK_DESC_BGN at" << input_path << "\n\n\n\n\n\n" << endl;
                return false; 
            }

            if(bgn != string::npos) line = regex_replace(line, regex(COMMENT_BLOCK_DESC_BGN), BLOCK_DESC_BGN), bgn = line.find(BLOCK_DESC_BGN);
            if(end != string::npos) line = regex_replace(line, regex(COMMENT_BLOCK_DESC_END), BLOCK_DESC_END), end = line.find(BLOCK_DESC_END);
            
            if(bgn != string::npos && end != string::npos){
                block_desc = line.substr(bgn + BLOCK_DESC_BGN.size(), end - bgn - BLOCK_DESC_BGN.size());
                line.erase(bgn, end - bgn + BLOCK_DESC_END.size());
            } 
            else 
            if(bgn != string::npos && end == string::npos){
                isInBlckDesc = true;
                block_desc = line.substr(bgn + BLOCK_DESC_BGN.size());
                line.erase(bgn);
            } 
            else
            if(bgn == string::npos && end != string::npos){
                isInBlckDesc = false;
                block_desc += (block_desc.empty() ? "" : "\\\\\n") + line.substr(0, end);
                line.erase(0, end + BLOCK_DESC_END.size());
            } 
            else if(isInBlckDesc){
                block_desc += line;
                line.clear();
            }

            if(end != string::npos){
                block_desc = convert_description(block_desc, true);
                remove_whitespace(block_desc);
                remove_front_whitespace(block_desc);
                remove_whitespace(processed_content);
                block_desc = block_desc.empty() ? "\n" : "\n@\\blockdesc{" + block_desc + "}@\n";
                if(isInDesc){
                    block_desc_desc.emplace_back(block_desc),
                    description += BLOCK_DESC_MARK;
                }
                else {
                    block_descs.emplace_back(block_desc);
                    processed_content += "\n" + BLOCK_DESC_MARK;
                }
                can_begin = false;
                isInBlckDesc = false;
                block_desc.clear();
                remove_front_whitespace(line);
            }
        }

        bool blank_line = line.empty();
        if(!blank_line)
        for(const auto& pattern : IGNORED_LINES)
            if(line.find(pattern) != string::npos){
                ignore = true;
                break;
            }

        if(ADD_DESC && isInDesc && !ignore){ description += line + "\n"; continue; }
        if(line.find(DESC_END) != string::npos) isInDesc = false; //if(line.find(MY_DESC_END) != string::npos) isInDesc = false;
        if(IGNORE_EMPTY_LINES && blank_line) continue;

        if(!ignore && !blank_line) can_begin = true;
        if(!can_begin || ignore) continue;

        remove_invalid_char(line);
        remove_ignored_substrings(line);

        processed_content += line + "\n";
    }

    remove_whitespace(processed_content);

    remove_invalid_char(description);
    remove_ignored_substrings(description);
    description = convert_description(description);

    if(PRINT_HASH) processed_content = _get_code_hash_(processed_content);
    
    for(auto blck : block_descs){
        auto bgn = processed_content.find(BLOCK_DESC_MARK);
        int sz = BLOCK_DESC_MARK.size();
        while(bgn > 0 && processed_content[bgn] != '\n') bgn--, sz++;
        processed_content.replace(bgn, sz, blck);
    }

    for(auto blck : block_desc_desc){
        auto bgn = description.find(BLOCK_DESC_MARK);
        int sz = BLOCK_DESC_MARK.size();
        while(bgn > 0 && description[bgn] != '\n') bgn--, sz++;
        description.replace(bgn, sz, blck);
    }

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
    if (ext == "tex") return "tex";
    if (ext == "sh") return "sh";
    return "txt";
}

string get_tex(const vector<pair<string, vector<t_section>>>& sections) {
    string tex, description;
    for(auto& [section_name, subsections] : sections) if(!subsections.empty()){
        tex += "\\section{" + section_name + "}\n";
        
        for(auto [filename, subsection_name, file_hash] : subsections){
            cout << get_style(filename) + "\t| " << filename << endl;
            if(get_style(filename) == "tex"){ tex += "\\input{" + filename + "}\n"; continue; }
            
            string newpath = "./temp/" + filename, full_path = filename;;
            newpath = regex_replace(newpath, regex(R"(\.\./|\./)"), ""); // remove qualquer ../ ou ./ de newpath

            if(convert_files(full_path, newpath, description, USE_HASH&&file_hash&&get_style(filename)=="cpp"))
                full_path = newpath;

            tex += "\\vspace{-2pt}\n";
            tex += "\\subsection{" + subsection_name + "}\n";
            
            if (!description.empty()) {
                tex += "\\vspace{-4pt}\n";
                tex += "\\begin{lstlisting}[style=description]\n";
                tex += description + "\n";
                tex += "\\end{lstlisting}\n";
            } 
            
            tex += "\\vspace{-5pt}\n";
            tex += "\\raggedbottom\\lstinputlisting[style="+get_style(filename) + "]{" + full_path + "}\n";
            tex += "\\hrulefill\n\n";
        }
        tex += "\n";
    }
    return tex;
}

vector<pair<string, vector<t_section>>> get_sections() {
    vector<pair<string, vector<t_section>>> sections;
    
    ifstream f("contents.txt", ios::binary); // For UTF-16 handling on Windows

    if (!f.is_open()) { cerr << "Error opening contents.txt" << endl; return sections; }

    // Skip BOM for UTF-16 if present
    char bom[2];
    f.read(bom, 2);
    if (bom[0] != (char)0xFF || bom[1] != (char)0xFE){ f.seekg(0); }

    string line;
    char div_char; // Default divisor character
    f >> div_char;

    while(getline(f, line)) 
    {
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        line.erase(remove(line.begin(), line.end(), 0), line.end());
        
        if(line.empty()) continue;
        if(line.find('#') < line.size()) continue;

        if(line[0] == '[') sections.emplace_back(line.substr(1, line.size() - 2), vector<t_section>());
        else {
            size_t div_pos = line.find(div_char);
            if (div_pos >= line.size()) {
                cerr << "\n\n\n\nSubsection parse error {" << line << "} " << line.size() << "\n";
                cerr << "Is the DIVISOR character correct? It should be '" << div_char << "'\n\n\n\n";
                continue;
            }
            
            bool file_hash = true;
            if(line.find('@') < line.size()) file_hash = false, line[line.find('@')] = ' ';

            string filename = line.substr(0, div_pos);   
            while(!filename.empty() && isspace(filename.back())) filename.pop_back();
            string subsection_name = line.substr(div_pos + 1);
            remove_whitespace(subsection_name);
            remove_front_whitespace(subsection_name);

            if(sections.empty()) {
                cerr << "Subsection given without section {" << line << "} " << line.size() << endl;
                continue;
            }
            
            sections.back().second.push_back(t_section({filename, subsection_name, file_hash}));
        }
    }
    
    return sections;
}


int main(){    
    auto sections = get_sections();

    if(USE_HASH)
    {
        bool added_hash = false;
        for(auto& [section_name, subsections] : sections)
            if(section_name == "Extra")
                subsections.push_back(t_section({HASH_CODE, "Hash Function", true})),
                added_hash = true;
        if(!added_hash) 
            sections.emplace_back("Extra", vector<t_section>({t_section({HASH_CODE, "Hash Function", true})}));
    }

    string tex = get_tex(sections);
    
    ofstream out("contents.tex");
    if(out.is_open()) out << tex;
    else {
        cerr << "Error writing contents.tex" << endl;
        return 1;
    }
    
    return 0;
}
