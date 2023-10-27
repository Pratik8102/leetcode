#include <iostream>
#include <vector>

using namespace std;


    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        int start = 0;  // Start index of the longest palindrome substring
        int maxLen = 1; // Length of the longest palindrome substring

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check for palindromes of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Check for palindromes of length greater than 2
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }


int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;


    string result = longestPalindrome(input);

    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
