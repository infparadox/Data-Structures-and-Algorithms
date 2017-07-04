#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll a[n],i,j;
	for(i=0;i<n;i++)
		cin >> a[i];
	ll ans=a[0],sum=a[0];
	for(i=1;i<n;i++)
	{
		sum=max(a[i],sum+a[i]);
		ans=max(ans,sum);
	}
	cout << ans << "\n";
	return 0;
}
