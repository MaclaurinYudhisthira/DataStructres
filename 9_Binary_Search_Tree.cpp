#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(){
        data=-1;
        left=NULL;
        right=NULL;
    }
};

class BST{
    Node *root;
    Node* _insert(Node *root,int data);
    bool _search(Node *root,int data);
    bool _inOrderTr(Node *root);
    bool _preOrderTr(Node *root);
    bool _postOrderTr(Node *root);
public:
    BST();
    void _insert(int data);
    bool _search(int data);
    void _remove();
    bool _inOrderTr();
    bool _preOrderTr();
    bool _postOrderTr();
};

BST :: BST()
{
    root=NULL;
}

Node* BST :: _insert(Node *root,int data)
{
    if(root==NULL)
    {
        root=new Node;
        root->data=data;
    }
    else
    {

        if(data<=root->data)
        {
            root->left=_insert(root->left,data);
        }
        else if(data>root->data)
        {
            root->right=_insert(root->right,data);
        }
    }
    return root;
}
bool BST :: _search(Node *root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    else if(data==root->data)
    {
        return true;
    }
    else if(data<=root->data)
    {
        this->_search(root->left,data);
    }
    else if(data>root->data)
    {
        this->_search(root->right,data);
    }
}
void BST :: _remove()
{
    cout<<"remove";
}
bool BST :: _inOrderTr(Node *root)
{
    if(root==NULL)
    {
        return false;
    }
    else
    {
        this->_inOrderTr(root->left);
        cout<<root->data<<" ";
        this->_inOrderTr(root->right);
    }
    return true;
}
bool BST :: _preOrderTr(Node *root)
{
    if(root==NULL)
    {
        return false;
    }
    else
    {
        cout<<root->data<<" ";
        this->_inOrderTr(root->left);
        this->_inOrderTr(root->right);
    }
    return true;
}
bool BST :: _postOrderTr(Node *root)
{
    if(root==NULL)
    {
        return false;
    }
    else
    {
        this->_inOrderTr(root->left);
        this->_inOrderTr(root->right);
        cout<<root->data<<" ";
    }
    return true;
}
void BST :: _insert(int data)
{
    root=_insert(root,data);
}
bool BST :: _search(int data)
{
    return _search(root,data);
}
bool BST :: _inOrderTr()
{
    return _inOrderTr(root);
}
bool BST :: _preOrderTr()
{
    return _preOrderTr(root);
}
bool BST :: _postOrderTr()
{
    return _postOrderTr(root);
}
int main()
{
    BST *t1=new BST();

    t1->_insert(11);
    t1->_insert(7);
    t1->_insert(13);
    t1->_insert(9);
    t1->_insert(6);
    t1->_insert(15);
    t1->_insert(12);
    t1->_insert(5);
    cout<<"\n";
    t1->_inOrderTr();
    cout<<"\n";
    t1->_preOrderTr();
    cout<<"\n";
    t1->_postOrderTr();
    cout<<"\n"<<t1->_search(9);
    cout<<"\n"<<t1->_search(95);
    return 0;
}
