#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
bool prime[100000];

void sieve(ll n)
{
	ll i,j;
	for(i=2;i<=sqrt(n);i++)
	{
		if(prime[i])
		{
			for(j=2;i*j<=n;j++)
			{
				if(prime[i*j])
					prime[i*j]=false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	ll n,i,j;
	cin >> n;
	for(i=0;i<=n;i++)
		prime[i]=true;
	prime[0]=false;
	prime[1]=false;
	sieve(n);
	for(i=2;i<=n;i++)
	{
		if(prime[i])
			cout << i << " " ;
	}
	cout << "\n";
	return 0;
}
