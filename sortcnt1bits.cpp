#include<bits/stdc++.h>
using namespace std;
    static bool lambda(int &a, int &b) {
        int cnta = __builtin_popcount(a);
        int cntb = __builtin_popcount(b);
        if (cnta == cntb) {
            return a < b;
        } else {
            return cnta < cntb;
        }
    }

   


int main() {
   
    vector<int> arr = {3, 8, 5, 7, 10, 3};

    sort(arr.begin(), arr.end(), lambda);

    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}