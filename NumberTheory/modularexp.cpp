#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
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
int main()
{
	ios::sync_with_stdio(false);
	ll x,n,m,ans;
	cin >> x >> n >> m;
	ans=exp(x,n,m);
	cout << ans << "\n";
	return 0;
}

