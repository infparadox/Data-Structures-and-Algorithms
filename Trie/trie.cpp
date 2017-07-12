#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
	map< char,struct node* >m;
	bool isleaf;
};

node* newnode()
{
	struct node* temp;
	//temp=(struct node*)malloc(sizeof(struct node));
	temp=new node;
	(temp->isleaf)=false;
	return temp;
}

void insert(node** rootptr,string s)
{
	ll n=s.size(),i;
	node *cur= *rootptr;
	for(i=0;i<n;i++)
	{
		if(cur->m.find(s[i]) == cur->m.end()) // not found
			cur->m[s[i]]=newnode();
		
		cur=cur->m[s[i]];
	}
	cur->isleaf=true;
}

bool search(node* ptr,string s)
{
	ll n=s.size(),i;
	if(ptr==NULL)
		return false;
	for(i=0;i<n;i++)
	{
		if((ptr)->m.find(s[i])==(ptr)->m.end()) // not found
			return false;
	 	ptr=(ptr)->m[s[i]];
	}
	return(ptr->isleaf);
}

bool prefixsearch(node* ptr,string s)
{
	ll n=s.size(),i;
	if(ptr==NULL)
		return false;
	bool fl=1; // found
	for(i=0;i<n;i++)
	{
		if((ptr)->m.find(s[i])==(ptr)->m.end()) // not found
		{
			fl=0;
			break;
		}
	 	ptr=(ptr)->m[s[i]];
	}
	return fl;
}

int main()
{
	ios::sync_with_stdio(false);
	node* root=newnode();
	ll q;
	cin >> q;
	while(q--)
	{
		ll x;
		cin >> x;
		if(x==1) // insert
		{
			string str;
			cin >> str;
			insert(&root,str);
		}
		else if(x==2) // complete word search
		{
			string str;
			cin >> str;
			bool fl;
			fl=search(root,str);
			if(fl)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else if(x==3) // prefix based search
		{
			string str;
			cin >> str;
			bool fl;
			fl=prefixsearch(root,str);
			if(fl)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}
