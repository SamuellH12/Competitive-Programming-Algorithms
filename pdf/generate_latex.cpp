#include <bits/stdc++.h>
using namespace std;

const string code_dir = "../Library";
const string title = "SamuellH12 - ICPC Library";

const vector<string> IGNORED_LINES = {
    "#include <bits/stdc++.h>",
    "using namespace std;",
    "#define pii pair<int, int>",
    "#define ll long long",
    "/*LATEX IGNORE THIS LINE*/",
    "Credits: ",
    "/********",
    "*************/",
    " \t \t \t \t ", //pra ocultar linhas sem chamar atenção no código
};


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
        
        if (line.empty()) continue;
        if (line.find('#') < line.size()) continue;
        
        if (line[0] == '[') sections.emplace_back(line.substr(1, line.size() - 2), vector<pair<string, string>>());
        else
        {
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

string texify(const string& s) {
    // Implement any necessary escaping here
    return s;
}


namespace fs = std::filesystem;

// Replacement map using Unicode code points
std::map<char32_t, char> char_changes = {
    {U'ç', 'c'}, {U'ã', 'a'},  // Using U-prefix for char32_t literals
    {0x00E7, 'c'},  // ç -> c (hexadecimal)
    {0x00E3, 'a'},  // ã -> a
    {0x00E1, 'a'},  // á -> a
    {0x00E9, 'e'},  // é -> e
    {0x00ED, 'i'},  // í -> i
    {0x00F3, 'o'},  // ó -> o
    {0x00FA, 'u'},   // ú -> u
    {U'á', 'a'}, {U'à', 'a'}, {U'â', 'a'}, {U'ã', 'a'}, {U'ä', 'a'}, {U'å', 'a'},
    {U'Á', 'A'}, {U'À', 'A'}, {U'Â', 'A'}, {U'Ã', 'A'},
    {U'é', 'e'}, {U'è', 'e'}, {U'ê', 'e'}, {U'ë', 'e'},
    {U'í', 'i'}, {U'ì', 'i'}, {U'î', 'i'}, {U'ï', 'i'},
    {U'ó', 'o'}, {U'ò', 'o'}, {U'ô', 'o'}, {U'õ', 'o'}, {U'ö', 'o'}, {U'ø', 'o'},
    {U'ú', 'u'}, {U'ù', 'u'}, {U'û', 'u'}, {U'ü', 'u'},
    {U'ñ', 'n'}, {U'ç', 'c'},
    {U'ý', 'y'}, {U'ÿ', 'y'},
    {U'\x2019', '\''},
    {U'\x3b1', 'a'},
    {U'\x2013', '-'},
};


bool convert_files(const std::string& input_path, const std::string& output_path) {
    std::ifstream in(input_path, std::ios::binary);
    if (!in) {
        std::cerr << "Error opening input file: " << input_path << std::endl;
        return false;
    }

    std::string content((std::istreambuf_iterator<char>(in)),
                std::istreambuf_iterator<char>());
    in.close();

    bool changed = false;
    bool can_begin = false;
    std::string processed_content;
    std::string line;
    size_t pos = 0;

    // Process line by line
    while (pos < content.size()) {
        size_t end = content.find('\n', pos);
        line = (end == std::string::npos) ? content.substr(pos) : content.substr(pos, end - pos);
        pos = (end == std::string::npos) ? content.size() : end + 1;

        bool ignore = false;
        bool blank_line = line.empty();

        if (!blank_line) {
            for (const auto& pattern : IGNORED_LINES) {
                if (line.find(pattern) != std::string::npos) {
                    ignore = true;
                    break;
                }
            }
        }

        if (!ignore && !blank_line) can_begin = true;
        if (!can_begin || ignore) continue;

        // Process UTF-8 characters
        for (size_t i = 0; i < line.size(); ) {
            unsigned char c = line[i];
            if ((c & 0x80) == 0) { // ASCII character
                if (char_changes.count(c)) {
                    line[i] = char_changes[c];
                    changed = true;
                }
                i++;
            } else { // UTF-8 sequence
                char32_t codepoint = 0;
                int seq_len = 0;

                if ((c & 0xE0) == 0xC0) { // 2-byte sequence
                    codepoint = ((c & 0x1F) << 6) | (line[i+1] & 0x3F);
                    seq_len = 2;
                } else if ((c & 0xF0) == 0xE0) { // 3-byte sequence
                    codepoint = ((c & 0x0F) << 12) | ((line[i+1] & 0x3F) << 6) | (line[i+2] & 0x3F);
                    seq_len = 3;
                } else if ((c & 0xF8) == 0xF0) { // 4-byte sequence
                    codepoint = ((c & 0x07) << 18) | ((line[i+1] & 0x3F) << 12) |
                                ((line[i+2] & 0x3F) << 6) | (line[i+3] & 0x3F);
                    seq_len = 4;
                }

                if (seq_len > 0 && char_changes.count(codepoint)) {
                    line.replace(i, seq_len, 1, char_changes[codepoint]);
                    changed = true;
                    i++;
                } else {
                    i += seq_len > 0 ? seq_len : 1;
                }
            }
        }

        processed_content += line + "\n";
    }

    // Trim trailing whitespace
    while (!processed_content.empty() && 
          (processed_content.back() == '\n' || 
           processed_content.back() == '\t' || 
           processed_content.back() == ' ')) {
        processed_content.pop_back();
    }

    // Ensure output directory exists
    fs::path out_path(output_path);
    fs::create_directories(out_path.parent_path());

    // Write output
    std::ofstream out(output_path, std::ios::binary);
    if (!out) {
        std::cerr << "Error creating output file: " << output_path << std::endl;
        return false;
    }
    out << processed_content;
    out.close();

    return changed;
}

string get_tex(const vector<pair<string, vector<pair<string, string>>>>& sections) {
    string tex;
    for(auto& [section_name, subsections] : sections) if(!subsections.empty()){
        tex += "\\section{" + texify(section_name) + "}\n";
        
        for(auto [filename, subsection_name] : subsections) {
            string full_path = code_dir + "/" + filename;
            cout << full_path << endl;

            string newpath = "./temp/" + filename;
            convert_files(full_path, newpath);
            full_path = newpath;

            tex += "\\subsection{" + texify(subsection_name) + "}\n";
            tex += "\\raggedbottom\\lstinputlisting[style="+get_style(filename) + "]{" + full_path + "}\n";
            tex += "\\hrulefill\n";
        }
        tex += "\n";
    }
    return tex;
}



int main() {
    cout << title << endl;
    
    auto sections = get_sections();
    string tex = get_tex(sections);
    
    ofstream out("contents.tex");
    if(out.is_open()) out << tex;
    else {
        cerr << "Error writing contents.tex" << endl;
        return 1;
    }
    
    return 0;
}