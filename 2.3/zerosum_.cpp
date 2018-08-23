/*
 ID: dinovin1
 PROG: zerosum
 LANG: C++14
*/

#include <iostream>
#include <fstream>
using namespace std;

int N;

void dfs(int number, int sign, int result, string str)
{
    if (number==N) {
        if (result==0)
            cout << str << endl;
        str="1";
        return;
    }
    dfs(number+1, 0, sign? result+sign*(number*10+1): result*10+number+1, str+" "+char(number+'1'));
    dfs(number+1, 1, result+number+1, str+"+"+char(number+'1'));
    dfs(number+1, -1, result-number-1, str+"-"+char(number+'1'));
}

int main()
{
    //ifstream cin("zerosum.in");
    //ofstream cout("zerosum.out");
    cin >> N;
    dfs(1, 1, 1, "1");
    return 0;
}