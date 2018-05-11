#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll si=1e5;
ll lev[si];
bool vis[si];

void dfs(vector< list<ll > >&G,ll s)
{
	vis[s]=1;
	for(auto it=G[s].begin();it!=G[s].end();it++)
	{
		if(!vis[*it])
		{
			lev[*it]=lev[s]+1;
			dfs(G,*it);
		}
	}
}

string func(string s)
{
	string cur=s;
	ll n=s.size();
	for(ll i=0;i<n;i++)
	{
		if(cur[i]>='A' && cur[i]<='Z')
			cur[i]+=32;
	}
	return cur;
}
int main()
{
	ios::sync_with_stdio(false);
	ll n,i;
	cin >> n;
	ll in=0;
	unordered_map<string,ll>M;
	vector< list<ll> >G(si);
	string s="polycarp";
	M[s]=in; // Root
	in++;
	for(i=0;i<si;i++)
		vis[i]=0;
	for(i=0;i<n;i++)
	{
		string s1,s2,s3;
		cin >> s1 >> s2 >> s3;
		s1=func(s1);
		s3=func(s3);
		M[s1]=in;
		in++;
		G[M[s3]].push_back(M[s1]);
		//G[M[s1]].push_back(M[s3]);
	}
	dfs(G,0);
	ll ans=0;
	for(i=0;i<in;i++)
		ans=max(ans,lev[i]);
	ans++;
	cout << ans << "\n";
	return 0;
}