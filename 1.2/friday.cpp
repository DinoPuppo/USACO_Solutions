/*
 ID: dinovin1
 PROG: friday
 LANG: C++
 */

#include <fstream>
using namespace std;

int main() {
    ifstream in("friday.in");
    ofstream out("friday.out");
    int N, day[7] = {0}, k = 0, year = 1900;
    in >> N;
    while (year < 1900 + N) {
        day[k%7]++;
        k += 3;
        day[k%7]++;
        k += (year%400 != 100 && year%400 != 200 && year%400 != 300 && year%4 == 0)? 1: 0;
        day[k%7]++;
        k += 3;
        day[k%7]++;
        k += 2;
        day[k%7]++;
        k += 3;
        day[k%7]++;
        k += 2;
        day[k%7]++;
        k += 3;
        day[k%7]++;
        k += 3;
        day[k%7]++;
        k += 2;
        day[k%7]++;
        k += 3;
        day[k%7]++;
        k += 2;
        day[k%7]++;
        k += 3;
        year++;
    }
    for (int z = 0; z < 6; z++)
        out << day[z] << " ";
    out << day[6] << endl;
}

