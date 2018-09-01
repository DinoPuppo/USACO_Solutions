/*
 ID: dinovin1
 PROG: stamps
 LANG: C++14
*/

#include <iostream>
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

using namespace std;

int main() {
    
    ifstream cin("stamps.in");
    ofstream cout("stamps.out");
    int K, N;
    cin >> K >> N;
    int values[50]{0};
    int combinations[200*10000]{0};
    for (int i=0; i<N; i++)
        cin >> values[i];
    int i;
    for(i=1; i<=K*10000; i++)
    {
        combinations[i]=K*10000;
        for(int j=0; j!=N; j++)
            if(values[j]<=i)
                if(combinations[i]>combinations[i-values[j]]+1)
                    combinations[i]=combinations[i-values[j]]+1;
        if(combinations[i]>K)
            break;
    }
    cout << i-1 << endl;

    return 0;
}