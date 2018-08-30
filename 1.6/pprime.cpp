/*
 ID: dinovin1
 PROG: pprime
 LANG: C++14
 */

#include <fstream>
#include <set>
using namespace std;

int a, b;
set<int> result = {5, 7, 11};

bool isPrime(int number)
{
    if (number==1||number%2==0)
        return false;
    for(int i=3; (i*i)<=number; i+=2)
        if(number%i == 0)
            return false;
    return true;
}

int main()
{
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    fin >> a >> b;
    for (int d1 = 1; d1 <= 9; d1+=2)
        for (int d2 = 0; d2 <= 9; d2++) {
            result.insert(100*d1 + 10*d2 + d1);
        }
    for (int d1 = 1; d1 <= 9; d1+=2)
        for (int d2 = 0; d2 <= 9; d2++)
            for (int d3 = 0; d3 <= 9; d3++) {
                result.insert(10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1);
            }
    for (int d1 = 1; d1 <= 9; d1+=2)
        for (int d2 = 0; d2 <= 9; d2++)
            for (int d3 = 0; d3 <= 9; d3++)
                for (int d4 = 0; d4 <= 9; d4++) {
                    result.insert(1000000*d1 + 100000*d2 +10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1);
                }
    for(int item: result)
        if (item >= a && item <= b && isPrime(item))
            fout << item << endl;
    return 0;
}
