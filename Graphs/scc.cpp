#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define size 1000000
bool vis[size];

void print(vector< list<ll> >&g,ll v)
{
	for(ll i=0;i<v;i++)
	{
		cout << i ;
		for(auto it=g[i].begin();it!=g[i].end();it++)
			cout << "-->" << *it ;
		cout << "\n";
	}
}

stack<ll>S;

void toposort(vector< list<ll> >&g,ll s)
{
	vis[s]=1;
	for(auto it=g[s].begin();it!=g[s].end();it++)
	{
		if(!vis[*it])
			toposort(g,*it);
	}
	S.push(s);
}

void dfs(vector< list<ll> >&g,ll s)
{
	vis[s]=1;
	cout << s << " ";
	for(auto it=g[s].begin();it!=g[s].end();it++)
	{
		if(!vis[*it])
			dfs(g,*it);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	ll v,e,i;
	cin >> v >> e;
	vector< list<ll> >g(v);
	vector< list<ll> >rev(v);
	for(i=0;i<v;i++)
	{
		g[i].clear();
		rev[i].clear();
		vis[i]=0;
	}
	for(i=0;i<e;i++)
	{
		ll m,n;
		cin >> m >> n;
		g[m].push_back(n);
		rev[n].push_back(m);
	}
	print(g,v);
	for(i=0;i<v;i++)
	{
		if(!vis[i])
			toposort(g,i);
	}
	for(i=0;i<v;i++)
		vis[i]=0;
	while(!S.empty())
	{
		i=S.top();
		S.pop();
		if(!vis[i])
		{
			dfs(rev,i);
			cout << "\n";
		}
	}
	return 0;
}
