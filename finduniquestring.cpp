#include <iostream>
#include <vector>
#include <stack>
#include <set>

class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        std::set<std::string> st(nums.begin(), nums.end());
        int n = nums[0].size();
        std::string ans = "";
        std::stack<std::string> stack;
        stack.push("");

        while (!stack.empty()) {
            std::string current = stack.top();
            stack.pop();

            if (current.size() == n) {
                if (st.find(current) == st.end()) {
                    ans = current;
                    break;
                }
            } else {
                stack.push(current + '0');
                stack.push(current + '1');
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> nums = {"01", "10", "11"};
    std::string result = solution.findDifferentBinaryString(nums);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
