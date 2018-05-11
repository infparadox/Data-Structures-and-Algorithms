#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll m=1e9+7;
ll dp[2][10000001];
/*
ll func(ll same,ll steps) //des=3 (fixed)
{
	if(steps==0)
	{
		if(same==1)
			return 1;
		return 0;
	}
	ll x=dp[same][steps];
	if(x!=-1)
		return x;
	if(same==1)
		x=(3*(func(0,steps-1))%m)%m;
	else
		x=((2*func(0,steps-1)%m)%m+func(1,steps-1)%m)%m;
	dp[same][steps]=x;
	return x;
}*/

int main()
{
	ios::sync_with_stdio(false);
	ll n,i,j;
	cin >> n;
	dp[0][0]=0;
	dp[1][0]=1;
	for(i=1;i<=n;i++)
	{
		ll x=(3LL*dp[0][i-1]%m)%m;
		dp[0][i]=((2LL*dp[0][i-1]%m)%m+dp[1][i-1]%m)%m;
		dp[1][i]=x;
	}
	ll ans=dp[1][n];
	cout << ans << "\n";
	return 0;
}