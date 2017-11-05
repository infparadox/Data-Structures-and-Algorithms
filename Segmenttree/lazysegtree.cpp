#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll MAX=INT_MAX;

ll getsize(ll n)
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

void update(ll segtree[],ll lazy[],ll delta,ll ql,ll qh,ll l,ll h,ll pos)
{
	if(l>h)
		return;
	if(lazy[pos]!=0)
	{
		segtree[pos]+=lazy[pos];
		if(l!=h)  // If not a leaf node update its children
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	// no overalap
	if(l>qh || h<ql)
		return;
	// total overlap
	if(l>=ql && h<=qh)
	{
		segtree[pos]+=delta;
		if(l!=h)
		{
			lazy[2*pos+1]+=delta;
			lazy[2*pos+2]+=delta;
		}
		return;
	}
	ll m=l+(h-l)/2;
	update(segtree,lazy,delta,ql,qh,l,m,2*pos+1);
	update(segtree,lazy,delta,ql,qh,m+1,h,2*pos+2);
	segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
}

ll query(ll segtree[],ll lazy[],ll ql,ll qh,ll l,ll h,ll pos)
{
	if(l>h)
		return MAX;
	if(lazy[pos]!=0)
	{
		segtree[pos]+=lazy[pos];
		if(l!=h) // not leaf node
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	// no overalap
	if(l>qh || h<ql)
		return MAX;
	// total overlap
	if(l>=ql && h<=qh)
		return segtree[pos];
	ll m=l+(h-l)/2;
	return(min(query(segtree,lazy,ql,qh,l,m,2*pos+1),query(segtree,lazy,ql,qh,m+1,h,2*pos+2)));
}

void print(ll a[],ll n)
{
	for(ll i=0;i<n;i++)
		cout << a[i] << " ";
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	ll n,x;
	cin >> n ;
	ll a[n],i;
	for(i=0;i<n;i++)
		cin >> a[i];
	x=getsize(n);
	ll segtree[x],lazy[x];
	for(i=0;i<x;i++)
	{
		segtree[i]=MAX;
		lazy[i]=0;
	}
	construct(a,segtree,0,n-1,0);
	for(i=0;i<x;i++)
		cout << segtree[i] << " ";
	cout << "\n";
	ll q;
	cin >> q;
	while(q--)
	{
		ll y;
		cin >> y;
		if(y==1) // update
		{
			ll ql,qh,delta;
			cin >> ql >> qh >> delta;
			update(segtree,lazy,delta,ql,qh,0,n-1,0);
		}
		else if(y==2) // range query
		{
			ll ql,qh,ans;
			cin >> ql >> qh;
			ans=query(segtree,lazy,ql,qh,0,n-1,0);
			cout << ans << "\n";
		}
		else if(y==3) // print segtree
			print(segtree,x);
		else if(y==4) // print lazy tree
			print(lazy,x);
	}
	return 0;
}
