#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ios::sync_with_stdio(0);
	multimap<ll,ll>m;
	ll i=0,j=0;
	ll n;
	cin >> n;
	for(i=0;i<n;i++)
	{
		ll x;
		cin >> x;
		m.insert(make_pair(x,i));
	}
	for(auto it=m.begin();it!=m.end();it++)
		cout << (*it).first << " " << (*it).second << "\n";
	ll q;
	cin >> q;
	while(q--)
	{
		ll x;
		cin >> x;
		if(x==1) //search
		{
			ll y;
			cin >> y;
			if(m.find(y)!=m.end())
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		else if(x==2) // delete
		{
			ll y;
			cin >> y;
			auto it=m.find(y);
			if(it!=m.end())
				m.erase(it);
		}
		else // lowerbound
		{
			ll y;
			cin >> y;
			auto it=m.lower_bound(y);
			cout << (*it).first << " " << (*it).second << "\n";
		}
	}
	return 0;
}