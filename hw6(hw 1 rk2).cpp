#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;





int main() {
    int n;
    cin >> n;
    vector<string> Array(n);

    for (int i = 0; i < n; i++) {
        cin >> Array[i];
    }

    map<string, vector<string>> anagramGroups;
    // string - ключ отсортированных строк 
    // vector<string> - значение векторы строк, представляющие анаграммы.

    for (int i = 0; i < n; i++) {
        string sortedStr = Array[i];
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(Array[i]);
    }

    //  Позволяет хранить все анаграммы, сгруппированные по ключам, представляющим отсортированные версии строк
    // sortedStr - это ключ, который используется для доступа к соответствующей группе анаграмм в anagramGroups.
    
    for (const auto& entry : anagramGroups) {
        for (const string& anagram : entry.second) {
            cout << anagram << " ";
        }
        cout << endl;
    }
    // 1-й цикл перебирает все элементы пары ключ-значение в anagramGroups
    // 2-й цикл перебирает все строки в векторе строк, который является значением entry.second текущего ключа entry группы анаграмм

    return 0;
}




