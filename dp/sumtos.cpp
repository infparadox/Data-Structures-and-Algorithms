#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll i,j,v[n],s;
	for(i=0;i<n;i++)
		cin >> v[i];
	cin >> s;
	ll dp[s+1],par[s+1];
	for(i=0;i<=s;i++)
		dp[i]=INT_MAX;
	dp[0]=0;
	par[0]=0;
	for(i=1;i<=s;i++)
	{
		for(j=0;j<n;j++)
		{
			if(v[j]<=i && dp[i-v[j]]+1<dp[i])
			{
				dp[i]=dp[i-v[j]]+1;
				par[i]=i-v[j];
			}
		}
	 }
	for(i=0;i<=s;i++)
		cout << "dp[" << i << "]: " << dp[i] << "\n"; 
	ll cur,val;
	cur=s;
	val=par[s];
	while(1)
	{
		cout << cur-val << " ";
		if(val==0)
			break;
		cur=val;
		val=par[cur];
	}
	return 0;
}
