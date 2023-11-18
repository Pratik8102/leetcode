#include <iostream>
#include <vector>

class Solution {
public:
    int longestNiceSubarray(std::vector<int>& nums) {
        int num = 0;
        int j = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            while ((num & nums[i]) != 0) {
                num = num ^ nums[j++];
            }
            num = num | nums[i];
            ans = std::max(ans, i - j + 1);
        }
        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<int> nums = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9};
    int result = solution.longestNiceSubarray(nums);

    // Display the result
    std::cout << "Length of the longest nice subarray: " << result << std::endl;

    return 0;
}
