#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
	ll data;
	struct node* next;
	struct node* prev;
};

struct node* create(ll x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}

void insert(struct node** rootptr,ll x, ll n)
{
	struct node* ptr=create(x);
	struct node* temp=(*rootptr);
	if(temp==NULL)
	{
		(*rootptr)=ptr;
		return;
	}
	else if(n==1)
	{
		(*rootptr)->prev=ptr;
		ptr->next=(*rootptr);
		(*rootptr)=ptr;
	}
	else
	{
		for(ll i=1;i<n-1;i++)
			temp=temp->next;
		struct node* temp2=temp->next;
		if(temp2!=NULL)
		{
			temp2->prev=ptr;
			ptr->next=temp2;
			ptr->prev=temp;
			temp->next=ptr;
		}
		else
		{
			temp->next=ptr;
			ptr->prev=temp;
		}
	}
}

void print(struct node* head)
{
	struct node* temp=head;
	if(temp==NULL)
	{
		cout << "Empty\n";
		return ;
	}
	while(temp!=NULL)
	{
		cout << temp->data << " ";
		temp=temp->next;
	}
	cout << "\n";
}

void search(struct node* head,ll x)
{
	struct node* temp=head;
	bool fl=0;
	ll pos=0;
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			fl=1;
			break;
		}
		else
		{
			temp=temp->next;
			pos++;
		}
	}
	if(fl)
		cout << "Found at:" << pos << "\n";
	else
		cout << "Not Found\n";
}

void del(struct node** rootptr,ll n)
{
	struct node* temp=(*rootptr);
	if((*rootptr)==NULL)
	{
		cout << "Empty list\n";
		return ;
	}
	if(n==1)
	{
		struct node* temp2=temp->next;
		if(temp2==NULL)
			(*rootptr)=temp->next;
		else
		{
			temp2->prev=NULL;
			(*rootptr)=temp2;
		}
		free(temp);
	}
	else
	{
		for(ll i=1;i<n-1;i++)
			temp=temp->next;
		struct node* temp2=temp->next;
		if(temp2->next==NULL)
		{
			temp->next=NULL;
			free(temp2);
		}
		else
		{
			temp->next=temp2->next;
			temp=temp->next;
			temp->prev=temp2->prev;
			free(temp2);
		}
	}
}

void reverse(struct node* head)
{
	struct node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	while(temp!=NULL)
	{
		cout << temp->data << " ";
		temp=temp->prev;
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	struct node* head=NULL;
	ll q;
	cin >> q;
	while(q--)
	{
		ll op;
		cin >> op;
		if(op==1)   // INSERT
		{
			ll x,n;
			cin >> x >> n;
			insert(&head,x,n);
		}
		else if(op==2) // PRINT
			print(head);
		else if(op==3) // SEARCH
		{
			ll x;
			cin >> x;
			search(head,x);
		}
		else if(op==4) // DELETE
		{
			ll n;
			cin >> n;
			del(&head,n);
		}
		else
			reverse(head);
	}
	return 0;
}
