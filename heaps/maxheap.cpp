#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void max_heapify(ll a[],ll i,ll n)
{
	ll left,right,largest=i;
	left=2*i;
	right=2*i+1;
	if(left<=n && a[left]>a[i])
		largest=left;
	if(right<=n && a[right]>a[largest])
		largest=right;
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		max_heapify(a,largest,n);
	}
}

void build_heap(ll a[],ll n)
{
	ll i;
	for(i=n/2;i>=1;i--)
		max_heapify(a,i,n);
}

void heapsort(ll a[],ll n)
{
	ll i,size=n;
	build_heap(a,n);
	for(i=n;i>=2;i--)
	{
		swap(a[i],a[1]);
		size--;
		max_heapify(a,1,size);
	}
	for(i=1;i<=n;i++)
		cout << a[i] << " ";
	cout << "\n";
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
//	heapsort(a,n);
	return 0;
}
