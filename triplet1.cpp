#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int minimumSum(std::vector<int>& nums) 
    {
        int n = nums.size();
        std::vector<int> left(n);
        left[0] = nums[0];
        std::vector<int> right(n);
        right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            left[i] = std::min(nums[i], left[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = std::min(nums[i], right[i + 1]);
        }
        int ans = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > left[i - 1] && nums[i] > right[i + 1]) {
                ans = std::min(ans, nums[i] + left[i - 1] + right[i + 1]);
            }
        }
        if (ans == INT_MAX) {
            return -1;
        } else {
            return ans;
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6}; 
    int result = solution.minimumSum(nums);
    std::cout << "Minimum sum: " << result << std::endl;
    return 0;
}
