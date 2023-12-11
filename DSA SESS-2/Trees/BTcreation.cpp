//creation of Binary tree and traverse in level order traversal(BFS)

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
  cout<<"Enter the data for new node: ";
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

int main()
{
   node* root=NULL;
   //creation
   root=buildTree(root);
  //1,3,7,-1,-1,11,-1,-1,5,17,-1,-1,-1
  //level order traversal
  cout<<"Printing the levelorder traversal : "<<endl;
  levelOrderTraversal(root);
  return 0;
}