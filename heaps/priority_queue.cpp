/* Build Heap - O(n)
   Extract Max= O(logn)
   Insert val = O(logn)
   Change val = O(Logn)
   */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll size,a[1000000];               //contains size of heap

void max_heapify(ll i,ll n)
{
	ll left,right,largest=i;
	left=2*i;
	right=2*i+1;
	if(left<=n && a[left]>a[i])
		largest=left;
	if(right<=n && a[right]>a[largest])
		largest=right;
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		max_heapify(largest,n);
	}
}

void build_heap(ll n)
{
	ll i;
	for(i=n/2;i>=1;i--)
		max_heapify(i,n);
}

ll maximum()
{
	return a[1];
}

ll extract_max()
{
	if(size==0)
	{
		cout << "heap is empty\n";
		return -1;
	}
	else
	{
		ll maximum=a[1];
		a[1]=a[size];
		size--;
		max_heapify(1,size);
		return maximum;
	}
}

void increase_val(ll i,ll val)
{
	if(val<a[i])
	{
		cout << "New value is less than current value, can’t be inserted\n";
		return ;
	}
	a[i]=val;
	while(i>1 && a[i/2]<a[i])
	{
		swap(a[i/2],a[i]);
			i=i/2;
	}
}

void insert_val(ll val)
{
	size++;
	a[size]=-1;   // assume all values are greater than 1
	increase_val(size,val);
}

void print(ll size)
{
	ll i;
	for(i=1;i<=size;i++)
		cout << a[i] << " " ;
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	size=n;
	ll i;
	for(i=1;i<=n;i++)
		cin >> a[i];
	build_heap(n);
	ll q;
	cin >> q;
	while(q--)
	{
		ll op;
		cin >> op;
		if(op==1) // Insert
		{
			ll x;
			cin >> x;
			insert_val(x);
		}
		else if(op==2) // Increase value at index y
		{
			ll val,y;
			cin >> val >> y;
			increase_val(y,val);
		}
		else if(op==3) // Extract Max
			cout << "MAX:" << extract_max() << "\n";
		else if(op==4) // Size
			cout << "Size:" << size << "\n";
		else if(op==5) // print
			print(size);
		else if(op==6) // Max value
			cout << "Max:" << maximum() << "\n";
	}
	return 0;
}
