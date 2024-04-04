#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> replaceWithRanks(vector<int>& arr) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    unordered_map<int, int> rankMap;

    
    int rank = 1;
    for (int num : sortedArr) {
        if (rankMap.find(num) == rankMap.end()) {
            rankMap[num] = rank++;
        }
    }

    
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = rankMap[arr[i]];
    }

    return arr;
}

int main() {
    vector<int> arr = {10, 8, 15, 12, 6, 20, 1};
    vector<int> result = replaceWithRanks(arr);


    cout << "\nOutput: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}