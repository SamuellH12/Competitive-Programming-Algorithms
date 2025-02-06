#  https://codeforces.com/contest/1899/problem/D
import math

t = int(input())

while(t > 0):
    t -= 1

    n = int(input())

    occ = {}
    ans = 0

    lista = input().split()

    for x in lista:
        x = int(x)

        temp = x - math.log2(x)

        if( temp not in occ ):
            occ[temp] = 0

        ans += occ[temp]

        occ[temp] += 1


    print(ans)