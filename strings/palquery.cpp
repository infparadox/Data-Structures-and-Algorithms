#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod(ll x,ll n,ll m)
{
	if(n==0)
		return 1;
	else if(n==1)
		return x%m;
	else if(n%2==0)
		return(mod((x%m*x%m)%m,n/2,m));
	else
		return((x%m*mod((x%m*x%m)%m,(n-1)/2,m)%m)%m);
}
int main()
{
	string x,y;
	cin >> x;
	ll n=x.size();
	ll p=101,mo=1e9+7,h1=0,h2=0,i,j,pre[n],suf[n];
	for(i=0;i<n;i++)
	{
		h1+=((x[i]%mo)*(mod(p,i,mo)));
		h1=h1%mo;
		pre[i]=h1;
	}
	for(i=n-1;i>=0;i--)
	{
		h2+=((x[i]%mo)*(mod(p,n-i-1,mo)));
		h2=h2%mo;
		suf[i]=h2;
	}
	ll q;
	cin >> q;
	while(q--)
	{
		ll l,r;
		cin >> l >> r;
		ll x,y;
		if(l==r)
			x=y;
		else if(l==0 || r==n-1)
		{
			if(l==0 && r!=(n-1))
			{
				ll t;
				t=(n-r-1)*(mo-2);
				x=pre[r];
				y=(((suf[l]-suf[r+1]+mo)%mo)*mod(p,t,mo))%mo;
			}
			else if(l==0 && r==n-1)
			{
				x=pre[r];
				y=suf[l];
			}
			else if(l!=0 && r==n-1)
			{
				ll s;
				s=l*(mo-2);
				x=(((pre[r]-pre[l-1]+mo)%mo)*mod(p,s,mo))%mo;
				y=suf[l];
			}
		}
		else
		{
			ll s,t,u;
			s=l*(mo-2);
			t=(n-r-1)*(mo-2);
			x=(((pre[r]-pre[l-1]+mo)%mo)*mod(p,s,mo))%mo;
			y=(((suf[l]-suf[r+1]+mo)%mo)*mod(p,t,mo))%mo;
		}
		if(x==y)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
