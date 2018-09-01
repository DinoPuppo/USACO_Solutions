/*
 ID: dinovin1
 PROG: agrinet
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

// Description: Implementation of Prim's algorithm

using namespace std;

int weight[101][101], distanceToTree[101], intree[101];

int main() {
    ifstream cin("agrinet.in");
    ofstream cout("agrinet.out");
    
    int treesize=0, treecost=0, N=0;
    cin >> N;
    cin.get();
    
    for(int i=0; i<N; i++) {
        intree[i] = 0;
        distanceToTree[i] = INF;
        for(int j=0; j<N; j++)
            cin >> weight[i][j];
        cin.get();
    }
    
    intree[0]=1;
    treesize=1;
    for(int i=0; i<N; i++) {
        distanceToTree[i] = weight[0][i];
    }
    
    while(treesize<N) {
        int node=0;
        int minDistance=INF;
        for(int i=0; i<N; i++)
            if (distanceToTree[i]>0 && !intree[i])
                if (distanceToTree[i] < minDistance) {
                    minDistance = distanceToTree[i];
                    node = i;
                }
                
        treecost += distanceToTree[node];
        treesize++;
        intree[node]=1;
        
        for(int i=0; i<N; i++) {
            if(!intree[i]) {
                distanceToTree[i] = min(distanceToTree[i], weight[node][i]);
            }
        }
    }
    cout << treecost << endl;
    return 0;
}
