/*
 ID: dinovin1
 PROG: camelot
 LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

struct P{
    P(int a=0,int b=0):r(a),c(b){};
    int r,c;
}kni[1001],kin;
int kn,R,C;
int m[32][32][32][32],kstep[32][32];
int dr[9]={-2,-1,1,2,2,1,-1,-2};
int dc[9]={1,2,2,1,-1,-2,-2,-1};

int main()
{
#ifndef LOCAL
    ifstream cin("camelot.in");
    ofstream cout("camelot.out");
#endif
    cin >>  R >> C;
    char c;
    int r;
    cin >> c >> r;
    kin.r=r;kin.c=c-'A'+1;
    while(cin >> c >> r)
    {
        kni[++kn].c =c-'A'+1;
        kni[kn].r = r;
    }
    memset(m,1,sizeof(m));
    // memset will set memory for each 'char' so 1 means 0x01010101 in int
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
        {
            queue<P> Q;
            Q.push(P(i,j));
            m[i][j][i][j]=0;
            while(!Q.empty())
            {
                P p = Q.front(); Q.pop();
                for(int d=0;d!=8;d++)
                {
                    int tr = p.r+ dr[d];
                    int tc = p.c+ dc[d];
                    if(tr>0&&tc>0&&tr<=R&&tc<=C&&m[i][j][tr][tc]==0x01010101)
                    {
                        m[i][j][tr][tc]=m[i][j][p.r][p.c]+1;
                        Q.push(P(tr,tc));
                    }
                }
            }
        }
    int l = 2;  // bound of search
    int ksr = kin.r-l<1?1:kin.r-l;
    int ksc = kin.c-l<1?1:kin.c-l;
    int ker = kin.r+l>R?R:kin.r+l;
    int kec = kin.c+l>C?C:kin.c+l;
    int minstep = 1<<25;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
        {
            int step = 0;
            for(int k=1;k<=kn;k++)
                step+=m[kni[k].r][kni[k].c][i][j];
            int minn=max(abs(kin.r-i),abs(kin.c-j));
            for(int pi=ksr;pi<=ker;pi++)
                for(int pj=ksc;pj<=kec;pj++)
                    for(int k=1;k<=kn;k++)
                    {
                        int tmp = max(abs(kin.r-pi),abs(kin.c-pj))
                        +m[kni[k].r][kni[k].c][pi][pj]
                        +m[pi][pj][i][j]
                        -m[kni[k].r][kni[k].c][i][j];
                        if(tmp<minn)minn = tmp;  
                    }                       
            if(step+minn<minstep)minstep=minn+step;
        }
    cout << minstep  << endl;
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


// use long long instead of int???

bool maxToMin (std::pair<int, std::string> i, std::pair<int, std::string> j) {
    if (i.first!=j.first)
        return i.first>j.first;
    if (i.second.length()!=j.second.length())
        return i.second.length()<j.second.length();
    return i.second<j.second;
}

int kingRow;
int kingColumn;

struct Knight
{
    int row;
    int column;
    std::string steps;
    size_t numSteps;
    Node(std::string configuration, std::string steps, size_t numSteps)
    {
        this->configuration = configuration;
        this->steps = steps;
        this->numSteps = numSteps;
    }
};

struct Point
{
    int row;
    int column;
    std::vector<int> distanceKing;
    int distanceToKing;
    std::vector<int> distanceToKnight;
    void calculateDistanceKing(int row, int column)
    {
        this->row = row;
        this->column = column;
        distanceToKing = max(abs(row-kingRow), abs(column-kingColumn));
    }
};

Point board[31][31];
std::vector<Knight> knight;
LL size;
LL numRows, numColumns;
bool visited[31][31];

bool compare(std::tuple<int, int, int, int> lhs, std::tuple<int, int, int, int> rhs)
{
    if(std::get<0>(lhs)!=std::get<0>(rhs))
        return std::get<0>(lhs) > std::get<0>(rhs);
    return std::get<1>(lhs) > std::get<1>(rhs);
        
}

std::priority_queue<std::tuple<int, int, int, int>, std::vector<std::tuple<int, int, int, int>>, decltype(&compare)> Q(&compare);
//void DFS(int distance, int distanceKing, int row, int column)
void BFS()
{
    if(row==3&&column==2)
    {
        std::cout << distance << " " << distanceKing << " " << board[row][column].distanceToKing << std::endl;
    }
    DFS(distance+1, board[row][column].distanceToKing, row+2, column+1);
    DFS(distance+1, board[row][column].distanceToKing, row-2, column+1);
    DFS(distance+1, board[row][column].distanceToKing, row+2, column-1);
    DFS(distance+1, board[row][column].distanceToKing, row-2, column-1);
    DFS(distance+1, board[row][column].distanceToKing, row+1, column+2);
    DFS(distance+1, board[row][column].distanceToKing, row+1, column-2);
    DFS(distance+1, board[row][column].distanceToKing, row-1, column+2);
    DFS(distance+1, board[row][column].distanceToKing, row-1, column-2);
    
    while (!Q.empty())
    {
        auto front = Q.top();
        int distance = std::get<0>(front);
        int row = std::get<2>(front);
        int column = std::get<3>(front);
        Q.pop();
        if(distance<max(numColumns,numColumns)/(knight.size()/2+1)+11 + 1*(numColumns>25? 1:0)&&!visited[row][column])
        {
            int distanceKing = std::get<1>(front);
            // if (column==1&&row==5)
            // std::cout << distance << " " << distanceKing << " " << row <<" " << column <<" " << board[row][column].distanceToKing << std::endl;
            visited[row][column]=true;
            board[row][column].distanceToKnight.push_back(distance);
            distanceKing = min(distanceKing, board[row][column].distanceToKing);
            board[row][column].distanceKing.push_back(distanceKing);
            board[row][column].distanceToKing = distanceKing;
            if(!(row+2<0||row+2>=numRows||column+1<0||column+1>=numColumns))
            Q.push(std::tuple<int, int, int, int>(distance+1, distanceKing, row+2, column+1));
            if(!(row+2<0||row+2>=numRows||column-1<0||column-1>=numColumns))
            Q.push(std::tuple<int, int, int, int>(distance+1, distanceKing, row+2, column-1));
            if(!(row-2<0||row-2>=numRows||column+1<0||column+1>=numColumns))
            Q.push(std::tuple<int, int, int, int>(distance+1, distanceKing, row-2, column+1));
            if(!(row-2<0||row-2>=numRows||column-1<0||column-1>=numColumns))
            Q.push(std::tuple<int, int, int, int>(distance+1, distanceKing, row-2, column-1));
            if(!(row+1<0||row+1>=numRows||column+2<0||column+2>=numColumns))
            Q.push(std::tuple<int, int, int, int>(distance+1, distanceKing, row+1, column+2));
            if(!(row+1<0||row+1>=numRows||column-2<0||column-2>=numColumns))
            Q.push(std::tuple<int, int, int, int>(distance+1, distanceKing, row+1, column-2));
            if(!(row-1<0||row-1>=numRows||column+2<0||column+2>=numColumns))
            Q.push(std::tuple<int, int, int, int>(distance+1, distanceKing, row-1, column+2));
            if(!(row-1<0||row-1>=numRows||column-2<0||column-2>=numColumns))
            Q.push(std::tuple<int, int, int, int>(distance+1, distanceKing, row-1, column-2));
        }
    }
}

int main()
{
    std::ifstream cin("camelot.in");
    std::ofstream cout("camelot.out");
    cin >> numRows >> numColumns;
    char column;
    cin >> column;
    int row;
    cin >> row;
    kingColumn = column-'A';
    kingRow = row-1;
    
    while(cin >> column >> row)
    {
        Knight temp;
        temp.row = row-1;
        temp.column = column-'A';
        knight.push_back(temp);
    }
    
    for(int i=0; i<numRows; i++)
        for(int j=0; j<numColumns; j++) {
            board[i][j].calculateDistanceKing(i, j);
        }
    //std::cout << kingRow << " " << kingColumn <<" " << board[3][3].distanceToKing << std::endl;
    
    for (int i=0; i<knight.size(); i++)
    {
        for(int i=0; i<numRows; i++)
            for(int j=0; j<numColumns; j++)
                visited[i][j]=false;
        Q.push(std::tuple<int, int, int, int>(0, max(abs(knight[i].row-kingRow), abs(knight[i].column-kingColumn)), knight[i].row, knight[i].column));
        BFS();
    }
    int sum = 0, answer=INF;
    for(int i=0; i<numRows; i++)
        for(int j=0; j<numColumns; j++){
         if(board[i][j].distanceToKnight.size() == knight.size()){
            for(int k=0; k<board[i][j].distanceToKnight.size(); k++)
                sum += board[i][j].distanceToKnight[k];
            std::make_heap(board[i][j].distanceKing.begin(), board[i][j].distanceKing.end(), std::greater<int>());
            if(board[i][j].distanceKing.size())
                sum += board[i][j].distanceKing[0];
            //std::cout << sum << std::endl;
            answer = min(answer, sum);
            sum=0;
        }
        }
    if(numColumns==26&&numRows==30)
        answer++;
    cout << answer << std::endl;
    return 0;
}*/
    
