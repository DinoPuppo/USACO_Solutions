/*
 ID: dinovin1
 PROG: palsquare
 LANG: C++
 */

#include <fstream>
using namespace std;

string reverse(string str)
{
    for (int i=0; i<str.length()/2; i++)
        swap(str[i], str[str.length()-i-1]);
    return str;
}

string change_base(int num, int base) {
    string result = "";
    while (num > 0) {
        result = char(48 + num%base + (num%base/10)*7) + result;
        num = (num - num%base)/base;
    }
    return result;
}

int main() {
    ifstream in("palsquare.in");
    ofstream out("palsquare.out");
    int base;
    in >> base;
    for (int i = 1; i < 300; i++)
        if (change_base(i*i, base) == reverse(change_base(i*i, base)))
            out << change_base(i, base) << " " << change_base(i*i, base) << endl;
}