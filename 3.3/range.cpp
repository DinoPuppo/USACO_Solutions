/*
 ID: dinovin1
 PROG: game1
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

std::vector<int> board;
int size;

std::pair<int, int> strategy(int index)
{
    int right=index, left=index;
    int score1=0, score2=0;
    if(size%2)
    {
        score1=board[index];
        if(index!=size-1 && index!=0)
        {
            if(board[index+1]>board[index-1])
            {
                score2=board[index+1];
                right++;
            } else{
                score2=board[index-1];
                left--;
            }
        } else if(index==0)
        {
            score2=board[index+1];
            right++;
        } else if(index==size-1)
        {
            score2=board[index-1];
            left--;
        }
    }
    else{
        score2=board[index];
    }
    
    while(right+2<size && left-2>=0)
    {
        if(board[right+1]>board[left-1]){
            score1+=board[right+1];
            score2+=board[right+2];
            right+=2;
        }
        else{
            score1+=board[left-1];
            score2+=board[left-2];
            left-=2;
        }
    }
    while(right+2==size && left-2>=0)
    {
        if(board[right+1]>board[left-1])
        {
            score1+=board[right+1];
            right++;
            score2+=board[left-1];
            left--;
        }
        else{
            score1+=board[left-1];
            score2+=board[left-2];
            left-=2;
        }
    }
    while(left-2==0 && right+2<size)
    {
        if(board[left-1]>board[right+1])
        {
            score1+=board[left-1];
            score2+=board[right+1];
            left--;
            right++;
        }
        else{
            score1+=board[right+1];
            score2+=board[right+2];
            right+=2;
        }
    }
    while(left>=2)
    {
        score1+=board[left-1];
        score2+=board[left-2];
        left-=2;
    }
    while(right<size-2)
    {
        score1+=board[right+1];
        score2+=board[right+2];
        right+=2;
    }
    if(left==1&&right==size-2)
    {
        if(board[0]>board[size-1])
        {
            score1+=board[0];
            score2+=board[size-1];
        }else{
            score1+=board[size-1];
            score2+=board[0];
        }
        left=0;
        right=size-1;
    }
    if (left==1)
    {
        score1+=board[0];
    }
    if(right==size-2)
    {
        score1+=board[size-1];
    }
    
    return std::pair<int, int>(score1,score2);
}

int main()
{
    std::ifstream cin("game1.in");
    std::ofstream cout("game1.out");
    
    cin >> size;
    for(int i=0; i<size; i++){
        int num;
        cin >> num;
        board.push_back(num);
    }
    int maximum=0, minimum=INF;
    for(int i=0; i<size; i++) {
        maximum = max(maximum, strategy(i).first);
        minimum = min(minimum, strategy(i).second);
    }
    cout << maximum << " " << minimum << std::endl;
    return 0;
}
