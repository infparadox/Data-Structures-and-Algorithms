// C++ Program to find n'th fibonacci Number in
// with O(Log n) arithmatic operations
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll f[100000];

// Returns n'th fuibonacci number using table f[]
ll  fib(ll  n)
{
	// Base cases
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return (f[n] = 1);

	// If fib(n) is already computed
	if (f[n])
		return f[n];

	ll  k = (n & 1)? (n+1)/2 : n/2;

	// Applyting above formula [Note value n&1 is 1
	// if n is odd, else 0.
	f[n] = (n & 1)? (fib(k)*fib(k) + fib(k-1)*fib(k-1))
		: (2*fib(k-1) + fib(k))*fib(k);
	return f[n];
}

int main()
{
	ios::sync_with_stdio(false);
	ll  n ;
	cin >> n;
	ll ans=fib(n);
	cout << ans << "\n";
	return 0;
}
