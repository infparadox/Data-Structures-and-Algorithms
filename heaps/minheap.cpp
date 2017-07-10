#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void min_heapify(ll a[],ll i,ll n)
{
	ll left,right,smallest=i;
	left=2*i;
	right=2*i+1;
	if(left<=n && a[left]<a[i])
		smallest=left;
	if(right<=n && a[right]<a[smallest])
		smallest=right;
	if(smallest!=i)
	{
		swap(a[i],a[smallest]);
		min_heapify(a,smallest,n);
	}
}

void build_heap(ll a[],ll n)
{
	ll i;
	for(i=n/2;i>=1;i--)
		min_heapify(a,i,n);
}

int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll a[n+1],i;
	for(i=1;i<=n;i++)
		cin >> a[i];
	build_heap(a,n);
	for(i=1;i<=n;i++)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}
