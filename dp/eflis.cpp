#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll lis(vector<ll>&a)
{
	ll i;
	vector<ll>res;
	vector<ll>::iterator it;
	for(i=0;i<a.size();i++)
	{
		it=lower_bound(res.begin(),res.end(),a[i]);
		if(it==res.end())
			res.push_back(a[i]);
		else
			*it=a[i];
	}
	return res.size();
}

int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll>a(n);
	ll i;
	for(i=0;i<n;i++)
		cin >> a[i];
	ll ans=lis(a);
	cout << ans << "\n";
	return 0;
}
