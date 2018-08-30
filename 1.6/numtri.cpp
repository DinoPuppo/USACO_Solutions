/*
 ID: dinovin1
 PROG: numtri
 LANG: C++14
 */

#include <fstream>
using namespace std;

int R, triangle[1001][1001];

int main()
{
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    fin >> R;
    for (int i=0; i<R; i++)
        for (int j=0; j<=i; j++)
            fin >> triangle[i][j];
    for (int i=R-1; i>=1; i--)
        for (int j=0; j<i; j++)
            triangle[i-1][j] += max(triangle[i][j], triangle[i][j+1]);
    fout << triangle[0][0] << endl;
    return 0;
}