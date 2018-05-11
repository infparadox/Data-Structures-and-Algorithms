#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define si 1000001
ll qrt_si;
ll blocks[si],arr[si];

void build(ll n)
{
	for(ll i=0;i<n;i++)
		blocks[i/qrt_si]+=arr[i];
}

void update(ll index,ll val)
{
	ll old=arr[index];
	blocks[index/qrt_si]+=(val-old);
	arr[index]=val;
}

ll query(ll l,ll r)
{
	ll ans=0;
	ll l_block=l/qrt_si; 
	ll r_block=(r/qrt_si),i;
	for(i=(l_block+1);i<r_block;i++)
		ans+=blocks[i];
	for(i=l;i<=min(r,((l_block+1)*qrt_si)-1);i++)
		ans+=arr[i];
	if(l_block!=r_block)
	{
		for(i=(r_block)*qrt_si;i<=r;i++)
			ans+=arr[i];
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll i,j;
	for(i=0;i<n;i++)
		cin >> arr[i];
	qrt_si=ceil((double)sqrt(n));
	cout << qrt_si << "\n";
	build(n);
	ll q;
	cin >> q;
	while(q--)
	{
		ll x;
		cin >> x;
		if(x==1) // 1 i k update a[i]=x
		{
			ll index,val;
			cin >> index >> val;
			update(index,val);
		}
		else  // query : sum - (l,r)
		{
			ll l,r;
			cin >> l >> r;
			ll ans=query(l,r);
			cout << ans  << "\n";
		}
	}
	return 0;
}