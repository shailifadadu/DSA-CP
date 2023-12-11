//Creation of Binary search tree
//in BST on left side, all values are less than root node and on right side all values are greater than root node
//o(logn) -> insertion time complexity

#include<bits/stdc++.h>
#include<queue>
using namespace std;

class node
{
  public:
  int data;
  node*left;
  node*right;

  node(int d)
  {
    data=d;
    left=right=NULL;
  }
};

void levelOrderTraversal(node* root)
{
  queue<node*> q;
  q.push(root); 
  q.push(NULL);//separator

  while(!q.empty())
  {
    node*temp=q.front();
    q.pop();

    if(temp == NULL)//last level completely traversed
    {
       cout<<endl;
       if(!q.empty())//q still has some child nodes
       {
          q.push(NULL);
       }
    }
    else 
    {
      cout<<temp->data<<" ";
      if(temp->left)
    {
      q.push(temp->left);
    }

    if(temp->right)
    {
      q.push(temp->right);
    }
    }
  }
}

node* insertBST(node*&root,int data)
{
  if(root == NULL)
  {
    root = new node(data);
    return root;
  }

  if(data > root->data)
  {
    root->right = insertBST(root->right,data);
  }
  else 
  {
    root->left = insertBST(root->left, data);
  }
  return root;
}

void takeInput(node*&root)
{
  int data;
  cin>>data;

  while(data != -1)
  {
    root = insertBST(root,data);
    cin>>data;
  }
}

int main()
{
  node*root = NULL;
  cout<<"Enter data to create BST"<<endl;
  takeInput(root);

  cout<<"Printing BST"<<endl;
  levelOrderTraversal(root);
  return 0;
}