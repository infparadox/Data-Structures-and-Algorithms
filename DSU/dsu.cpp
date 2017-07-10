#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
	ll data;
	ll rank;
	struct node* par;
};

map<ll, struct node* > m;

void makeset(ll x)
{
	struct node *temp=new node;
	temp->data=x;
	temp->rank=0;
	temp->par=temp;
	m[x]=temp;
}
// do path compression
struct node* findset(struct node* node)
{
	struct node* parent=node->par;
	if(parent==node)
		return parent;
	node->par=findset(node->par);
	return node->par;
}

bool unionset(ll data1,ll data2)
{
	struct node* node1=m[data1];
	struct node* node2=m[data2];

	struct node* parent1=findset(node1);
	struct node* parent2=findset(node2);

	if((parent1->data)==(parent2->data))  //same set
		return false;
	if((parent1->rank)>=(parent2->rank))
	{
		if((parent1->rank)==(parent2->rank)) // if rank is same increase by 1
			parent1->rank=parent1->rank+1;
		(parent2->par)=parent1;
	}
	else
		(parent1->par)=parent2;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	makeset(1);
	makeset(2);
	makeset(3);
	makeset(4);
	makeset(5);
	makeset(6);
	makeset(7);

	unionset(1,2);
	unionset(2,3);
	unionset(4,5);
	unionset(6,7);
//	unionset(5,6);
//	unionset(3,7);
	
	struct node* temp;
	temp=findset(m[1]);
	cout << temp->data << "\n";
	temp=findset(m[2]);
	cout << temp->data << "\n";
	temp=findset(m[3]);
	cout << temp->data << "\n";
	temp=findset(m[4]);
	cout << temp->data << "\n";
	return 0;
}

