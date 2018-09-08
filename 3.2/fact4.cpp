/*
 ID: dinovin1
 PROG: fact4
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

LL trim (LL n)
{
    while(n%10==0)
        n/=10;
    return n;
}

int main() {
    
    std::ifstream cin("fact4.in");
    std::ofstream cout("fact4.out");
    
    LL N;
    cin >> N;
    LL trimmed[4221]{1};
    for (int i=1; i<=N; i++) {
        trimmed[i]= (trim(i*trimmed[i-1])%1000000);
    }
    cout << trimmed[N]%10 << std::endl;
    
    return 0;
}
