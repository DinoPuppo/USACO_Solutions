/*
 ID: dinovin1
 PROG: concom
 LANG: C++14
 */

#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;

int n, dp[MAX+1][MAX+1];

int main()
{
    ifstream cin("concom.in");
    ofstream cout("concom.out");
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        dp[x][y]=z;
    }
    for (int i=1; i<=MAX; i++)
        for (int j=1; j<=MAX; j++)
            for (int k=1; k<=MAX; k++) {
                if (dp[i][k]>50)
                    dp[i][j] += dp[k][j];
                if (dp[i][j]>50) {
                    cout << i << " " << j << endl;
                    break;
                }
            }
    return 0;
}