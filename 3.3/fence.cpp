/*
 ID: dinovin1
 PROG: fence
 LANG: C++14
*/

//#include <iostream>
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

int size;
//std::vector<std::priority_queue<int, std::vector<int>, std::greater<int>>> graph;
std::vector<std::multiset<int>> graph;
std::vector<int> circuit;

void find_circuit(int node)
{
    while (graph[node].size()) {
        int next = *graph[node].begin();
        graph[node].erase(graph[node].begin());
        graph[next].erase(graph[next].lower_bound(node));
        find_circuit(next);
    }
    circuit.insert(circuit.begin(), node);
}

int main()
{
    std::ifstream cin("fence.in");
    std::ofstream cout("fence.out");
    
    cin >> size;
    graph.resize(510);
    int from, to;
    int i=0;
    while(i!=size)
    {
        cin >> from >> to;
        graph[from].insert(to);
        graph[to].insert(from);
        i++;
    }
    graph.shrink_to_fit();
    int start = 1;
    for (int i=0; i<graph.size(); i++)
    {
        if (graph[i].size()%2) {
            start = i;
            break;
        }
    }
    find_circuit(start);
    for(int i: circuit)
        cout << i << endl;
    return 0;
}
