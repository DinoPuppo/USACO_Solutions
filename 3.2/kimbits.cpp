/*
 ID: dinovin1
 PROG: kimbits
 LANG: C++14
*/

#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <iterator>

#define INF 2147483647
#define Pi acos(-1.0)
#define LL long long
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)

int main() {
    
    std::ifstream cin("kimbits.in");
    std::ofstream cout("kimbits.out");
    
    long long dp[34][34]{0}, N, L, I;
    cin >> N >> L >> I;
    for (long i=0; i<=N; i++)
        dp[i][0]=dp[0][i]=1;
    for(long i=1; i<=N; i++)
        for (long j=1; j<=N; j++)
            dp[i][j]= dp[i-1][j]+dp[i-1][j-1];
    I--;
    while (N) {
        if (I>=dp[N-1][L]) {
            I = I - dp[N-1][L];
            L--;
            cout << "1";
        }
        else {
            cout << "0";
        }
        N--;
    }
    cout << std::endl;
    
    return 0;
}
