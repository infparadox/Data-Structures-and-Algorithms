#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll bs(ll a[],ll n,ll x)
{
	ll l=0,h=n-1;
	while(l<=h)
	{
		ll m=l+(h-l)/2;
		if(a[m]==x)
			return m;
		else if(a[m]<x)
			l=m+1;
		else
			h=m-1;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	ll n;
	cin >> n;
	ll a[n],i,j;
	for(i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	ll q;
	cin >> q;
	while(q--)
	{
		ll x;
		cin >> x;
		ll index=bs(a,n,x);
		if(index!=-1)
			cout << "Yes\n" << index << "\n";
		else
			cout << "No\n";
	}
	return 0;
}