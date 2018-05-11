#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ios::sync_with_stdio(false);
	ll n,i;
	cin >> n;
	multiset<ll>cnt;
	for(i=0;i<n;i++)
	{
		ll x;
		cin >> x;
		cnt.insert(x);
	}
	for(auto it=cnt.begin();it!=cnt.end();it++)
		cout << (*it) << "\n";
	return 0;
}

