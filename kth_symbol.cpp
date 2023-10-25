#include<bits/stdc++.h>
using namespace std;

int kthGrammar(int n, int k) {
    if (n == 1) {
        return 0;
    }
    
    int totalNodes = pow(2, n - 1);
    int mid = totalNodes / 2;
    
    if (k <= mid) {
        return kthGrammar(n - 1, k);
    } else {
        int prevResult = kthGrammar(n - 1, k - mid);
        return prevResult == 0 ? 1 : 0;
    }
}



int main() {
  

    int n, k;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter k: ";
    std::cin >> k;

    int result = kthGrammar(n, k);
    std::cout << "The k-th grammar symbol is: " << result << std::endl;

    return 0;
}
