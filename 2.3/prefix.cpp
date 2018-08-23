/*
 ID: dinovin1
 PROG: prefix
 LANG: C++14
*/

//#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> primitives;
string input;
int lens[200000], answer;

int main()
{
    ifstream cin("prefix.in");
    ofstream cout("prefix.out");
    while (true) {
        string input;
        cin >> input;
        if (input==".")
            break;
        primitives.push_back(input);
    }
    while (cin.good()) {
        string line;
        cin >> line;
        input += line;
    }
    for (int i=0; i<input.length(); i++)
        if (i==0 || lens[i-1]==1) {
            for (int j=0; j<primitives.size(); j++)
                if (primitives[j]==input.substr(i, primitives[j].length())) {
                    lens[i+primitives[j].length()-1] = 1;
                    answer = max(answer, int(i+primitives[j].length()));
                }
        }
    cout << answer << endl;
    return 0;
}