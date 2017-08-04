// Complexity -O(R)
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;

ll ncr(ll n,ll r)
{
	ll res=1;
	if(r>(n-r))
		r=n-r;
	for(ll i=0;i<r;i++)
	{
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	ll n,r;
	cin >> n >> r;
	ll ans=ncr(n,r);
	cout << ans << "\n";
	return 0;
}

