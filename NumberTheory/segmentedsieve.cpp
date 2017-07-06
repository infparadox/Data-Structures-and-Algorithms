#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll diff=0;
vector<ll>prime;
void sieve(ll n)
{
	ll i,j;
	bool a[n+1];
	for(i=0;i<=n;i++)
		a[i]=true;
	a[0]=false;
	a[1]=false;
	for(i=2;i<=sqrt(n);i++)
	{
		if(a[i]==true)
		{
			for(j=2;i*j<=n;j++)
				a[i*j]=false;
		}
	}
	for(i=2;i<=n;i++)
	{
		if(a[i]==true)
			prime.push_back(i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	while(t--)
	{
		prime.clear();
		ll i,j,k,l,r;
		cin >> l >> r;
		diff=r-l+1;
		sieve(sqrt(r));
		ll n;
		n=prime.size();
		bool ans[diff];
		for(i=0;i<diff;i++)
			ans[i]=true;
		for(i=0;i<n;i++)
		{
			ll y;
			y=l/prime[i];
			y=y*prime[i];
			for(j=y;j<=r;j+=prime[i])
			{
				if(j<l)
					continue;
				ans[j-l]=false;
			}
		}
		for(i=0;i<n;i++)
		{
			if(prime[i]>=l && prime[i]<=r)
				cout << prime[i] << "\n";
		}
		for(i=0;i<diff;i++)
		{
			if(ans[i]==true && (i+l)!=1)
				cout << i+l << "\n";
		}
	cout << "\n";
	}
	return 0;
}
