#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	string x;
	cin >> x;
	ll i,j,k,n;
	n=x.size();
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			for(k=i;k<=j;k++)
				cout << x[k] ;
			cout << "\n";
		}
	}
	return 0;
}
