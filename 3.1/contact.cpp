/*
 ID: dinovin1
 PROG: contact
 LANG: C++14
*/

//#include <iostream>
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

std::map<std::string, int> myMap;

bool maxToMin (std::pair<int, std::string> i, std::pair<int, std::string> j) {
    if (i.first!=j.first)
        return i.first>j.first;
    if (i.second.length()!=j.second.length())
        return i.second.length()<j.second.length();
    return i.second<j.second;
}

int main() {
    
    std::ifstream cin("contact.in");
    std::ofstream cout("contact.out");
    
    int A, B, N;
    char c;
    std::string temp;
    cin >> A >> B >> N;
    while(cin.good() && temp.length()!=B) {
        cin >> c;
        if (cin.good())
            temp += c;
    }
    
    while(cin.good() && temp.length()==B) {
        for (int i=A; i<=B; i++)
            myMap[temp.substr(0,i)]++;
        cin >> c;
        if (cin.good()) {
            temp += c;
            temp = temp.substr(1);
        }
    }
    
    while(temp.length()>=A) {
        if (A!=1 || temp.length()!=1)
            temp = temp.substr(1);
        for (int i=A; i<=temp.length(); i++)
            myMap[temp.substr(0,i)]++;
        if (A==1 && temp.length()==1)
            break;
    }
    std::vector<std::pair<int, std::string>> sorted;
    std::map<std::string, int>::iterator s;
    //s = myMap.begin();
    //cout << s->first << " " << s->second << std::endl;
    for (s=myMap.begin(); s!=myMap.end(); ++s)
        sorted.push_back(std::make_pair(s->second, s->first));
    sort(sorted.begin(), sorted.end(), maxToMin);
    int count =0;
    int current=-1, prev=-1;
    for (int i=0, total=0; total<min(N, myMap.size()); total++, i++) {
        if (sorted[i].first==0) continue;
        prev = sorted[i].first;
        cout << sorted[i].first << std::endl << sorted[i].second;
        count++;
        if(i+1<myMap.size())
            current = sorted[i+1].first;
        else current=-1;
        while (prev==current) {
            i++;
            prev = sorted[i].first;
            if (count%6==0)
                cout << std::endl << sorted[i].second;
            else cout << " " << sorted[i].second;
            count++;
            if(i+1<myMap.size())
                current = sorted[i+1].first;
            else current=-1;
        }
        cout << std::endl;
        count = 0;
    }
    return 0;
}
