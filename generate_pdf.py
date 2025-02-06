#!/usr/bin/python
# Credit for this file goes to the Stanford University ACM team

import subprocess
code_dir = "Library"
title = "SamuellH12 - ICPC Library"

print(title)

def get_sections():
    sections = []
    section_name = None
    with open('contents.txt', 'r', encoding="utf-16") as f:
        for line in f:
            if '#' in line: continue
            line = line.strip()
            if len(line) == 0: continue
            if line[0] == '[':
                section_name = line[1:-1]
                subsections = []
                if section_name is not None:
                    sections.append((section_name, subsections))
            else:
                tmp = line.split('\t', 1)
                if len(tmp) == 1: raise ValueError('Subsection parse error: %s' % line)
                filename = tmp[0]
                subsection_name = tmp[1]
                if section_name is None:
                    raise ValueError('Subsection given without section')
                subsections.append((filename, subsection_name))
    return sections

def get_style(filename):
    ext = filename.lower().split('.')[-1]
    if ext in ['c', 'cc', 'cpp']:
        return 'cpp'
    elif ext in ['java']:
        return 'java'
    elif ext in ['py']:
        return 'py'
    else:
        return 'txt'

# TODO: check if this is everything we need
def texify(s):
    #s = s.replace('\'', '\\\'')
    #s = s.replace('\"', '\\\"')
    return s

def get_firstline(path): # to ignore #include <bits/stdc++.h> and namespace std
    ln = 1
    with open(path, 'r') as f:
        for line in f:
            if ('#include <bits/stdc++.h>' not in line) and ('using namespace std;' not in line):
                if len(line) > 0:
                    break
            ln += 1
    return ln

def get_tex(sections):
    tex = ''
    for (section_name, subsections) in sections:
        tex += '\\section{%s}\n' % texify(section_name)
        for (filename, subsection_name) in subsections:
            frstline = str(get_firstline(f"{code_dir}\\{filename}"))
            print(f"{code_dir}/{filename} {frstline}")
            tex += '\\subsection{%s}\n' % texify(subsection_name)
            tex += '\\raggedbottom\\lstinputlisting[style=%s, firstline=%s]{%s/%s}\n' % (get_style(filename), frstline, code_dir, filename)
            tex += '\\hrulefill\n'
        tex += '\n'
    return tex

import os
if __name__ == "__main__":
    sections = get_sections()
    tex = get_tex(sections)
    print("ok ok?")
    with open('contents.tex', 'w') as f:
        f.write(tex)
    os.system("pdflatex notebook.tex")
    os.system("latexmk -pdf -f notebook.tex")
    os.system("mv notebook.pdf SH12-Notebook.pdf")
    os.system("rm contents.tex")
    os.system("mv notebook.tex _notebook.tex")
    os.system("rm notebook.*")
    os.system("mv _notebook.tex notebook.tex")

