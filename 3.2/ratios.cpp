/*
 ID: dinovin1
 PROG: ratios
 LANG: C++14
*/

#include <fstream>

#define INF 2147483647

using namespace std;
int matrix[3][3];

int main() {
    
    std::ifstream cin("ratios.in");
    std::ofstream cout("ratios.out");
    
    int ratio[3];
    for (int i=0; i<3; i++)
        cin >> ratio[i];
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            cin >> matrix[j][i];
    
    int result = INF;
    int answer[4];
    for (int i=0; i<100; i++)
        for (int j=0; j<100; j++)
            for (int k=0; k<100; k++) {
                if (i==0 && j==0 && k==0)
                    continue;
                int sum1 = matrix[0][0]*i + matrix[0][1]*j + matrix[0][2]*k;
                if (ratio[0]==0 && sum1!=0)
                    continue;
                if (ratio[0]!=0 && sum1%ratio[0]!=0)
                    continue;
                int d = sum1/ratio[0];
                int sum2 = matrix[1][0]*i + matrix[1][1]*j + matrix[1][2]*k;
                if (ratio[1]==0 && sum2!=0)
                    continue;
                if (ratio[1]!=0 && (sum2%ratio[1]!=0 || sum2/ratio[1]!=d))
                    continue;
                int sum3 = matrix[2][0]*i + matrix[2][1]*j + matrix[2][2]*k;
                if (ratio[2]==0 && sum3!=0)
                    continue;
                if (ratio[2]!=0 && (sum3%ratio[2]!=0 || sum3/ratio[2]!=d))
                    continue;
                if (result > (ratio[0]==0? 0:sum1/ratio[0])+(ratio[1]==0? 0:sum2/ratio[1])+(ratio[2]==0? 0:sum3/ratio[2])) {
                    result = (ratio[0]==0? 0:sum1/ratio[0])+(ratio[1]==0? 0:sum2/ratio[1])+(ratio[2]==0? 0:sum3/ratio[2]);
                    answer[0] = i;
                    answer[1] = j;
                    answer[2] = k;
                    answer[3] = d;
                }
                
            }
    if (result == INF)
        cout << "NONE" << std::endl;
    else{
        for (int i=0; i<3; i++)
            cout << answer[i] << " ";
        cout << answer[3] << std::endl;
    }
    return 0;
}
