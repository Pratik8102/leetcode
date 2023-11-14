#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

class Solution {
public:
    int countElements(std::vector<int>& nums) 
    {
        std::set<int> st;
        std::map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
            st.insert(num);
        }

        if (st.size() == 1) {
            return 0;
        } 

        int mini = *std::min_element(nums.begin(), nums.end());
        int maxi = *std::max_element(nums.begin(), nums.end());

        return nums.size() - mp[mini] - mp[maxi];
    }
};

int main() {
    Solution solution;

    // Example usage:
    std::vector<int> nums = {1, 2, 2, 3, 4, 4, 5};
    int result = solution.countElements(nums);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
