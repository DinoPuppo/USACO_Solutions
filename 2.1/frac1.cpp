/*
 ID: dinovin1
 PROG: frac1
 LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int fraction[161][161], N;
vector<int> result;

void sort(vector<int> &result)
{
    for (int x=0; x <result.size(); x++)
        for (int y=0; y<result.size()-1; y++)
            if ((result[y]/1000)*(result[y+1]%1000) > (result[y+1]/1000)*(result[y]%1000)) {
                int temp = result[y+1];
                result[y+1] = result[y];
                result[y] = temp;
            }
}

int gcd(int a, int b)
{
    return b? gcd(b, a%b): a;
}

int main()
{
    ifstream cin("frac1.in");
    ofstream cout("frac1.out");
    cin >> N;
    for (int j=1; j<=N; j++)
        for (int i=1; i<=j; i++)
            if (gcd(i, j)==1) {
                fraction[i][j] = 1;
                result.push_back(1000*i+j);
            }
    sort(result);
    cout << "0/1" << endl;
    for (int i=0; i<result.size(); i++)
        cout << result[i]/1000 << "/" << result[i]%1000 << endl;
    return 0;
}
