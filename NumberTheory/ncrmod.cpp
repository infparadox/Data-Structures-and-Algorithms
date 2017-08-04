#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;

ll ncr(ll n,ll r,ll m)
{
	ll i,j,res[r+1];
	for(i=0;i<=r;i++)
		res[i]=0;
	res[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=min(i,r);j>0;j--)
			res[j]=(res[j]%m+res[j-1]%m)%m;
	}
	return res[r];
}

int main()
{
	ios::sync_with_stdio(false);
	ll n,r,p,i,m;
	cin >> n >> r >> m;
	ll ans=ncr(n,r,m);
	cout << ans << "\n";
	return 0;
}
