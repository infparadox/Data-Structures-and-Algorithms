#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void maxsubarr(ll a[],ll n,ll k)
{
	deque<ll>q;
	ll i;
	for(i=0;i<k;i++)
	{
		while(!q.empty() && a[i]>=a[q.back()])
			q.pop_back();
		q.push_back(i);
	}
	for(;i<n;i++)
	{
		cout << a[q.front()] << " ";
		while(!q.empty() && q.front()<=(i-k))
			q.pop_front();
		while(!q.empty() && a[i]>=a[q.back()])
			q.pop_back();
		q.push_back(i);
	}
	cout << a[q.front()] << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	ll n;
	cin >> n;
	ll a[n],i,j,k;
	for(i=0;i<n;i++)
		cin >> a[i];
	cin >> k;
	maxsubarr(a,n,k);
	return 0;
}