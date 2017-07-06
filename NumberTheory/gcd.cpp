#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	else
		return(gcd(b,a%b));
}
int main()
{
	ios::sync_with_stdio(false);
	ll a,b,ans;
	cin >> a >> b;
	ans=gcd(a,b);
	cout << ans << "\n";
	return 0;
}
