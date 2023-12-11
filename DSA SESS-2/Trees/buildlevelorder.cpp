//build tree from level order
//level order is not done without queue

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

void buildFromLevelorder(node* &root)
{
  queue<node*> q;
  cout<<"Enter data for root : ";
  int data;
  cin>>data;
  root = new node(data);
  q.push(root);

  while(!q.empty())
  {
    node*temp=q.front();
    q.pop();

    cout<<"Enter left node for: "<<temp->data<<endl;
    int leftData;
    cin>>leftData;

    if(leftData != -1)
    {
      temp->left= new node(leftData);
      q.push(temp->left);
    }

    cout<<"Enter right node for: "<<temp->data<<endl;
    int rightData;
    cin>>rightData;

    if(rightData != -1)
    {
      temp->right= new node(rightData);
      q.push(temp->right);
    }
  }
}

int main()
{
  node* root=NULL;
  //creation
  //  root=buildTree(root);
  //1,3,7,-1,-1,11,-1,-1,5,17,-1,-1,-1
  //level order traversal

  buildFromLevelorder(root);
  cout<<"Printing the levelorder traversal : "<<endl;
  levelOrderTraversal(root);
  return 0;
}