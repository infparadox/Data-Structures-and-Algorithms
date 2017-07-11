#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll>segtree[100000];
ll a[100000];

void construct(ll l,ll h, ll pos)
{
	if(l==h)
	{
		segtree[pos].push_back(a[l]);
		return ;
	}
	ll m;
	m=l+(h-l)/2;
	construct(l,m,2*pos+1);
	construct(m+1,h,2*pos+2);
	merge(segtree[2*pos+1].begin(), segtree[2*pos+1].end(), segtree[2*pos+2].begin(), segtree[2*pos+2].end(), back_inserter(segtree[pos]));
}

ll query(ll qlow,ll qhigh,ll l,ll h,ll pos,ll k)
{
	if(qlow<=l && qhigh>=h) //total overlap
		return(lower_bound(segtree[pos].begin(),segtree[pos].end(),k)-segtree[pos].begin());
	if(l>qhigh || h<qlow)   //no overlap
		return 0;
	ll m;
	m=l+(h-l)/2;
	return(query(qlow,qhigh,l,m,2*pos+1,k)+query(qlow,qhigh,m+1,h,2*pos+2,k));
}

int main()
{
	ios::sync_with_stdio(false);
	ll n,x;
	cin >> n ;
	ll i;
	for(i=0;i<n;i++)
		cin >> a[i];
	construct(0,n-1,0);
	ll q;
	cin >> q;
	while(q--)
	{
		ll ql,qh,ans,k;
		cin >> ql >> qh >> k;
		ans=query(ql,qh,0,n-1,0,k);
		cout << ans << "\n";
	}
	return 0;
}
