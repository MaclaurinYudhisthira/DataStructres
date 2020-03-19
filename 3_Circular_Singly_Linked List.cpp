#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(){
        data=0;
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
        start->next=start;
    }
    else{
        Node *temp=start;
        while(temp->next!=start)
            temp=temp->next;
        cout<<temp->data<<" ";
        cout<<temp->next->data<<" ";
        temp->next=new Node();
        temp->next->next=start;
        start=temp->next;
        cout<<start->data;
        cout<<"Enter data:";
        cin>>start->data;
        //start->next=temp;
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
        while(n->next!=start){
            n=n->next;
        }
        n->next=new Node();
        cout<<"Enter data:";
        cin>>n->next->data;
        n->next->next=start;
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
            n->next->next=temp;
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
            while(temp->next!=start)
                temp=temp->next;
            temp->next=start->next;
            cout<<"Deleted: "<<start->data<<endl;
            delete start;
            start=temp->next;
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
            while(n->next->next!=start){
                n=n->next;
            }
            Node *temp=n->next;
            n->next=start;
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
        while(n->next!=start){
            if(n->next==NULL)
            {
                cout<<"pass";
                //pass
            }
            else
            {
                cout<<n->data<<", ";
            }
            n=n->next;
        }
        cout<<n->data<<" ]";
        cout<<endl;
    }
}
int main(){
    short int choice;
    LinkedList *l1=new LinkedList();
    do
    {
        cout<<"\n1.Insert at beginning\n2.Insert at end\n3.Delete from beginning \
        \n4.Delete from end\n5.Traverse\n6.Exit\n";
        cin>>choice;
        switch(choice){
        case 1:
            l1->insertAtStart();
            break;
        case 2:
            l1->insertAtEnd();
            break;
        case 3:
            l1->delFromStart();
            break;
        case 4:
            l1->delFromEnd();
            break;
        case 5:
            l1->traverse();
            break;
        case 6:
            cout<<"Exiting\n";
            break;
        default:
            cout<<"Invalid input\n";
            break;
        }
    }while(choice!=6);
    return 0;
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
l1->traverse();
l1->insertAtStart();
l1->insertAtEnd();
l1->insertAtEnd();
l1->insertAtEnd();
l1->insertAtEnd();
l1->insertAtEnd();
l1->insertAtEnd();
l1->traverse();
l1->insertAtStart();
l1->traverse();
l1->insertAtStart();
l1->traverse();
l1->insertAtStart();
l1->traverse();
l1->insertAtStart();
l1->traverse();
l1->insertAtEnd();
l1->insertAtEnd();
l1->traverse();
l1->insertAtMid();
l1->traverse();
l1->insertAtMid();
l1->traverse();
l1->delFromMid();
l1->traverse();
return 0;
}

*/
