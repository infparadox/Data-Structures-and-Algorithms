#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	ll n,m;
	cin >> n >> m;
	ll cost[n][m],dp[n][m],i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin >> cost[i][j];
			dp[i][j]=0;
		}
	}
	dp[0][0]=cost[0][0];
	for(i=1;i<n;i++)
		dp[i][0]=dp[i-1][0]+cost[i][0];
	for(i=1;i<m;i++)
		dp[0][i]=dp[0][i-1]+cost[0][i];
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
			dp[i][j]=min(dp[i-1][j],dp[i][j-1])+cost[i][j];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
