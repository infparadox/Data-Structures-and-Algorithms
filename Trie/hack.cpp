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

void insert(struct node* root,string s,ll k)
{
	struct node* temp=root;
	for(ll i=0;i<s.size();i++)
	{
		ll index=s[i]-'a';
		if(!(temp->child[index]))
		{
			temp->child[index]=newnode();
			(temp->child[index])->val=k;
		}
		else
		{
			if((temp->child[index])->val<k)
				(temp->child[index])->val=k;
		}
		temp=temp->child[index];
	}
}

ll search(struct node* root,string s)
{
	ll ans=-1;
	struct node* temp=root;
	for(ll i=0;i<s.size();i++)
	{
		ll index=s[i]-'a';
		if(!temp->child[index])
		{
			ans=-1;
			break;
		}
		else
			ans=(temp->child[index])->val;
		temp=temp->child[index];
	}	
	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	struct node* root=newnode();
	ll n,q,i;
	cin >> n >> q;
	for(i=0;i<n;i++)
	{
		string s;
		ll k;
		cin >> s >> k;
		insert(root,s,k);
	}
	while(q--)
	{
		string s;
		cin >> s;
		ll ans=search(root,s);
		cout << ans << "\n";
	}
	return 0;
}