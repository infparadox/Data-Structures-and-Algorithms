#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll>a;
	ll pro,carry=0,i,j;
	a.push_back(1);
	for(j=2;j<=n;j++)
	{
		carry=0;
		for(i=0;i<a.size();i++)
		{
			pro=a[i]*j+carry;
			a[i]=pro%10;
			carry=pro/10;
		}
		while(carry!=0)
		{
			a.push_back(carry%10);
			carry=carry/10;
		}
	}
	for(i=a.size()-1;i>=0;i--)
		cout << a[i];
	cout << "\n";
	return 0;
}
