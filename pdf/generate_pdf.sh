#!/bin/bash

# python3 generate_pdf.py
g++ -std=c++17 -o genLatex generate_latex.cpp -O2
./genLatex

pdflatex notebook.tex
latexmk -pdf -f notebook.tex
mv notebook.pdf ../SH12-Notebook.pdf
rm contents.tex
mv notebook.tex _notebook.tex
rm notebook.*
mv _notebook.tex notebook.tex
rm genLatex.exe
rm ./temp -r