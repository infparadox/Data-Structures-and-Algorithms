#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int x) {
        left = NULL;
        right = NULL;
        data = x;
    }
};

class Solution {
    public:
    void dfs(Node* root) {
        if(root==NULL)return;
        
        dfs(root->left);
        dfs(root->right);
        cout << root->data << " ";
    }
    
    int height(Node* root) {
        if(root == NULL) return -1;
        
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh, rh) + 1;
    }  
    
    void bfs(Node* root) {
        deque<Node*> Q;
        Q.push_back(root);
        while(!Q.empty()) {
            Node* front = Q.front();
            Q.pop_front();
            cout << front->data << " ";
            if(front->left!=NULL)
                Q.push_back(front->left);
            if(front->right!=NULL)
                Q.push_back(front->right);
        }
    }
};
    
    
int main() {
    ios::sync_with_stdio(0);
    Node* root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->left->right->left = new Node(10);
    Solution solve;
    cout << solve.height(root) << "\n";
//    solve.dfs(root);
    solve.bfs(root);
    cout << "\n";
    return 0;
}
