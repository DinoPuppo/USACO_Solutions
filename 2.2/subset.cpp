/*
 ID: dinovin1
 PROG: subset
 LANG: C++14
 */

#include <fstream>
using namespace std;

ifstream cin("subset.in");
ofstream cout("subset.out");
int N=0;
long long ways[800];

int main()
{
    ways[0]=1;
    cin >> N;
    if (((N*(N+1))/2)%2 == 1) {
        cout << "0" << endl;
        return 0;
    }
    for (int i = 1; i <= N; i++)
        for (int j = (N*(N+1))/2 - i; j >= 0; --j)
            ways[j + i] += ways[j];
    cout << ways[(N*(N+1))/2/2]/2 << endl;
    return 0;
}