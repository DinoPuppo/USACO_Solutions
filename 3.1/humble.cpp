/*
 ID: dinovin1
 PROG: humble
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

#define INF 2147483647
#define Pi acos(-1.0)
#define LL long long

#define Set(a, s) memset(a, s, sizeof (a))
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)


using namespace std;

int pn,p[101],n;
set<int> si;
size_t factors[101];
vector<size_t> z;

bool s(size_t n, size_t total) {
    for (size_t i=0; i<total; i++)
        while(n%factors[i]==0)
            n/=factors[i];
    return n==1;
}

int main() {
    
    ifstream cin("humble.in");
    ofstream cout("humble.out");
    cin >> pn >> n;
    for(int i=0;i!=pn;i++)
    {
        cin >> p[i];
        si.insert(p[i]);
    }
    for(int i=0;i!=pn;i++)
    {
        set<int>::iterator it = si.begin();
        while(1)
        {
            int t = (*it)*p[i];
            if(t<0) break;
            if(si.size()>n)
            {
                si.erase(--si.end());
                if(t>(*(--si.end()))) break;
            }
            si.insert(t);
            it++;
        }
    }
    cout << *(--si.end())<< endl;
    return 0;
    
    size_t K, N;
    cin >> K >> N;
    cin.get();
    
    for(int i=0; i<K; i++) {
        cin >> factors[i];
    }
    size_t total =0;
    size_t i=1;
    while(total<N) {
        i++;
        if (find(z.begin(), z.end(), i) == z.end() && s(i,K))
            total++;
        else
            z.push_back(i);
    }
    cout << i << endl;
    return 0;
}
