#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define size 1000000
bool vis[size];

void print(vector< list<ll> >&g,ll v)
{
	ll i;
	for(i=0;i<v;i++)
	{
		cout << i ;
		for(auto it=g[i].begin();it!=g[i].end();it++)
			cout << "-->" << *it ;
		cout << "\n";
	}
}

stack<ll>S;

void dfs(vector< list<ll> >&g,ll s)
{
	vis[s]=1;
	for(auto it=g[s].begin();it!=g[s].end();it++)
	{
		if(!vis[*it])
			dfs(g,*it);
	}
	S.push(s);
}

int main()
{
	ios::sync_with_stdio(false);
	ll v,e,i;
	cin >> v >> e;
	vector< list<ll> >g(v);
	for(i=0;i<v;i++)
	{
		g[i].clear();
		vis[i]=0;
	}
	for(i=0;i<e;i++)
	{
		ll m,n;
		cin >> m >> n;
		g[m].push_back(n);
	}
	print(g,v);
	for(i=0;i<v;i++)
	{
		if(!vis[i])
			dfs(g,i);
	}
	while(!S.empty())
	{
		cout << S.top() << " ";
		S.pop();
	}
	return 0;
}
