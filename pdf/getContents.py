import os

code_dir = "../Library"

note = '''
# Any line followed by a '#' character is ignored
# Section headings must be in square brackets
# Subsections within a section should follow the format:
#   [filename within code directory][tab character\t][subsection title]
# tab character:	
'''
print(note)

for dir in os.listdir(code_dir):
    if(os.path.isfile(os.path.join(code_dir, dir))): continue
    files = os.listdir(os.path.join(code_dir, dir))
    if(len(files) == 0): continue
    
    print(f'[{dir}]')
    for arquivo in files:
        if('.exe' in arquivo): continue
        print(f"{dir}/{arquivo}\t{arquivo.split('.')[0]}")
                
    print()