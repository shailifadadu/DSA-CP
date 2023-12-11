//search in BST

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

bool searchBST(node*root,int x)
{
  //recursion
  // if(root == NULL)
  // {
  //   return false;
  // }
  // if(root->data == x)
  // {
  //   return true;
  // }

  // if(x < root->data)
  // {
  //   return searchBST(root->left,x);
  // }
  // else 
  // {
  //   return searchBST(root->right,x);
  // }

  //iteration
  node*temp=root;
  while(temp!=NULL)
  {
    if(temp->data == x)
    {
      return true;
    }
    if(x < temp->data)
    {
      temp=temp->left;
    }
    if(x > temp->data)
    {
      temp=temp->right;
    }
  }
  return false;
}

int main()
{
  node*root = NULL;
  cout<<"Enter data to create BST"<<endl;
  takeInput(root);

  cout<<"Printing BST"<<endl;
  levelOrderTraversal(root);

  int x;
  cout<<"element you want to search in BST : ";
  cin>>x;
  cout<<searchBST(root,x)<<endl;
  return 0;
}