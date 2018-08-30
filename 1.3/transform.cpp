/*
 ID: dinovin1
 PROG: transform
 LANG: C++
 */

#include <fstream>
using namespace std;

int main() {
    ifstream in("transform.in");
    ofstream out("transform.out");
    int N, i ,j, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
    in >> N;
    char before[N][N], after[N][N];
    for(i = 0; i < N; i++) for (j = 0; j < N; j++) in >> before[i][j];
    for(i = 0; i < N; i++) for (j = 0; j < N; j++) in >> after[i][j];
    for(i = 0; i < N; i++) for (j = 0; j < N; j++) {
        if (before[i][j] == after[j][N-i-1]) a++;
        if (before[i][j] == after[N-i-1][N-j-1]) b++;
        if (before[i][j] == after[N-j-1][i]) c++;
        if (before[i][j] == after[i][N-j-1]) d++;
        if (before[i][j] == after[N-j-1][N-i-1]) e++;
        if (before[i][j] == after[N-i-1][j]) f++;
        if (before[i][j] == after[j][i]) g++;
        if (before[i][j] == after[i][j]) h++;
    }
    if (a == N*N) out << "1\n";
    else if (b == N*N) out << "2\n";
    else if (c == N*N) out << "3\n";
    else if (d == N*N) out << "4\n";
    else if (e == N*N || f == N*N || g == N*N) out << "5\n";
    else if (h == N*N ) out << "6\n";
    else out << "7\n";
}