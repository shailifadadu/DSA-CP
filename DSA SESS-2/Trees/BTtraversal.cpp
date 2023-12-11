//binary tree inorder, preorder, postorder traversal

#include<iostream>
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

node* buildTree(node*root)
{
  cout<<"Enter the data : ";
  int data;
  cin>>data;
  root=new node(data);

  if(data == -1)
  {
    return NULL;
  }
  cout<<"Enter data for inserting in left of "<<data<<endl;
  root->left = buildTree(root->left);
  cout<<"Enter data for inserting in right of "<<data<<endl;
  root->right = buildTree(root->right);
  return root;
}

void inorder(node* root)
{
  if(root == NULL)
  {
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void preorder(node* root)
{
  if(root == NULL)
  {
    return;
  }
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(node* root)
{
  if(root == NULL)
  {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

int main()
{
   node* root=NULL;
   //creation
   root=buildTree(root);
  //1,3,7,-1,-1,11,-1,-1,5,17,-1,-1,-1
  // cout<<"Inorder traversal is : \n";
  // inorder(root);

  // cout<<"preorder traversal is : \n";
  // preorder(root);

  cout<<"postorder traversal is : \n";
  postorder(root);
  return 0;
}