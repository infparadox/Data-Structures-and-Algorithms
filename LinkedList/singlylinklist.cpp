#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
	ll data;
	struct node* next;
};

struct node* newnode(ll x)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}

void insert(struct node** rootptr,ll x,ll n)
{
	struct node* ptr=newnode(x);
	if(n==1)
	{
		ptr->next=*rootptr;
		*rootptr=ptr;
	}
	else
	{
		struct node* temp=*rootptr;
		ll i;
		for(i=1;i<n-1;i++)
			temp=temp->next;
		ptr->next=temp->next;
		temp->next=ptr;
	}
}

void print(struct node* head)
{
	if(head==NULL)
	{
		cout << "Empty\n";
		return;
	}
	struct node* temp=head;
	while(temp!=NULL)
	{
		cout << temp->data << " ";
		temp=temp->next;
	}
	cout << "\n";
}

ll search(struct node* head,ll x)
{
	ll pos=1;
	bool fl=0;
	struct node* temp=head;
	while(temp!=NULL)
	{
		if((temp->data)==x)
		{
			fl=1;
			break;
		}
		temp=temp->next;
		pos++;
	}
	if(fl)
		return pos;
	else
		return -1;
}

void del(struct node** rootptr,ll n)
{
	if((*rootptr)==NULL)
	{
		cout << "Empty\n";
		return;
	}
	struct node* temp=(*rootptr);
	if(n==1)
	{
		(*rootptr)=temp->next;
		free(temp);
	}
	else
	{
		ll i;
		struct node* temp2;
		for(i=1;i<n-1;i++)
			temp=temp->next;
		temp2=temp->next;
		temp->next=temp2->next;
		free(temp2);
	}
}

void reverse(struct node **rootptr)
{
	struct node *pre,*cur,*next;
	pre=NULL;
	cur=(*rootptr);
	while(cur!=NULL)
	{
		next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
	}
	(*rootptr)=pre;
}


int main()
{
	ios::sync_with_stdio(false);
	struct node* head=NULL;
	ll q;
	cin >> q;
	while(q--)
	{
		ll x,y,n;
		cin >> n;
		if(n==1)      //insert
		{
			cin >> y >> n;
			insert(&head,y,n);
		}
		else if(n==2) //search
		{
			cin >> y;
			ll ans=search(head,y);
			if((ans)==-1)
				cout << "Not Found\n";
			else
				cout << "Found at " << ans << "\n";
		}
		else if(n==3) //delete
		{
			cin >> n;
			del(&head,n);
		}
		else if(n==4)        // print
			print(head);
		else                //reverse
			reverse(&head); 
	}
	return 0;
}
