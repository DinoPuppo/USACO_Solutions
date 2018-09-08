/*
 ID: dinovin1
 PROG: msquare
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

using namespace std;

struct Node
{
    std::string configuration;
    std::string steps;
    size_t numSteps;
    Node(std::string configuration, std::string steps, size_t numSteps)
    {
        this->configuration = configuration;
        this->steps = steps;
        this->numSteps = numSteps;
    }
};

std::string finalStr;
std::queue<Node> Q;
std::set<std::string> S;

Node BFS()
{
    if (finalStr=="12345678")
        return Node("", "", 0);
    
    Q.push(Node("12345678", "", 0));
    S.insert("12345678");
    
    while(!Q.empty())
    {
        Node cur = Q.front();
        Q.pop();
        std::string current = cur.configuration;
        std::string A(current.rbegin(), current.rend());
        if(A==finalStr) return Node(A, cur.steps+"A", cur.numSteps+1);
        if (!S.count(A))
        {
            S.insert(A);
            Q.push(Node(A, cur.steps+"A", cur.numSteps+1));
        }
        std::string B(current[3] + current.substr(0,3) + current.substr(5) + current[4]);
        if(B==finalStr) return Node(B, cur.steps+"B", cur.numSteps+1);
        if (!S.count(B))
        {
            S.insert(B);
            Q.push(Node(B, cur.steps+"B", cur.numSteps+1));
        }
        std::string C(current);
        std::swap(C[1],C[2]);
        std::swap(C[1],C[5]);
        std::swap(C[1],C[6]);
        if(C==finalStr) return Node(C, cur.steps+"C", cur.numSteps+1);
        if (!S.count(C))
        {
            S.insert(C);
            Q.push(Node(C, cur.steps+"C", cur.numSteps+1));
        }
    }
    return Node("","",0);
}

int main()
{
    std::ifstream cin("msquare.in");
    std::ofstream cout("msquare.out");
    
    char in;
    for(int i=0; i!=8; i++){
        cin >> in;
        finalStr += in;
    }
    
    Node n = BFS();
    cout << n.numSteps << std::endl << n.steps << std::endl;
    
    return 0;
}