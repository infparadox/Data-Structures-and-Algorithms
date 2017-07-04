#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll wt[n],val[n],i,j,temp;
	for(i=0;i<n;i++)
		cin >> wt[i];
	for(i=0;i<n;i++)
		cin >> val[i];
	ll k;   //capacity of knapsack
	cin >> k;
	ll dp[n+1][k+1];
	for(i=0;i<=n;i++)
		dp[i][0]=0;
	for(i=0;i<=k;i++)
		dp[0][i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			if(wt[i-1]>j)
				dp[i][j]=dp[i-1][j];
			else
			{
				temp=j-wt[i-1];
				dp[i][j]=max(dp[i-1][temp]+val[i-1],dp[i-1][j]);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
