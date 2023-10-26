// Magic is really very simple, all you’ve got to do is want something and then let yourself have it.

// Chadda and his Wizard friend PSC were exploring the enchanted forest on Halloween, when Chadda stumbled upon an array 

// A of 

// N magical numbers which took him into a different world.

// Chadda remembered that PSC gave him two integers 

// P and 

// Q for such a situation.
// Using these integers, Chadda can modify the array 

// A as follows:

// At most 

// P times, perform the following operation:
// Pick two elements 

// x and 

// y from 

// A, delete them both from 

// A, and insert 
// (

// +

// )
// (x+y) into 

// A.
// This operation can be performed only if 

// A has at least two elements.
// At most 

// Q times, perform the following operation:
// Pick two elements 

// x and 

// y from 

// A, delete them both from 

// A, and insert 
// (

// −

// )
// (x−y) into 

// A.
// This operation can also be performed only if 

// A has at least two elements.
// Note that each operation reduces the size of 

// A by one.
// The two types of operations (addition and subtraction) can be performed in any order, as long as at most 

// P addition operations and 

// Q subtraction operations are made.

// Let 

// B denote the final array obtained after performing some (possibly, zero) operations.
// To return to his original world, Chadda has to find the maximum possible value of

// max
// ⁡
// (

// )
// −
// min
// ⁡
// (

// )
// max(B)−min(B)
// across all possible final arrays 

// B.
// Can you help Chadda find this value?



#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve() {
	ll n, p, q;
	cin >> n >> p >> q;

	ll arr[n];
	for(ll i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);
	ll ans = arr[n - 1] - arr[0];

	vector<ll> v;
	for(ll i = 1; i < n - 1; i++) v.push_back(abs(arr[i]));

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for(ll i = 0; i < min(p + q, (ll)v.size()); i++) ans += v[i];

	cout << ans << '\n';

}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}