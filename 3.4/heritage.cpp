/*
ID: dinovin1
PROG: heritage
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <fstream>
#include <stack>
using namespace std;

int main()
{
    std::ifstream cin("heritage.in");
    std::ofstream cout("heritage.out");
    std::stack<char> myStack;
    std::string in, pre;
    getline(cin, in);
    getline(cin, pre);
    int count=0;
    while(count<in.length())
    {
        char cur = in[count];
        if(myStack.empty() || pre.find(cur)>pre.find(myStack.top())) {
            myStack.push(cur);
        }
        else {
            while(!(myStack.empty() || pre.find(cur)>pre.find(myStack.top()))) {
            cout << myStack.top();
            myStack.pop();
            }
            myStack.push(cur);
        }
        count++;
    }
    while(!myStack.empty())
    {
        cout << myStack.top();
        myStack.pop();
    }
    cout << endl;
    return 0;
}
