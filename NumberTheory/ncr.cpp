#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
ll ncr(ll n , ll r)
{
	if(r>n)
		return 0;
	if(r==0 || r==n)
		return 1;
	else if(r==1 || r==n-1)
		return n;
	else
		return(ncr(n-1,r-1)+ncr(n-1,r));
}

int main()
{
	ios::sync_with_stdio(false);
	ll n,r,ans;
	cin >> n >> r;
	ans=ncr(n,r);
	cout << ans << "\n";
	return 0;
}
