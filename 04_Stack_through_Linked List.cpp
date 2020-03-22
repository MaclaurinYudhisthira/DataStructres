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
public:
    int size_of_list;
    LinkedList(){
        start=NULL;
        size_of_list=0;
    }
    void insertAtStart(int);
    int delFromStart();
    int traverse();
};
void LinkedList:: insertAtStart(int data){
    if(start==NULL){
        start=new Node();
        start->data=data;
    }
    else{
        Node *temp=start;
        start=new Node();
        start->data=data;
        start->next=temp;
    }
    size_of_list++;
}
int LinkedList:: delFromStart(){
    if(start==NULL){
        return -1;
    }
    else{
        int data;
        if(size_of_list!=1)
        {
            Node *temp=start->next;
            data=start->data;
            delete start;
            start=temp;
        }
        else
        {
            data=start->data;
            delete start;
            start=NULL;
        }
        size_of_list--;
        return data;
    }
}

int LinkedList:: traverse(){
    cout<<"\nTraverse:\n";
    if(start==NULL){
        return -1;
    }
    else{
        Node *n=start;
        while(n!=NULL){
            if(n->next==NULL)
            {
                cout<<n->data<<" ]";
            }
            else
            {
                cout<<n->data<<", ";
            }
            n=n->next;
        }
        cout<<endl;
        return 1;
    }
}
int main(){
    short int choice;
    LinkedList *l1=new LinkedList();
    do
    {
        cout<<"\n1.Push\n2.Pop\n3.Traverse\n4.Exit\n";
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"Enter value to push: ";
            int data;
            cin>>data;
            l1->insertAtStart(data);
            break;
        case 2:
            if(l1->size_of_list==0)
            {
                cout<<"Stack underflow\n";
            }
            else
            {
                cout<<"Popped element: "<<l1->delFromStart()<<endl;
            }
            break;
        case 3:
            if(l1->size_of_list==0)
            {
                cout<<"Stack underflow\n";
            }
            else
            {
                l1->traverse();
            }
            break;
        case 4:
            cout<<"Exiting";
            break;
        default:
            cout<<"Invalid input";
            break;
        }
    }while(choice!=4);
}
