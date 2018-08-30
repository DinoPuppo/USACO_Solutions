/*
 ID: dinovin1
 PROG: combo
 LANG: C++
 */

#include <fstream>
using namespace std;

bool valid(int N, int A, int B, int C, int a, int b, int c, int d, int e, int f)
{
    return ((abs(A-a)%N<3||N-abs(A-a)%N<3)&&(abs(B-b)%N<3||N-abs(B-b)%N<3)&&(abs(C-c)%N<3||N-abs(C-c)%N<3))||((abs(A-d)%N<3||N-abs(A-d)%N<3)&&(abs(B-e)%N<3||N-abs(B-e)%N<3)&&(abs(C-f)%N<3||N-abs(C-f)%N<3));
}

int main()
{
    ifstream in("combo.in");
    ofstream out("combo.out");
    int N, a, b, c, d, e, f, result = 0;
    in >> N >> a >> b >> c >> d >> e >> f;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            for(int k = 1; k <= N; k++)
                if(valid(N, i, j, k, a, b, c, d, e, f))
                    result++;
    out << result << endl;
}