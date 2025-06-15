## 📄 Gerar PDF

Para gerar o pdf execute o script shell.

Windows:
```shell
sh .\generate_pdf.sh
```

Ou linux:
```shell
.\generate_pdf.sh
```

Necessário que haja suporte para C++ e Latex!

```shell
g++
pdflatex
latexmk 
```

## 📑 Escolher códigos que serão incluídos no PDF 

Para escolher o que entra no pdf ou não, edite o arquivo [contents.txt](contents.txt).

Para remover algum dos códigos do PDF, remova ou comente a linha dele com ```#```.

Para gerar novamente a lista com todos os códigos e extras, rode:
```shell
python3 .\getContents.py
```

## 📚 Extras

Você pode criar e adicionar também trechos em latex colocando o arquivo ```.tex``` desejado na pasta [extra](./extra).

Ele irá aparecer no arquivo contents e você também pode controlar o que será ou não adicionado.

## 🛠 Personalizações 

Edite o arquivo [generate_latex.cpp](generate_latex.cpp) para alterar opções como:

- IGNORED_LINES: ignora **linhas inteiras** com determinados valores de substring (ex: ```#include <bits/stdc++.h>"```, ```"using namespace std;```, ```#define pii pair<int, int>```).Cuidado para não remover algo que você não gostaria que fosse removido.
  
- IGNORED_SUBSTRINGS: ignora substrings específicas no código (ex: ```std::```).

- Caracteres alterados: caracteres latinos como à, ã, é, ç, etc... são alterados para a, e, c e etc, para evitar conflitos com o LaTex e caracteres .

- Descrição: O código interpreta trechos do arquivo do código como descrição e adiciona essa descrição no pdf em uma caixa logo antes do código. Mais especificamente trechos entre comentários específicos: ```/*LATEX_DESC_BEGIN  Isso é uma descrição!  LATEX_DESC_END*/```. Para permitir ou não, altere ```bool ADD_DESC = true;```. Algumas formatações suportadas:
  - **bold** com `**bold**`
  - *Itálico* com `_.Italico_.`
  - `código inline` com ``` `codigo inline` ```
  - Potência `N^2` e subscrito `x._k`
  - Escape char `@` para usar LaTex na descrição. Exemplo:
```cpp
/*LATEX_DESC_BEGIN 
    Aqui está um exemplo para adicionar uma imagem na descrição.
    @\begin{center}
        \includegraphics[height=0.3\linewidth]{ascii-art.png}
        \centering\vspace{-3pt}\footnotesize\textit{}
    \end{center}@
LATEX_DESC_END*/
```

### ~~Hash~~

Não consegui terminar os códigos para adicionar o hash das linhas de código na lib. Mas sinta-se a vontade para contribuir.

<hr>

Esse código foi inspirado em alguns geradores de lib e latex famosos da comunidade, assim como adicionei novas funcionalidades. Sinta-se livre para copiar e modificar esse código também. =]

## 🦕🦖