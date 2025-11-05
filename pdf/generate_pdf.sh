#!/bin/bash

set -e

g++ -std=c++17 -o genLatex generate_latex.cpp -O3
./genLatex

pdflatex -halt-on-error -file-line-error notebook.tex
latexmk -pdf -f -silent notebook.tex
mv notebook.pdf ../Notebook.pdf
rm contents.tex
mv notebook.tex _notebook.tex
rm notebook.*
mv _notebook.tex notebook.tex
rm genLatex.exe
mv hsh.temp ./temp/h || true
mv temp.cpp ./temp/h || true
rm ./temp -r

echo "
Spinosaurus says: All done! =]
Good luck and good contest!
"