    
    
#include<bits/stdc++.h>
using namespace std;
int maxSumIncreasingSubsequence(int arr[], int n) {
  vector<int> dp(n);

    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    int maxSum = dp[0];
    for (int i = 1; i < n; i++) {
        maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
}


int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result =maxSumIncreasingSubsequence(arr, n);
    cout << "The maximum sum of increasing subsequence is: " << result << std::endl;

    return 0;
}
