#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Function to compute the Longest Prefix Suffix (LPS) array for the pattern
    vector<int> computeLPS(string pat) {
        int m = pat.length();
        vector<int> lps(m, 0); // Initialize LPS array with 0s, size equal to pattern length
        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len; // Update LPS value at index i
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // Update len to previous LPS value
                } else {
                    lps[i] = 0; // No prefix suffix found, set LPS at i to 0
                    i++;
                }
            }
        }
        return lps; // Return the computed LPS array
    }

    // Function to search for pattern occurrences in text
    vector<int> search(string pat, string txt) {
        int n = txt.length();
        int m = pat.length();
        vector<int> ans; // Stores the indices where pattern is found
        
        if (m > n) {
            ans.push_back(-1); // If pattern length is greater than text length, pattern not found
            return ans;
        }

        vector<int> lps = computeLPS(pat); // Compute LPS array for the pattern
        int i = 0, j = 0; // Pointers for text (i) and pattern (j)
        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == m) { // If pattern is found
                ans.push_back(i - j); // Store starting index of pattern in text
                j = lps[j - 1]; // Update j to continue searching for next occurrences
            } else if (i < n && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1]; // Update j based on LPS array
                } else {
                    i++;
                }
            }
        }

        if (ans.empty()) {
            ans.push_back(-1); // If pattern is not found, add -1 to the result
        }
        return ans; // Return the vector containing indices where pattern is found
    }
};

int main() {
    Solution sol; // Create an instance of the Solution class

    string text = "AABAACAADAABAABA"; // Text string
    string pattern = "AABA"; // Pattern string to search for in the text

    vector<int> result = sol.search(pattern, text); // Search for pattern in the text

    cout << "Pattern found at indices: ";
    if (result[0] == -1) {
        cout << "Pattern not found in the text.";
    } else {
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << " "; // Print indices where pattern is found
        }
    }
    cout << endl;

    return 0;
}
