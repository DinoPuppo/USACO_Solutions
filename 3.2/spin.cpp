/*
 ID: dinovin1
 PROG: spin
 LANG: C++14
*/
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <iterator>

#define INF 2147483647
#define Pi acos(-1.0)
#define LL long long
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)

using namespace std;

bool isInRange(std::pair<int, int> range, int angle)
{
    if (angle==range.first||angle==range.second)
        return true;
    if (range.first > range.second) {
        return !isInRange(make_pair(range.second, range.first), angle);
    }
    return angle>=range.first && angle<=range.second;
}

int main() {
    
    std::ifstream cin("spin.in");
    std::ofstream cout("spin.out");
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> list;
    //std::cout << isInRange(make_pair(201, 200), 4);
    for (int i=0; i<5; i++)
    {
        int speed, numWheels, start, extent;
        cin >> speed >> numWheels;
        for (int j=0; j<numWheels; j++) {
            cin >> start >> extent;
            list.push_back(make_pair(make_pair(start, (start+extent)%360), make_pair(i, speed)));
        }
    }
    for (int i=0; i<360; i++)
    {
        for (int j=0; j<360; j++) {
            int record[5]{0};
            for (int k=0; k<list.size(); k++) {
                if (isInRange(list[k].first, j))
                    record[list[k].second.first]=1;
            }
            if (record[0]+record[1]+record[2]+record[3]+record[4]==5) {
                cout << i << std::endl;
                return 0;
            }
        }
        for (int j=0; j<list.size(); j++) {
            list[j].first.first = (list[j].first.first + list[j].second.second)%360;
            list[j].first.second = (list[j].first.second + list[j].second.second)%360;
        }
    }
    cout << "none" << std::endl;
    return 0;
}
