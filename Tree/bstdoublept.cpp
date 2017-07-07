#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
	ll data;
	struct node *left,*right;
};

struct node* newnode(ll x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->left=temp->right=NULL;
	return temp;
}

void insert(struct node** rootptr,ll x)
{
	if((*rootptr)==NULL) //empty
	{
		(*rootptr)=newnode(x);
		return ;
	}
	else if(x<=((*rootptr)->data))
		insert(&((*rootptr)->left),x);
	else
		insert(&((*rootptr)->right),x);
	return;
}

bool search(struct node* ptr,ll x)
{
	if(ptr==NULL)
		return 0;
	else if((ptr->data)==x)
		return 1;
	else if(x<(ptr->data))
		return search(ptr->left,x);
	else
		return search(ptr->right,x);
}

struct node* findmin(struct node* ptr) //using loop
{
	/*if(ptr==NULL)
	{
		cout << "Tree empty\n";
		return -1;
	}
	*/
	while((ptr->left)!=NULL)
	{
		ptr=ptr->left;
	}
	return(ptr);
}

struct node* del(struct node* ptr,ll x)
{
	if(ptr==NULL)
		return ptr;
	if(x<(ptr->data))
		ptr->left=del(ptr->left,x);
	else if(x>(ptr->data))
		ptr->right=del(ptr->right,x);
	else
	{
		// 0 child
		if((ptr->left)==NULL && (ptr->right)==NULL) 
		{
			free(ptr);
			ptr=NULL;
		}
		// 1 child
		else if((ptr->left)==NULL) 
		{
			struct node* temp=ptr;
			ptr=temp->right;
			free(temp);
		}
		else if((ptr->right)==NULL)
		{
			struct node* temp=ptr;
			ptr=temp->left;
			free(temp);
		}
		//2 child
		else
		{
			struct node* temp=ptr;
			temp=findmin(ptr->right);
			ptr->data=temp->data;
			ptr->right=del(ptr->right,temp->data);
		}
	}
	return ptr;
}
			
ll findmax(struct node* ptr)  //using recursion
{
	if(ptr==NULL)
	{
		cout << "Tree empty\n";
		return -1;
	}
	else if((ptr->right)==NULL)
		return(ptr->data);
	else
		return findmax(ptr->right);
}

ll findheight(struct node* ptr)
{
	if(ptr==NULL)
		return -1;
	ll lh=findheight(ptr->left);
	ll rh=findheight(ptr->right);
	return(max(lh,rh)+1);
}

void BFS(struct node* ptr)
{
	if(ptr==NULL)
		return;
	else
	{
		deque< struct node* > Q;
		Q.push_back(ptr);
		while(!Q.empty())
		{
			struct node* temp=Q.front();
			cout << temp->data << " ";
			if((temp->left)!=NULL)
				Q.push_back(temp->left);
			if((temp->right)!=NULL)
				Q.push_back(temp->right);
			Q.pop_front();
		}
		cout << "\n";
	}
}

void preorder(struct node* root)
{
	if(root==NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(struct node* root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

int main()
{
	ios::sync_with_stdio(false);
	struct node* root=NULL;
	ll q;
	cin >> q;
	while(q--)
	{
		ll x;
		cin >> x;
		if(x==1) //INSERT
		{
			ll y;
			cin >> y;
			insert(&root,y);
		}
		else if(x==2) // Search
		{
			ll y;
			cin >> y;
			if(search(root,y))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else if(x==3) //DELETE
		{
			ll y;
			cin >> y;
			root=del(root,y);
		}
		else if(x==4) // Findmin
			cout << "Min:" << (findmin(root))->data << "\n";
		else if(x==5) // Findmax
			cout << "Max:" << findmax(root) << "\n";
		else if(x==6) //Height
			cout << "Height:" << findheight(root) << "\n";
		else if(x==7) //BFS traversal
			BFS(root) ;
		else if(x==8) //DFS traversal
		{
			inorder(root) ;
			cout << "\n";
		}
	}
	return 0;
}
