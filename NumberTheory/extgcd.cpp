#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
ll ans,x,y;
void extgcd(ll a, ll b)
{
	if(b==0)
	{
		ans=a;
		x=1;
		y=0;
	}
	else
	{
		extgcd(b,a%b);
		ll temp=x;
		x=y;
		y=temp- (a/b)*y;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	ll a,b;
	cin >> a >> b;
	extgcd(a,b);
	cout << ans << " " << x << " " <<  y << "\n";
	return 0;
}
