#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[10000][10000],n,m;

ll editdis(string s1,string s2)
{
	ll i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(s1[j-1]==s2[i-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
		}
	}
	return(dp[n][m]);
}

int main()
{
	ios::sync_with_stdio(false);
	string s1,s2;
	cin >> s1 >> s2;
	ll i,j;
	n=s2.size();
	m=s1.size();
	for(i=0;i<=n;i++)
		dp[i][0]=i;
	for(i=0;i<=m;i++)
		dp[0][i]=i;
	ll ans=editdis(s1,s2);
	cout << ans << "\n";
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
