#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
unordered_map<string,ll>cnt;
string str;
ll ma=0,si=0;
ll dp[40001];
ll m=1e9+7;

ll func(ll pos)
{
	if(pos==si)
		return 1;
	if(dp[pos]!=-1)
		return dp[pos];
	string cur="";
	dp[pos]=0;
	for(ll i=pos;i<min(pos+ma,si);i++)
	{
		cur+=str[i];
		sort(cur.begin(),cur.end());
		if(cnt.find(cur)!=cnt.end())
			dp[pos]=(dp[pos]%m+(cnt[cur]%m*func(i+1)%m)%m)%m;
	}
	return dp[pos];
}
int main()
{
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	for(ll test=1;test<=t;test++)
	{
		ll n,q,i;
		cin >> n >> q;
		cnt.clear();
		ma=0;
		for(i=0;i<n;i++)
		{
			string s;
			cin >> s;
			sort(s.begin(),s.end());
			cnt[s]++;
			ma=max(ma,(ll)s.size());
		}
		cout << "Case #" << test << ": ";
		while(q--)
		{
			str.clear();
			cin >> str;
			si=str.size();
			for(i=0;i<=si;i++)
				dp[i]=-1;
			ll ans=func(0);
			cout << ans << " ";
		}
		cout << "\n";
	}
	return 0;
}