//finding inorder successor in threaded binary tree

#include <iostream>

struct node
{
    int data;
    node* left;
    node* right;
    bool leftthread;
    bool rightthread;
};

// Helper function to create a new node
node* createNode(int data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->leftthread = false;
    newNode->rightthread = false;
    return newNode;
}

// Function to create a threaded binary tree
node* createThreadedBinaryTree()
{
    node* root = createNode(1);
    node* node2 = createNode(2);
    node* node3 = createNode(3);
    node* node4 = createNode(4);
    node* node5 = createNode(5);

    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = root;
    node3->left = root;
    node3->right = node5;
    node4->left = nullptr;
    node4->right = node2;
    node5->left = node3;
    node5->right = nullptr;

    root->leftthread = true;
    root->rightthread = false;
    node2->leftthread = false;
    node2->rightthread = true;
    node3->leftthread = false;
    node3->rightthread = true;
    node4->leftthread = true;
    node4->rightthread = false;
    node5->leftthread = false;
    node5->rightthread = true;

    return root;
}

// In-order traversal of a threaded binary tree
void inOrderTraversal(node* root)
{
    if (!root)
        return;

    node* current = root;
    while (current->leftthread)
        current = current->left;
    
    while (current)
    {
        std::cout << current->data << " ";
        
        if (current->rightthread)
            current = current->right;
        else
        {
            current = current->right;
            while (current->leftthread)
                current = current->left;
        }
    }
}

// Function to find the inorder successor of the current node
int InorderSucc(node* currentnode, node* root)
{
    node* temp = currentnode->right;

    if (!currentnode->rightthread)
    {
        while (!temp->leftthread)
            temp = temp->left;
    }

    currentnode = temp;

    if (currentnode == root)
        return 0;
    else
        return currentnode->data;
}

int main()
{
    node* root = createThreadedBinaryTree();

    std::cout << "In-order traversal of the threaded binary tree: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    node* currentnode = root->left; // Set the current node to a specific node for testing

    int successor = InorderSucc(currentnode, root);
    if (successor != 0)
    {
        std::cout << "Inorder successor of the current node "<<currentnode->data <<" is: "<< successor << std::endl;
    }
    else
    {
        std::cout << "No inorder successor for the current node." <<currentnode->data<< std::endl;
    }

    return 0;
}
