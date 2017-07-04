#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	string s1,s2;
	cin >> s1 >> s2;
	ll n=s2.size(),m=s1.size(),i,j;
	ll dp[n+1][m+1];
	for(i=0;i<=n;i++)
		dp[i][0]=0;
	for(i=0;i<=m;i++)
		dp[0][i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(s2[i-1]==s1[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	stack<char>S;
	i=n;
	j=m;
	while(1)
	{
		if(i==0 || j==0)
			break;
		if(s2[i-1]==s1[j-1])
		{
			S.push(s2[i-1]);
			i--;
			j--;
		}
		else 
		{
			if(dp[i][j]==dp[i-1][j])
				i--;
			else
				j--;
		}
	}
	while(!S.empty())
	{
		cout << S.top() ;
		S.pop();
	}
	cout << "\n";
	return 0;
}
