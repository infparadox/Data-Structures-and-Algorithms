#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool compare(const vector<ll>&a,const vector<ll>&b)
{
	if(a[2]<b[2])  // sort according to 2nd col'm
		return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	ll n,m;
	cin >> n >> m;
	ll i,j;
	vector< vector<ll> >a(n,vector<ll>(m));
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cin >> a[i][j];
	}
	sort(a.begin(),a.end(),compare);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
	return 0;
}