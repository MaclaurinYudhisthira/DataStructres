#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *prev;
    Node *next;
    Node(){
        data=0;
        prev=NULL;
        next=NULL;
    }
};
class LinkedList{
    Node *start;
    int size_of_list;
public:
    LinkedList(){
        start=NULL;
        size_of_list=0;
        cout<<"\nA new list is created successfully.\n";
    }
    void insertAtStart();
    void insertAtEnd();
    void insertAtMid();
    void delFromStart();
    void delFromEnd();
    void delFromMid();
    void traverse();
};
void LinkedList:: insertAtStart(){
    cout<<"\nInserting at starting end of list:\n";
    if(start==NULL){
        start=new Node();
        cout<<"Enter data:";
        cin>>start->data;
    }
    else{
        Node *temp=start;
        start=new Node();
        cout<<"Enter data:";
        cin>>start->data;
        start->next=temp;
        temp->prev=start;
    }
    size_of_list++;
    cout<<"Added node successfully.\n";
}
void LinkedList:: insertAtEnd(){
    cout<<"\nInserting at end of list:\n";
    if(start==NULL){
        cout<<"list is empty.\n";
    }
    else{
        Node *n=start;
        while(n->next!=NULL){
            n=n->next;
        }
        n->next=new Node();
        cout<<"Enter data:";
        cin>>n->next->data;
        n->next->prev=n;
        size_of_list++;
        cout<<"Added node successfully.\n";
    }
}
void LinkedList:: insertAtMid(){
    cout<<"\nInserting at middle of list:\n";
    if(start==NULL){
        cout<<"list is empty.\n";
    }
    else{
        cout<<"Enter the position for new node: ";
        int pos;
        cin>>pos;
        if(pos>size_of_list || pos<1)
        {
            cout<<"Invalid Position.\n";
        }
        else
        {
            int k=1;
            Node *n=start;
            while(n->next!=NULL){
                if(k==pos-1)
                {
                    break;
                }
                else
                {
                    n=n->next;
                    k++;
                }
            }
            Node *temp=n->next;
            n->next=new Node();
            cout<<"Enter data:";
            cin>>n->next->data;
            n->next->prev=n;
            n->next->next=temp;
            temp->prev=n->next;
            size_of_list++;
            cout<<"Added node successfully.\n";
        }
    }
}
void LinkedList:: delFromStart(){
    cout<<"\nDeleting from starting end of list:\n";
    if(start==NULL){
        cout<<"list is empty.\n";
    }
    else{
        if(size_of_list!=1)
        {
            Node *temp=start->next;
            cout<<"Deleted: "<<start->data<<endl;
            delete start;
            start=temp;
            start->prev=NULL;
        }
        else
        {
            cout<<"Deleted: "<<start->data<<endl;
            delete start;
            start=NULL;
        }
        size_of_list--;
    }
}
void LinkedList:: delFromEnd(){
    cout<<"\nDeleting from end of list:\n";
    if(start==NULL){
        cout<<"list is empty.\n";
    }
    else{
        if(size_of_list!=1)
        {
            Node *n=start;
            while(n->next!=NULL){
                n=n->next;
            }
            Node *temp=n;
            n->prev->next=NULL;
            cout<<"Deleted: "<<temp->data<<endl;
            delete temp;
        }
        else
        {
            delete start;
            start=NULL;
        }
        size_of_list--;
    }
}
void LinkedList:: delFromMid(){
    cout<<"\nDeleting from middle of list:\n";
    if(start==NULL){
        cout<<"list is empty.\n";
    }
    else{
        cout<<"Enter the position for new node: ";
        int pos;
        cin>>pos;
        if(pos>size_of_list || pos<1)
        {
            cout<<"Invalid Position.\n";
        }
        else
        {
            if(pos==1)
            {
                if(size_of_list!=1)
                {
                    Node *temp=start->next;
                    cout<<"Deleted: "<<start->data<<endl;
                    delete start;
                    start=temp;
                    start->prev=NULL;
                }
                else
                {
                    cout<<"Deleted: "<<start->data<<endl;
                    delete start;
                    start=NULL;
                }
            }
            else
            {
                int k=1;
                Node *n=start;
                while(n->next!=NULL){
                    if(k==pos-1)
                    {
                        break;
                    }
                    else
                    {
                        n=n->next;
                        k++;
                    }
                }
                Node *temp=n->next;
                n->next=temp->next;
                temp->next->prev=n;
                cout<<"Deleted: "<<temp->data<<endl;
                delete temp;
            }
            size_of_list--;
        }
    }
}
void LinkedList:: traverse(){
    cout<<"\nTraverse:\n";
    if(start==NULL){
        cout<<"list is empty.\n";
    }
    else{
        Node *n=start;
        cout<<"[ ";
        while(n!=NULL){
            if(n->next==NULL)
            {
                cout<<n->data;
            }
            else
            {
                cout<<n->data<<", "<<endl;
            }
            n=n->next;
        }
        cout<<" ]"<<endl;
    }
}
int main(){
    short int choice;
    LinkedList *l1=new LinkedList();
    do
    {
        cout<<"\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete from beginning \
        \n5.Delete from end\n6.Delete from position\n7.Traverse\n8.Exit\n";
        cin>>choice;
        switch(choice){
        case 1:
            l1->insertAtStart();
            break;
        case 2:
            l1->insertAtEnd();
            break;
        case 3:
            l1->insertAtMid();
            break;
        case 4:
            l1->delFromStart();
            break;
        case 5:
            l1->delFromEnd();
            break;
        case 6:
            l1->delFromMid();
            break;
        case 7:
            l1->traverse();
            break;
        case 8:
            cout<<"Exiting\n";
            break;
        default:
            cout<<"Invalid input\n";
            break;
        }
    }while(choice!=8);
}

/*
//testing code
int main(){


LinkedList *l1=new LinkedList();

l1->traverse();
l1->insertAtMid();
l1->delFromEnd();
l1->delFromStart();
l1->insertAtEnd();
l1->insertAtStart();
l1->insertAtStart();
l1->insertAtStart();
l1->insertAtEnd();
l1->insertAtEnd();
l1->traverse();
l1->insertAtMid();
l1->traverse();
l1->insertAtMid();
l1->traverse();
l1->delFromMid();
l1->traverse();
}

*/
