#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll fre[100001];

int main()
{
	ios::sync_with_stdio(0);
	ll n;
	cin >> n;
	ll a[n],i;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
		fre[a[i]]++;
	}
	sort(a,a+n);
	if(a[0]==a[n-1])
	{
		if(n%2==0)
			cout << "Agasa\n";
		else
			cout << "Conan\n";
	}
	else
	{
		if(fre[a[n-1]]%2==1)
			cout << "Conan\n";
		else
		{
			bool fl=1;
			for(i=0;i<n;i++)
			{
				if(fre[a[i]]%2==1)
				{
					fl=0;
					break;
				}
			}
			if(fl)
				cout << "Agasa\n";
			else
				cout << "Conan\n";
		}
	}
	return 0;
}