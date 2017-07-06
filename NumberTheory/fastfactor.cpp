#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
int main()
{
	ios::sync_with_stdio(false);
	ll n,i,j;
	cin >> n;
	ll prime[n+1];
	for(i=0;i<=n;i++)
		prime[i]=1;
	prime[0]=0;
	prime[1]=0;
	for(i=2;i<=sqrt(n);i++)
	{
		if(prime[i]==1)
		{
			for(j=2;i*j<=n;j++)
			{
				if(prime[i*j]==1)
					prime[i*j]=i;
			}
		}
	}
	for(i=2;i<=n;i++)
	{
		if(prime[i]==1)
			prime[i]=i;
	}
	vector<ll>res;
	while(n!=1)
	{
		ll x=prime[n];
		res.push_back(x);
		n=n/x;
	}
	for(i=0;i<res.size();i++)
		cout << res[i] << " " ;
	cout << "\n";
	return 0;
}
