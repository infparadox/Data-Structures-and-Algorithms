#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
int main()
{
	ios::sync_with_stdio(false);
	ll n,i;
	cin >> n;
	bool flag=true;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			flag=false;
			break;
		}
	}
	if(flag)
		cout << "Prime\n";
	else
		cout << "Composite\n";
	return 0;
}


