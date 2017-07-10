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
	ll n,i;
	cin >> n;
	ll arr[n],size[n];
	for(i=0;i<n;i++)  //MAKE SET
	{
		arr[i]=i; // for storing root
		size[i]=1;// for calculating size of set 
	}
	ll q;
	cin >> q;
	while(q--)
	{
		ll x;
		cin >> x;
		if(x==1)  // FIND(A,B)
		{
			ll a,b;
			cin >> a >> b;
			bool fl=findset(arr,a,b);
			if(fl)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else if(x==2) //UNION(A,B)
		{
			ll a,b;
			cin >> a >> b;
			unionset(arr,size,a,b);
		}
		else if(x==3) //PRINT(ARR)
			print(arr,n);
		else if(x==4) //PRINT(SIZE)
			print(size,n);
	}
	return 0;
}
