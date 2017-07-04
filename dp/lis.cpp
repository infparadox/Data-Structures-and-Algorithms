#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll dp[n],a[n],i,j,par[n];
	for(i=0;i<n;i++)
	{
		cin >> a[i];
		dp[i]=1;
		par[i]=i;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[i] && (dp[i]+1)>dp[j])
			{
				dp[j]=dp[i]+1;
				par[j]=i;
			}
		}
	}
/*	for(i=0;i<n;i++)
		cout << par[i] << " ";
	cout << "\n";
	*/
	ll ans=1,index=0;
	for(i=0;i<n;i++)
	{
//		cout << dp[i] << " ";
		if(dp[i]>ans)
		{
			ans=dp[i];
			index=i;
		}
	}
//	cout << "\n";
	// ANSWER
	cout << ans << "\n";
	stack<ll>S;
	ll cur;
	while(1)
	{
		S.push(a[index]);
		if(index==0)
			break;
		cur=par[index];
		if(index==cur)
			break;
		index=par[index];
	}
	//ELEMENTS
	while(!S.empty())
	{
		cout << S.top() << " ";
		S.pop();
	}
	cout << "\n";
	return 0;
}

