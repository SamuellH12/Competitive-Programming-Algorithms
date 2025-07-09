import os

code_dir = "../Library"
extra_dir = "./extra" # const
div_char = '$'

print(div_char)
print("# First line is the divisor character used to separate the file name from it's title!!!\n# Don't change the first line!!!")


note = f'''
# Any line followed by a '#' character is ignored
# Section headings must be in square brackets
# Subsections within a section should follow the format:
# (filename within code directory)(divisor character:{div_char})(subsection title)
# div character:{div_char}

# If you add an '@' at the end of a file title, that file will not be hashed, even if use_hash is true.
'''
print(note)

for dir in os.listdir(code_dir):
    if(os.path.isfile(os.path.join(code_dir, dir))): continue
    files = os.listdir(os.path.join(code_dir, dir))
    if(len(files) == 0): continue
    
    print(f'[{dir}]')
    longestPath = max([len(arquivo) if '.exe' not in arquivo else 0 for arquivo in files])
    for arquivo in files:
        if('.exe' in arquivo): continue
        print(f"{code_dir}/{dir}/{arquivo} {' '*(longestPath-len(arquivo))} {div_char} {arquivo.split('.')[0]}")
                
    print()

print()
print("## Extra content - tex files ##")
print('[Extra]')

for arquivo in os.listdir(extra_dir):
    longestName = max([len(arquivo) if '.exe' not in arquivo else 0 for arquivo in files])
    if(os.path.isfile(os.path.join(extra_dir, arquivo))):
        print(f"{extra_dir}/{arquivo} {' '*(longestPath-len(arquivo))} {div_char}tex")
