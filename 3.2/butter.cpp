/*
 ID: dinovin1
 PROG: butter
 LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 801;
const int INF = 1<<20;
int n,p,c;
int m[MAX][MAX];
int d[MAX][MAX];
int cow[MAX];
vector<int> con[MAX];

void SPFA(int v0)
{
    queue<int> Q;
    bool v[MAX]={0};
    Q.push(v0);
    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for(int i=0;i!=con[cur].size();i++)
        {
            int cp = con[cur][i]; // connected point
            if(d[v0][cur]+m[cur][cp] < d[v0][cp])
            {
                d[v0][cp] = d[v0][cur]+m[cur][cp];
                if(!v[cp])
                {
                    Q.push(cp);
                    v[cp]=1;
                }
            }
        }
        v[cur] = 0;
    }
}

int main()
{
#ifndef LOCAL
    ifstream cin("butter.in");
    ofstream cout("butter.out");
#endif
    cin >> n >> p >> c;
    for(int i=0;i!=n;i++)
        cin >> cow[i];
    int x,y,dis;
    for(int i=1;i<=c;i++)
    {
        cin >> x >> y >> dis;
        m[x][y]=m[y][x] = dis;
        con[x].push_back(y);
        con[y].push_back(x);
    }
    for(int i=1;i<=p;i++)
        for(int j=1;j<=p;j++)
            d[i][j] = INF;
    for(int i=1;i<=p;i++)
        m[i][i]=d[i][i]=0;
    for(int i=1;i<=p;i++)
        SPFA(i);
    int min = INF;
    for(int i=1;i<=p;i++)
    {
        int sum =0;
        for(int j=0;j!=n;j++)
            sum+= d[cow[j]][i];
        if (sum<min) min = sum;
    }
    cout << min << endl;
    return 0;
}


/*
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
LL minimumDistance[801][801];
vector<int> con[801];

int main() {
    
    std::ifstream cin("butter.in");
    std::ofstream cout("butter.out");
    
    LL N, P, C;
    LL distance[801][801];
    LL numCows[801]{0};
    
    cin >> N >> P >> C;
    
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        numCows[temp]++;
    }
    
    for (int i=1; i<=P; i++)
        for (int j=1; j<=P; j++)
            distance[i][j] = (i==j)? 0: INF;
    
    for (int i=0; i<C; i++) {
        int from, to, value;
        cin >> from >> to >> value;
        distance[from][to] = distance[to][from] = min(value, distance[from][to]);
        con[from].push_back(to);
        con[to].push_back(from);
    }
    
    bool visited[801][801];
    
    
    for (int cur=1; cur<=P; cur++) {
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> temp;
        
        for (int i=0; i<=P; i++)
            visited[cur][i] = false;
        
        for (int i=1; i<=P; i++)
            minimumDistance[cur][i] = (cur==i)? 0: INF;
        
        temp.push(make_pair(0, cur));
        
        while (!temp.empty()) {
            int front = temp.top().second;
            temp.pop();
            if (!visited[cur][front]) {
                visited[cur][front] = true;
                for (int i=0;i!=con[cur].size();i++) {
                    int cp = con[cur][i];
                    if (!visited[cur][cp])
                        if (minimumDistance[cur][cp] > minimumDistance[cur][front] + distance[front][cp]) {
                            minimumDistance[cur][cp] = minimumDistance[cur][front] + distance[front][cp];
                            temp.push(make_pair(minimumDistance[cur][cp], cp));
                        }
                }
            }
        }
    }
    
    int result = INF, minFromPasture=0;
    
    for (int i=1; i<=P; i++) {
        for (int j=1; j<=P; j++) {
            minFromPasture += minimumDistance[i][j]*numCows[j];
        }
        result = min(result, minFromPasture);
        minFromPasture = 0;
    }
    
    cout << result << std::endl;
}*/
/*
int main() {
    
    std::ifstream cin("butter.in");
    std::ofstream cout("butter.out");
    
    LL N, P, C;
    LL distance[801][801];
    LL numCows[801]{0};
    
    cin >> N >> P >> C;
    
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        numCows[temp]++;
    }
    
    for (int i=1; i<=P; i++)
        for (int j=1; j<=P; j++)
            distance[i][j] = (i==j)? 0: INF;
    
    for (int i=0; i<C; i++) {
        int from, to, value;
        cin >> from >> to >> value;
        distance[from][to] = distance[to][from] = min(value, distance[from][to]);
    }
    
    for (int k=1; k<=P; k++)
        for (int i=1; i<=P; i++)
            if (distance[i][k]!=INF)
                for (int j=i; j<=P; j++)
                    distance[i][j] = min(min(distance[i][j], distance[i][k] + distance[k][j]),
                                         min(distance[j][i], distance[j][k] + distance[k][i]));
    
    int result = INF, minFromPasture=0;
    
    for (int i=1; i<=P; i++) {
        for (int j=1; j<=P; j++) {
            minFromPasture += distance[min(i,j)][max(i,j)]*numCows[j];
        }
        result = min(result, minFromPasture);
        minFromPasture = 0;
    }
    
    cout << result << std::endl;

    return 0;
}*/
