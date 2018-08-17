/*
 ID: dinovin1
 PROG: ariprog
 LANG: C++
 */

#include <fstream>
using namespace std;
#define MAX 250

int N, M, bisquare[2*MAX*MAX+1];
bool no_output = true;
ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

void solve()
{
    int starting = 0, difference = 1, length = 0;
    int next = starting;
    while (difference <= 2*M*M/(N-1)) {
        while (next <= 2*M*M) {
            while (next<=2*M*M && length<N && bisquare[next]) {
                length++;
                next += difference;
            }
            if (length == N) {
                no_output = false;
                fout << starting << " " << difference << endl;
            }
            length = 0;
            starting++;
            next = starting;
        }
        next = starting = 0;
        difference++;
    }
}

int main()
{
    fin >> N >> M;
    for(int i=0; i<=M; i++)
        for(int j=0; j<=M; j++)
            bisquare[i*i+j*j] = 1;
    solve();
    if (no_output)
        fout << "NONE\n";
    return 0;
}
