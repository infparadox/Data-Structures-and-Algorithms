#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll grundy[1000002];

ll mex(unordered_set<ll>set)
{
	ll ans=0;
	while(set.find(ans)!=set.end())
		ans++;
	return ans;
}

ll calcgrundy(ll n,ll grundy[])
{
	if(grundy[n]!=-1)
		return grundy[n];
	unordered_set<ll>set;
	for(ll i=1;i<=n;i++)
		set.insert(calcgrundy(n-i,grundy));
	grundy[n]=mex(set);
	return grundy[n];
}

int main()
{
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	ll grundy[101];
	while(t--)
	{
		ll n,m;
		cin >> n >> m;
		ll i,a[n];
		for(i=0;i<n;i++)
			a[i]=m;
		ll ans=0;
		for(ll i=0;i<=1000000;i++)
			grundy[i]=-1;
		grundy[0]=0;
		for(i=0;i<n;i++)
			ans=ans^calcgrundy(a[i],grundy);
		if(ans!=0)
			cout << "Second\n";
		else
			cout << "First\n";
	}
	return 0;
}