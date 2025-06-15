import os
import re

# Configurações
code_dir = "../Library"  # Pasta onde estão os códigos
readme_file = "../README.md"  # Arquivo README
index_start = "<!--- BEGIN OF INDEX -->"
index_end = "<!--- END OF INDEX -->"

def generate_index():
    sections = {}
    
    # Organiza por seções (pastas)
    for dir_name in sorted(os.listdir(code_dir)):
        dir_path = os.path.join(code_dir, dir_name)
        if not os.path.isdir(dir_path):
            continue
            
        files = []
        for file_name in sorted(os.listdir(dir_path)):
            if file_name.endswith('.cpp') or file_name.endswith('.py'):
                file_name_clean = file_name.replace('.cpp', '').replace('.py', '')
                files.append((file_name, file_name_clean))
        
        if files:
            sections[dir_name] = files
    
    # Gera o markdown
    md_content = ""
    for section, files in sections.items():
        md_content += f"\n### {section}\n\n"
        for file_name, file_name_clean in files:
            md_content += f"- [{file_name_clean}](./{os.path.join('Library', section, file_name)})\n"
    
    return md_content

def update_readme():
    with open(readme_file, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Encontra a seção do índice
    start_pos = content.find(index_start)
    end_pos = content.find(index_end)
    
    if start_pos == -1 or end_pos == -1:
        print("Marcadores de índice não encontrados no README.md")
        return
    
    new_content = (
        content[:start_pos + len(index_start)] + 
        "\n" + generate_index() + 
        "\n" + content[end_pos:]
    )
    
    with open(readme_file, 'w', encoding='utf-8') as f:
        f.write(new_content)
    
    print("README.md atualizado com sucesso!")

if __name__ == "__main__":
    update_readme()