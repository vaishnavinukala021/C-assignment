#include<stdio.h>
#include<stdlib.h>
typedef struct NodePtr
{
int value;
struct NodePtr *left;
struct NodePtr *right;

}Node;

Node* createNode(int value)
{
Node *node=(Node*)malloc(sizeof(Node));
node->value=value;
node->left = node->right=NULL;
return node;
}

Node* insert(Node *root,int value)
{
if(root == NULL)
{
root=createNode(value);
}
else if(value < root->value)
{
root->left=insert(root->left,value);
}
else if(value > root->value)
{
root->right=insert(root->right,value);
}
return root;

}

Node* fm(Node *root)
{
if(root->left)
{
root=fm(root->left);
}
return root;
}

Node* delete(Node* root,int value)
{
if(root)
{
if(value>root->value)
{
root->right=delete(root->right,value);
}
else if(value<root->value)
{
root->left=delete(root->left,value);
}
else if(value == root->value)
{
if(root->left && root->right)
{
Node *minNode= fm(root->right);
root->value=minNode->value;
root->right=delete(root->right, minNode->value);
}
else
{
Node *nodeToDelete=root;
if(root->left)
{
root=root->left;
}
else
{
root=root->right;
}
free(nodeToDelete);
}
}
}
return root;
}


void print(Node *root)
{
if(root)
{
printf("\n %d",root->value);
print(root->left);
print(root->right);
}
}

int main()
{
Node *root=NULL;
root=insert(root,60);
root=insert(root,50);
root=insert(root,100);
root=insert(root,70);
root=insert(root,80);
root=insert(root,66);
root=insert(root,10);
root=insert(root,3);

print(root);
printf("\n \n \n");

delete(root,10);
print(root);
return 0;
}
