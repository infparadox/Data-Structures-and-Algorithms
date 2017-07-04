#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll cost[n+1],i,j,ans=0,dp[n+1];
	for(i=1;i<=n;i++)
	{
		cin >> cost[i];
		dp[i]=0;
	}
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
			ans=max(ans,cost[j]+dp[i-j]);
		dp[i]=ans;
		ans=0;
	}
	for(i=1;i<=n;i++)
		cout << dp[i] << " ";
	cout << "\n";
	cout << dp[n] << "\n";
	return 0;
}
