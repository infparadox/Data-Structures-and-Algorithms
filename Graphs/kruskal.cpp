#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll root(ll arr[],ll i)
{
	while(arr[i]!=i)
	{
		arr[i]=arr[arr[i]];
		i=arr[i];
	}
	return i;
}

void unionset(ll arr[],ll size[],ll a,ll b)
{
	ll root_a=root(arr,a);
	ll root_b=root(arr,b);
	if((root_a)==(root_b))
		return;
	else
	{
		if(size[root_a]<size[root_b])
		{
			arr[root_a]=arr[root_b];
			size[root_b]+=size[root_a];
		}
		else
		{
			arr[root_b]=arr[root_a];
			size[root_a]+=size[root_b];
		}
	}
}

bool findset(ll arr[],ll a, ll b)
{
	if(root(arr,a)==root(arr,b))
		return true;
	return false;
}

void print(ll a[],ll n)
{
	for(ll i=0;i<n;i++)
		cout << a[i] << " ";
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	ll V,i;
	cin >> V;
	ll arr[V],size[V];
	for(i=0;i<V;i++)  //MAKE SET
	{
		arr[i]=i; // for storing root
		size[i]=1;// for calculating size of set 
	}
	ll E;
	cin >> E;
	multimap<ll,pair<ll,ll> >M;
	for(i=0;i<E;i++)
	{
		ll u,v,w;
		cin >> u >> v >> w;
		M.insert(make_pair(w,make_pair(u-1,v-1)));
	}
	ll sum=0;
	for(auto it=M.begin();it!=M.end();it++)
	{
		ll u,v,w;
		w=(*it).first;
		u=((*it).second).first;
		v=((*it).second).second;
		if(!findset(arr,u,v))
		{
			unionset(arr,size,u,v);
			sum+=w;
		}
	}
	cout << sum << "\n";
	return 0;
}
