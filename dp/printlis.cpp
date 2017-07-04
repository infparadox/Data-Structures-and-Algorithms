#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// Binary search
ll GetCeilIndex(ll arr[], vector<ll> &T, ll l, ll r,ll key)
{
	while (r - l > 1)
	{
		ll m = l + (r - l)/2;
		if (arr[T[m]] >= key)
			r = m;
		else
			l = m;
	}

	return r;
}

ll lis(ll arr[], ll n)
{
	// Add boundary case, when array n is zero
	// Depend on smart pollers

	vector<ll> tailIndices(n, 0); // Initialized with 0 
	vector<ll> prevIndices(n, -1); // initialized with -1

	ll len = 1; // it will always poll to empty location
	for (ll i = 1; i < n; i++)
	{
		if (arr[i] < arr[tailIndices[0]])
		{
			// new smallest value
			tailIndices[0] = i;
		}
		else if (arr[i] > arr[tailIndices[len-1]])
		{
			// arr[i] wants to extend largest subsequence
			prevIndices[i] = tailIndices[len-1];
			tailIndices[len++] = i;
		}
		else
		{
			// arr[i] wants to be a potential condidate of
			// future subsequence
			// It will replace ceil value in tailIndices
			ll pos = GetCeilIndex(arr, tailIndices, -1,
					len-1, arr[i]);

			prevIndices[i] = tailIndices[pos-1];
			tailIndices[pos] = i;
		}
	}

	cout << "LIS of given input\n" ;
	stack<ll>S;
	for (ll i = tailIndices[len-1]; i >= 0; i = prevIndices[i])
		S.push(arr[i]);
	while(!S.empty())
	{
		cout << S.top() << " " ;
		S.pop();
	}
	cout << "\n";

	return len;
}

int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll arr[n],i;
	for(i=0;i<n;i++)
		cin >> arr[i];
	ll ans=lis(arr,n);
	cout << "LIS size " << ans  << "\n";
	return 0;
}
