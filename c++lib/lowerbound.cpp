#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ios::sync_with_stdio(0);
	ll n,i;
	cin >> n;
	vector<ll>a;
	for(i=0;i<n;i++)
	{
		ll x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	ll q;
	cin >> q;
	while(q--)
	{
		ll x; // element to be searched
		cin >> x;
		if(binary_search(a.begin(),a.end(),x))
			cout << "Found\n";
		auto it=lower_bound(a.begin(),a.end(),x);
		cout << it-a.begin() << "\n";
		it=upper_bound(a.begin(),a.end(),x);
		cout << it-a.begin() << "\n";
	}
	return 0;
}