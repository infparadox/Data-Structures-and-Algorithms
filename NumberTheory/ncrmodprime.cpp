#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
ll dp[1000];

ll exp(ll x,ll n,ll m)
{
	if(n==0)
		return 1;
	else if(n==1)
		return(x%m);
	else if(n%2==0)
		return(exp((x%m*x%m)%m,n/2,m)%m);
	else
		return((x%m*exp((x%m*x%m)%m,(n-1)/2,m)%m)%m);
}

ll fact(ll n,ll m)
{
	if(dp[n]!=0)
		return dp[n];
	else
		dp[n]=(n*fact(n-1,m));
	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	ll n,r,m,i,j,ans;
	cin >> n >> r >> m;
	dp[0]=1;
	dp[1]=1;
	ll f_1,f_2,f_3;
	f_1=fact(n,m)%m;
	f_2=fact(n-r,m)%m;
	f_3=fact(r,m)%m;
	ans=(((f_1)%m*(exp(f_2,m-2,m)%m))%m*(exp(f_3,m-2,m)%m))%m;
	cout << ans << "\n";
	return 0;
}

