#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mex(unordered_set<ll>set)
{
	ll ans=0;
	while(set.find(ans)!=set.end())
		ans++;
	return ans;
}

ll calcgrundy(ll n,ll grundy[])
{
	if(n==0)
		return 0;
	if(grundy[n]!=-1)
		return grundy[n];
	unordered_set<ll>set;
	for(ll i=0;i<n;i++)
		set.insert(calcgrundy(i,grundy));
	grundy[n]=mex(set);
	return grundy[n];
}

int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll grundy[n+1],i;
	for(i=0;i<=n;i++)
		grundy[i]=-1;
	grundy[0]=0;
	calcgrundy(n,grundy);
	for(i=0;i<=n;i++)
		cout << grundy[i] << " ";
	cout << "\n";
	return 0;
}