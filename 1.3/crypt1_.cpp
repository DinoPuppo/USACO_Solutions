/*
 ID: dinovin1
 PROG: crypt1
 LANG: C++
 */

#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

bool valid(int a, vector<int> number) {
    string y;
    stringstream ss;
    ss << a;
    y = ss.str();
    for (int i = 0; i< number.size(); i++)
        y.erase(remove(y.begin(), y.end(), char(number[i]+48)), y.end());
    return y.length() == 0;
}

int main() {
    ifstream in("crypt1.in");
    ofstream out("crypt1.out");
    vector<int> number, a, b;
    int total, current, result = 0;
    in >> total;
    for(int i = 0; i < total; i++) {
        in >> current;
        number.push_back(current);
    }
    for(int i = 0; i < total; i++)
        for(int j = 0; j < total; j++) {
            b.push_back(number[i]*10 + number[j]);
            for(int k = 0; k < total; k++)
                a.push_back(number[i]*100 + number[j]*10 + number[k]);
        }
    for(int i = 0; i < total; i++)
        for(int j = 0; j < total; j++)
            if(valid(a[i]*b[j], number)&&valid(a[i]*(b[j]%10), number)&&valid(a[i]*(b[j]/10), number)) result++;
    out << result << endl;
}