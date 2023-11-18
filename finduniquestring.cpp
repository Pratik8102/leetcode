#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int head = 0;
        set<char> st;
        int ans = 0;
        int tail = 0;

        while (head < n) {
            if (st.find(s[head]) != st.end()) {
                st.erase(s[tail]);
                tail++;
            } else {
                ans = max(ans, head - tail + 1);
                st.insert(s[head]);
                head++;
            }
        }
        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Test string
    string testString = "abcabcbb";

    // Call the function
    int result = solution.lengthOfLongestSubstring(testString);

    // Print the result
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}
