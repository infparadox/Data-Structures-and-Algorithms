// O(sqrt(n))

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;

vector<ll> factor(ll n)
{
	ll i,j;
	vector<ll>res;
	for(i=2;i*i<=n;i++)
	{
		while(n%i==0)
		{
			res.push_back(i);
			n=n/i;
		}
	}
	if(n!=1)
		res.push_back(n);
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll>res;
	res=factor(n);
	ll i,x;
	x=res.size();
	for(i=0;i<x;i++)
		cout << res[i] << " ";
	cout << "\n";
	return 0;
}

