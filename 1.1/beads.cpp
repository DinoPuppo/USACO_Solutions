/*
 ID: dinovin1
 PROG: beads
 LANG: C++
 */

#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string reverse(string str)
{
    for (int i=0; i<str.length()/2; i++)
        swap(str[i], str[str.length()-i-1]);
    return str;
}

bool algorithm(string s)
{
    return (int(s.find("b")) == -1 || int(s.find("r")) == -1 || s.length()-1 <= reverse(s).find("r") + s.find("b") || s.length()-1 <= reverse(s).find("b") + s.find("r"));
}

int main()
{
    ifstream in("beads.in");
    ofstream out("beads.out");
    int N, i;
    bool stop = false;
    string s;
    in >> N >> s;
    s += s;
    for (i = 2*N; i > 0; i--) {
        for (int j = 0; j < 2*N + 1 - i; j++)
            if (algorithm(s.substr(j, i)))
                if !(i > N) {
                    stop = true;
                    break;
                }
        if (stop) break;
    }
    out << i << endl;
}