#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	ll n,m,q;
	cin >> n >> m >> q;
	ll dp[n][m],i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			dp[i][j]=0;
	}
	for(i=0;i<q;i++)
	{
		ll x,y;
		cin >> x >> y;
		dp[x][y]=-1;
	}
	for(i=0;i<n;i++)
	{
		if(dp[i][0]!=-1)
			dp[i][0]=1;
		else
			break;
	}
	for(i=1;i<m;i++)
	{
		if(dp[0][i]!=-1)
			dp[0][i]=1;
		else
			break;
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			if(dp[i][j]==-1)
				continue;
			if(dp[i][j-1]>0)
				dp[i][j]+=(dp[i][j-1]);
			if(dp[i-1][j]>0)
				dp[i][j]+=(dp[i-1][j]);
		}
	}
	if(dp[0][0]==-1)
	{
		cout << "0\n";
		return 0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
