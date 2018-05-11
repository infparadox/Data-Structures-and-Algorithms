#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ios::sync_with_stdio(0);
	ll n;
	cin >> n;
	ll a[n],i,j;
	for(i=0;i<n;i++)
		cin >> a[i];
	for(i=0;i<pow(2,n);i++)
	{
		for(j=0;j<n;j++)
		{
			if(i&(1<<j))
				cout << a[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}