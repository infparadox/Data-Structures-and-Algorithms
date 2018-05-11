#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mex(unordered_set<ll>set)
{
	ll ans=0;
	while(set.find(ans)!=set.end())
		ans++;
	return ans;
}

ll calcgrundy(ll n,ll grundy[])
{
	if(grundy[n]!=-1)
		return grundy[n];
	unordered_set<ll>set;
	set.insert(calcgrundy(n-2,grundy));
	set.insert(calcgrundy(n-3,grundy));
	set.insert(calcgrundy(n-5,grundy));
	grundy[n]=mex(set);
	return grundy[n];
}

int main()
{
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	ll grundy[101];
	for(ll i=0;i<=100;i++)
		grundy[i]=-1;
	grundy[0]=0;
	grundy[1]=0;
	grundy[2]=1;
	grundy[3]=1;
	grundy[4]=2;
	grundy[5]=2;
	while(t--)
	{
	ll n;
	cin >> n;
	ll i;
	ll ans=calcgrundy(n,grundy);
	if(ans!=0)
		cout << "First\n";
	else
		cout << "Second\n";
	}
	return 0;
}