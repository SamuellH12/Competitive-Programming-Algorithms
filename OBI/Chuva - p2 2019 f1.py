import sys
sys.setrecursionlimit(5000)

n, m = [ int(x) for x in input().split() ]

matriz = []

for i in range(0, n):
    linha = input()
    matriz.append(  list(linha)  )

gota = 0
for i in range(m):
    if matriz[0][i] == 'o':
        gota = i
        break

def percorrerMatriz(l, c): #dfs() deep first search
    matriz[l][c] = 'o'

    if l+1 < n and matriz[l+1][c] == '.':
        percorrerMatriz(l+1, c)
    elif l+1 < n and matriz[l+1][c] == '#':
        if c+1 < m and matriz[l][c+1] != 'o':
            percorrerMatriz(l, c+1)
        if c-1 >= 0 and matriz[l][c-1] != 'o':
            percorrerMatriz(l, c-1)


percorrerMatriz(0, gota)


for i in range(n):
    for j in range(m):
        print( matriz[i][j] , end='')
    print()
