#include <bits/stdc++.h>
using namespace std;

/*BLOCK_DESC_BEGIN converts Gregorian date to integer (Julian day number) BLOCK_DESC_END*/
int dateToInt (int m, int d, int y){ return 
    + 1461 * (y + 4800 + (m - 14) / 12) / 4 
    + 367  * (m - 2    - (m - 14) / 12  * 12)  / 12 
    - 3    *((y + 4900 + (m - 14) / 12) / 100) / 4 
    + d - 32075;
}

/*BLOCK_DESC_BEGIN converts integer (Julian day number) to Gregorian date: day/month/year BLOCK_DESC_END*/
tuple<int, int, int> intToDate(int jd){
    int x, n, i, j, d, m, y;
    x = jd + 68569;
    n = 4 * x / 146097;
    x -= (146097 * n + 3) / 4;
    i = (4000 * (x + 1)) / 1461001;
    x -= 1461 * i / 4 - 31;
    j = 80 * x / 2447;
    d = x - 2447 * j / 80;
    x = j / 11;
    m = j + 2 - 12 * x;
    y = 100 * (n - 49) + i + x;
    return {d, m, y};
}

/*BLOCK_DESC_BEGIN converts integer (Julian day number) to day of week BLOCK_DESC_END*/
string dayOfWeek[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
string intToWeek (int jd){ return dayOfWeek[jd % 7]; }


//Credits: https://github.com/gabrielpessoa1/ICPC-Library/blob/master/code/Miscellaneous/Dates.cpp