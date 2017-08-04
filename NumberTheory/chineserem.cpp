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

ll invmod(ll temp,ll m)
{
	extgcd(temp,m);
	return (x%m+m)%m;
}

int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll num[n],rem[n],i,j,pro=1;
	for(i=0;i<n;i++)
	{
		cin >> num[i];
		pro=pro*num[i];
	}
	for(i=0;i<n;i++)
		cin >> rem[i];
	ll pp[n];
	for(i=0;i<n;i++)
		pp[i]=(pro)/num[i];
	ll inv[n];
	for(i=0;i<n;i++)
		inv[i]=invmod(pp[i],num[i]);
	ll fin=0;
	for(i=0;i<n;i++)
	{
		fin+=(((rem[i]%pro*inv[i]%pro)%pro)*pp[i]%pro)%pro;
		fin=fin%pro;
	}
	cout << fin << "\n";
	return 0;
}
