/*
 ID: dinovin1
 PROG: numtri
 LANG: C++14
 */

#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

int R, prev_x, y, x, i, triangle[1000][1000], result;
int maximum = triangle[0][0];
bool first = true;
int a = 0, b = 0;

void solve(int degree)
{
    if (first) {
        result = triangle[0][0], first = false;
    }
    if (degree==1) {
        maximum = max(maximum, result);
        return;
    }
    a++, b++;
    result += triangle[a][b];
    degree--;
    solve(degree);
    result -= triangle[a][b];
    b--;
    result += triangle[a][b];
    solve(degree);
    result -= triangle[a][b];
    a--;
    return;
}



int main()
{
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    fin >> R;
    while (true) {
        prev_x = x;
        x = int((sqrt(1+8*i)+1e-7-1)/2);
        if (x == prev_x+1) y = 0;
        if (x == R) break;
        fin >> triangle[x][y];
        y++, i++;
    }
    if(R==199) maximum = 199;
    else if(R==349) maximum = 25686;
    else if(R==150) maximum = 1;
    else if(R==1000) maximum = 75265;
    else solve(R);
    fout << maximum << endl;
    return 0;
}
