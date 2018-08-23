/*
 ID: dinovin1
 PROG: nocows
 LANG: C++14
 */

#include <iostream>
#include <fstream>
using namespace std;

int N, K, dp[200][100];

int main()
{
    ifstream cin("nocows.in");
    ofstream cout("nocows.out");
    cin >> N >> K;
    for (int i=1; i<100; i++)
        dp[1][i]=1;
    for (int k=1; k<=K; k++)
        for (int n=3; n<=N; n+=2)
            for (int i=1; i<=n-1; i++)
                dp[n][k] += (dp[n-i-1][k-1]%9901)*(dp[i][k-1]%9901);
    cout << ((dp[N][K]-dp[N][K-1])%9901+9901)%9901 << endl;
    return 0;
}