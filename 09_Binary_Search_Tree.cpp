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
    Node* findMin(Node *root);
    Node* findMax(Node *root);
    Node* _remove(Node *root,int data);
    bool _inOrderTr(Node *root);
    bool _preOrderTr(Node *root);
    bool _postOrderTr(Node *root);
public:
    BST();
    void _insert(int data);
    bool _search(int data);
    Node* findMin();
    Node* findMax();
    void _remove(int data);
    bool _inOrderTr();
    bool _preOrderTr();
    bool _postOrderTr();
};

/***************Public_Functions********************/

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
        this->_preOrderTr(root->left);
        this->_preOrderTr(root->right);
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
        this->_postOrderTr(root->left);
        this->_postOrderTr(root->right);
        cout<<root->data<<" ";
    }
    return true;
}

Node* BST :: findMin(Node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        if(root->left==NULL)
        {
            return root;
        }
        else
        {
            return findMin(root->left);
        }
    }
}

Node* BST :: findMax(Node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        if(root->right==NULL)
        {
            return root;
        }
        else
        {
            return findMax(root->right);
        }
    }
}

Node* BST :: _remove(Node *root,int data)
{
    Node *temp=NULL;
    if(root==NULL)
    {
        return NULL;
    }
    else if(data<root->data)
    {
        root->left=_remove(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=_remove(root->right,data);
    }
    else if(data==root->data)
    {
        if(root->right && root->left)
        {
            temp=findMax(root->left);
            root->data=temp->data;
            root->left=_remove(root->left,root->data);
        }
        else if(root->right==NULL)
        {
            temp=root;
            root=root->left;
        }
        else if(root->left==NULL)
        {
            temp=root;
            root=root->right;
        }
        delete temp;
    }
    return root;
}

/***************Public_Functions********************/

BST :: BST()
{
    root=NULL;
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

Node* BST :: findMin()
{
    return findMin(root);
}

Node* BST :: findMax()
{
    return findMax(root);
}

void BST :: _remove(int data)
{
    root=_remove(root,data);
}

/***************Main_Functions********************/
int main()
{
    short int choice;
    BST *t1=new BST();
    do
    {
        cout<<"\n1.Insert \n2.Search\n3.Delete\n4.Find Maximum \
        \n5.Find Minimum\n6.Traverse\n7.Exit\n";
        cin>>choice;
        int data;
        Node *n;
        switch(choice){
        case 1:
            cout<<"\nEnter data to insert: ";
            cin>>data;
            t1->_insert(data);
            break;
        case 2:
            cout<<"\nEnter data to search: ";
            cin>>data;
            if(t1->_search(data))
            {
                cout<<"\nFound...!\n";
            }
            else
            {
                cout<<"\nNot Found...!\n";
            }
            break;
        case 3:
            cout<<"\nEnter data to delete: ";
            cin>>data;
            t1->_remove(data);
            break;
        case 4:
            n=t1->findMax();
            if(!n)
            {
                cout<<"\nTree is empty.\n";
            }
            else
            {
                cout<<"\nMaximum: "<<n->data<<endl;
            }
            break;
        case 5:
            n=t1->findMin();
            if(!n)
            {
                cout<<"\nTree is empty.\n";
            }
            else
            {
                cout<<"\nMinimum: "<<n->data<<endl;
            }
            break;
        case 6:
            cout<<"\nInOrder: ";
            t1->_inOrderTr();
            cout<<"\nPreOrder:";
            t1->_preOrderTr();
            cout<<"\nPostOrder:";
            t1->_postOrderTr();
            cout<<endl;
            break;
        case 7:
            cout<<"\nExiting\n";
            break;
        default:
            cout<<"\nInvalid input\n";
            break;
        }
    }while(choice!=7);
    return 0;
}
/**
//testing code
int main()
{
    BST *t1=new BST();

    t1->_insert(11);
    t1->_insert(6);
    t1->_insert(14);
    t1->_insert(5);
    t1->_insert(7);
    t1->_insert(13);
    t1->_insert(15);
    cout<<"\nInOrder: ";
    t1->_inOrderTr();
    cout<<"\nPreOrder:";
    t1->_preOrderTr();
    cout<<"\nPostOrder:";
    t1->_postOrderTr();
    cout<<"\n"<<t1->_search(14);
    cout<<"\n"<<t1->_search(95);
    cout<<"\n"<<t1->findMax()->data;
    cout<<"\n"<<t1->findMin()->data;
    t1->_remove(7);
    cout<<"\nInOrder: ";
    t1->_inOrderTr();
    cout<<"\nPreOrder:";
    t1->_preOrderTr();
    cout<<"\nPostOrder:";
    t1->_postOrderTr();

    return 0;
}
*/
