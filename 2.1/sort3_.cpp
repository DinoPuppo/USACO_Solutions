/*
 ID: dinovin1
 PROG: sort3
 LANG: C++14
 */

#include <fstream>
#include <iostream>
using namespace std;

int N, list[1001], limit[10], number1, number2, number3, cnt=0;

void swap(int x, int y)
{
    for (int i=limit[2*x-1]; i<=limit[2*x]; i++)
        for (int j=limit[2*y-1]; j<=limit[2*y]; j++) {
            if (list[j]==x && list[i]==y) {
                int temp = list[j];
                list[j] = list[i];
                list[i] = temp;
                cnt++;
            }
        }
}

int main()
{
    ifstream cin("sort3.in");
    ofstream cout("sort3.out");
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> list[i];
        if (list[i]==1) number1++;
        if (list[i]==2) number2++;
        if (list[i]==3) number3++;
    }
    limit[1] = number1>0?1:0;
    limit[2] = number1;
    limit[3] = limit[2]+(number2>0?1:0);
    limit[4] = number1+number2;
    limit[5] = limit[4]+(number3>0?1:0);
    limit[6] = number1+number2+number3;
    //cout << limit[1] << limit[2] << limit[3] << limit[4] << limit[5] << limit[6] << endl;
    swap(1,2);
    swap(1,3);
    swap(2,3);
    for (int i=limit[1]; i<=limit[6]; i++)
        if (list[i]==1 && i>=limit[5]) {
            for (int j=limit[1]; j<=limit[2]; j++)
                if (list[j]==2) {
                    int temp = list[j];
                    list[j] = list[i];
                    list[i] = temp;
                    cnt++;
                    break;
                }
        }
    swap(2,3);
    /*for (int i=limit[1]; i<=limit[6]; i++)
     if (list[i]==1 && i>limit[2]) {
     for (int j=limit[1]; j<=limit[2]; j++)
     if(list[j]!=1) {
     int temp = list[j];
     list[j] = list[i];
     list[i] = temp;
     cnt++;
     }
     }
     for (int i=limit[1]; i<=limit[2]; i++)
     if(list[i]!=1)
     for (int j=limit[3]; j<=limit[6]; j++)
     if(list[j]==1) {
     int temp = list[j];
     list[j] = list[i];
     list[i] = temp;
     cnt++;
     }
     for (int i=limit[3]; i<=limit[4]; i++)
     if(list[i]!=2)
     for (int j=limit[5]; j<=limit[6]; j++)
     if(list[j]==2) {
     int temp = list[j];
     list[j] = list[i];
     list[i] = temp;
     cnt++;
     }*/
    
    cout << cnt << endl;
    return 0;
}
