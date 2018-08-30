/*
 ID: dinovin1
 PROG: sprime
 LANG: C++14
 */

#include <fstream>
#include <vector>
using namespace std;

bool isPrime(int number)
{
    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2)
        if(number%i == 0)
            return false;
    return true;
}

vector<int> solve(int N)
{
    if (N == 1) {
        vector<int> r = {2, 3, 5, 7};
        return r;
    }
    vector<int> previous = solve(N - 1);
    vector<int> current;
    for (int i=0; i<previous.size(); ++i)
        for (int j=1; j<=9; j+=2) {
            int num = previous[i]*10 + j;
            if (isPrime(num))
                current.push_back(num);
        }
    return current;
}

int main()
{
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");
    int N;
    fin >> N;
    vector<int> result = solve(N);
    for (int i=0; i<result.size(); ++i)
        fout << result[i] << endl;
    return 0;
}