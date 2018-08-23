/*
 ID: dinovin1
 PROG: zerosum
 LANG: C++14
*/

//#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream cin("zerosum.in");
ofstream cout("zerosum.out");
int number=1, sign=1, N;

void operation(int sign, int result, string output)
{
    if (number==N) {
        if (result==0)
            cout << output << endl;
        output="1";
        return;
    }
    number++;
    operation(0, !sign? result*10+number: result+sign*(number*10-9), output+" "+to_string(number));
    operation(1, result+number, output+"+"+to_string(number));
    operation(-1, result-number, output+"-"+to_string(number));
    number--;
}

int main()
{
    cin >> N;
    operation(1, 1, "1");
    return 0;
}