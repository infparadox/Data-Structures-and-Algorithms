#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
	struct node* child[26];
	ll val; 
};

struct node* newnode()
{
	struct node* temp=new node;
	temp->val=0;
	for(ll i=0;i<26;i++)
		temp->child[i]=NULL;
	return temp;
}

void insert(struct node* root,string s)
{
	struct node* temp=root;
	for(ll i=0;i<s.size();i++)
	{
		ll index=s[i]-'a';
		if(!(temp->child[index]))
			temp->child[index]=newnode();
		temp=temp->child[index];
	}
	(temp->val)++;
}

ll search(struct node* root,string s)
{
	struct node* temp=root;
	for(ll i=0;i<s.size();i++)
	{
		ll index=s[i]-'a';
		if(!temp->child[index])
			return 0;
		temp=temp->child[index];
	}
	if(temp!=NULL && temp->val!=0)
		return temp->val;
	else
		return 0;
}

ll leafnode(struct node* temp)
{
	return(temp->val!=0);
}

ll freenode(struct node* temp)
{
	for(ll i=0;i<26;i++)
	{
		if(temp->child[i])
			return 0;
	}
	return 1;
}

bool delnode(struct node* temp,string s,ll level)
{
	if(temp)
	{
		if(level==s.size())
		{
			if(temp->val)
			{
				temp->val=0;
				if(freenode(temp))
					return 1;
				return 0;
			}
		}
		else
		{
			ll index=s[level]-'a';
			if(delnode(temp->child[index],s,level+1))
			{
				free(temp->child[index]);
				temp->child[index]=NULL;
				return(!leafnode(temp) && freenode(temp)); //recursively climb up, and delete eligible nodes
			}
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	ll q;
	cin >> q;
	struct node* root=newnode();
	while(q--)
	{
		ll x;
		cin >> x;
		if(x==1) // INSERT
		{
			string s;
			cin >> s;
			insert(root,s);
		}
		else if(x==2) // SEARCH
		{
			string s;
			cin >> s;
			ll cnt=search(root,s);
			if(cnt>0)
				cout << cnt << " " << "YES\n";
			else
				cout << "NO\n";
		}
		else if(x==3) // DELETE
		{
			string s;
			cin >> s;
			bool fl=delnode(root,s,0);
		}
	}
	return 0;
}