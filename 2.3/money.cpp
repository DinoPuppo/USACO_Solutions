/*
 ID: dinovin1
 PROG: money
 LANG: C++14
*/

#include <iostream>
#include <fstream>
using namespace std;

int V, N, coins[25];
long long ways[10000+1]{1};

int main()
{
    ifstream cin("money.in");
    ofstream cout("money.out");
    cin >> V >> N;
    for (int i=0; i<V; i++)
        cin >> coins[i];
    for (int j=0; j<V; j++)
        for (int i=coins[j]; i<=N; i++)
            ways[i] += ways[i-coins[j]];
    cout << ways[N] << endl;
    return 0;
}