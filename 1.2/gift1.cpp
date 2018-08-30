/*
 ID: dinovin1
 PROG: gift1
 LANG: C++
 */

#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct account
{
    string name;
    int money = 0;
};

int search(account array[], string name, int size)
{
    int loc = -1;
    for (int i = 0; i < size; i++)
        if (array[i].name == name)
            loc = i;
    return loc;
}


int main() {
    ifstream in("gift1.in");
    ofstream out("gift1.out");
    int size, amount = 0, to_give = 0;
    string name, name_;
    in >> size;
    account *balance = new account[size];
    for(int i = 0; i < size; i++)
        in >> balance[i].name;
    for(int j = 0; j < size; j++){
        in >> name >> amount >> to_give;
        balance[search(balance, name, size)].money += (to_give == 0)? amount: -amount + amount%to_give;
        for(int k = 0; k < to_give; k++) {
            in >> name_;
            balance[search(balance, name_, size)].money += amount/to_give;
        }
    }
    for(int l = 0; l<size; l++)
        out << balance[l].name << " " << balance[l].money << endl;
}