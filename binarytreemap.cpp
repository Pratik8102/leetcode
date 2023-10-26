#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
    int numFactoredBinaryTrees(std::vector<int>& arr) {
        unordered_map<int, long long> mp;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            mp[arr[i]] = 1;
        }

        for (int i = 0; i < n; i++) {
            int root = arr[i];
            for (int j = 0; j < i; j++) {
                if (root % arr[j] == 0 && mp.find(root / arr[j]) != mp.end()) {
                    mp[root] += (mp[arr[j]] * mp[root / arr[j]]) % 1000000007;
                }
            }
        }

        long long ans = 0;
        for (auto& it : mp) {
            ans = (ans + it.second) % 1000000007;
        }

        return ans;
    }


int main() {
 
    vector<int> arr = {2, 4, 5, 10};
    int result = numFactoredBinaryTrees(arr);

    cout << "Result: " << result << endl;

    return 0;
}
