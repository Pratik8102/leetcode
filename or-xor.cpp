// Be afraid, be very afraid.

// On Halloween, Chef is in a somber mood.
// Chef has an odd integer 
// �
// N that he has to decode.
// To do so, Chef would like to find a pair of integers 
// �
// x and 
// �
// y (
// 0
// ≤
// �
// ,
// �
// <
// 2
// 30
// 0≤x,y<2 
// 30
//  ) such that:

// (
// �
// ∣
// �
// )
// ⋅
// (
// �
// ⊕
// �
// )
// =
// �
// (x∣y)⋅(x⊕y)=N
// Help Chef find any such pair!
// It can be proved that a valid pair always exists.

// Here, 
// ∣
// ∣ represents the bitwise OR operation, and 
// ⊕
// ⊕ represents the bitwise XOR operation.


#include <iostream>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<n<<" "<<n-1<<endl;
    }
	return 0;
}
