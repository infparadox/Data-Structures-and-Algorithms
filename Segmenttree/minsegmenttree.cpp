#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll MAX=INT_MAX;

ll size(ll n)
{
	ll ans,y;
	if(n==1)
		ans=3;
	else
	{
		y=log(n)/log(2);
		ans=pow(2,y);
		if(ans==n) //power of 2
			ans=2*n-1;
		else
		{
			y=ceil((double)log(n)/log(2));
			y=pow(2,y);
			ans=2*y-1;
		}
	}
	return ans;
}

void construct(ll a[],ll segtree[],ll l,ll h, ll pos)
{
	if(l==h)
	{
		segtree[pos]=a[l];
		return ;
	}
	ll m;
	m=l+(h-l)/2;
	construct(a,segtree,l,m,2*pos+1);
	construct(a,segtree,m+1,h,2*pos+2);
	segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
}

ll query(ll segtree[],ll qlow,ll qhigh,ll l,ll h,ll pos)
{
	if(qlow<=l && qhigh>=h) //total overlap
		return segtree[pos];
	if(l>qhigh || h<qlow)   //no overlap
		return MAX;
	ll m;
	m=l+(h-l)/2;
	return(min(query(segtree,qlow,qhigh,l,m,2*pos+1),query(segtree,qlow,qhigh,m+1,h,2*pos+2)));
}

int main()
{
	ios::sync_with_stdio(false);
	ll n,x;
	cin >> n ;
	ll a[n],i;
	for(i=0;i<n;i++)
		cin >> a[i];
	x=size(n);
	ll segtree[x];
	for(i=0;i<x;i++)
		segtree[i]=MAX;
	construct(a,segtree,0,n-1,0);
	for(i=0;i<x;i++)
		cout << segtree[i] << " ";
	cout << "\n";
	ll q;
	cin >> q;
	while(q--)
	{
		ll ql,qh,ans;
		cin >> ql >> qh;
		ans=query(segtree,ql,qh,0,n-1,0);
		cout << ans << "\n";
	}
	return 0;
}
