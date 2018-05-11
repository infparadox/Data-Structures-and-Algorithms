#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define si 1000001
ll qrt_si;
ll arr[si],dp[si];
ll n;
vector< unordered_map<ll,ll> >cnt(1000);

void build(ll n)
{
	for(ll i=0;i<n;i++)
	{
		if(i%qrt_si==0)
			dp[i]=arr[i];
		else
			dp[i]=dp[i-1]^arr[i];
		cnt[i/qrt_si][dp[i]]++;
	}
}

void update(ll index,ll val)
{
	arr[index]=val;
	ll end=min(((index/qrt_si)+1)*qrt_si,n);
	ll start=(index/qrt_si)*qrt_si;
	ll blo=index/qrt_si;
	if(index==start)
	{
		auto it=cnt[blo].find(dp[index]);
		if((*it).second==1)
			cnt[blo].erase(it);
		else
			cnt[blo][dp[index]]--;
		dp[index]=val;
		cnt[blo][dp[index]]++;
		for(ll i=index+1;i<end;i++)
		{
			it=cnt[blo].find(dp[i]);
			if((*it).second==1)
				cnt[blo].erase(it);
			else
				cnt[blo][dp[i]]--;
			dp[i]=arr[i]^dp[i-1];
			cnt[blo][dp[i]]++;
		}
	}
	else
	{
		for(ll i=index;i<end;i++)
		{
			auto it=cnt[blo].find(dp[i]);
			if((*it).second==1)
				cnt[blo].erase(it);
			else
				cnt[blo][dp[i]]--;
			dp[i]=dp[i-1]^arr[i];
			cnt[blo][dp[i]]++;
		}
	}
}

ll query(ll index,ll val)
{
	ll ans=0,cur=val,i;
	ll block=(index/qrt_si);
	ll start= (index/qrt_si)*qrt_si;
	for(i=0;i<block;i++)
	{
		if(cnt[i].find(cur)!=cnt[i].end())
			ans+=cnt[i][cur];
		cur=cur^dp[((i+1)*qrt_si)-1];
	}
	//cout << "ans:" << ans << "\n";
	for(i=start;i<=index;i++)
	{
		if(dp[i]==cur)
			ans++;
	}
	//cout << "finans:" << ans << "\n";
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	ll q;
	cin >> n >> q;
	ll i,j;
	for(i=0;i<n;i++)
	{
		cin >> arr[i];
		dp[i]=0;
	}
	qrt_si=ceil((double)sqrt(n));
	//cout << qrt_si << "\n";
	build(n);
	while(q--)
	{
		ll x;
		cin >> x;
		if(x==1) // 1 i k update a[i]=x
		{
			ll index,val;
			cin >> index >> val;
			update(index-1,val);
		}
		else if(x==2) // query : sum - (l,r)
		{
			ll r,k;
			cin >> r >> k;
			ll ans=query(r-1,k);
			cout << ans  << "\n";
		}
	}
	return 0;
}