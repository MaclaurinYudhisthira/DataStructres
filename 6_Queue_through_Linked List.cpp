#include<iostream>
using namespace std;
class Node{
public:
    Node *next;
    int data;
    Node(){
        data=0;
        next=NULL;
    }
};
class LinkedList{
    Node *start;    //front end of queue
    Node *_end;     // rare end of queue
public:
    int size_of_list;
    LinkedList(){
        start=NULL;
        _end=NULL;
        size_of_list=0;
    }
    void insertAtEnd(int);
    int delFromStart();
    int traverse();
};
void LinkedList:: insertAtEnd(int data)
{
    if(start==NULL){
        start=new Node();
        start->data=data;
        _end=start;
    }
    else{
        _end->next=new Node();
        _end->next->data=data;
        _end=_end->next;
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
    if(start==NULL){
        return -1;
    }
    else{
        Node *n=start;
        cout<<": ";
        while(n!=NULL){
            if(n->next==NULL)
            {
                cout<<n->data;
            }
            else
            {
                cout<<n->data<<", ";
            }
            n=n->next;
        }
        cout<<" ]"<<endl;
        return 1;
    }
}
int main(){
    short int choice;
    LinkedList *l1=new LinkedList();
    do
    {
        cout<<"\n1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\n";
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"Enter value to enqueue: ";
            int data;
            cin>>data;
            l1->insertAtEnd(data);
            break;
        case 2:
            if(l1->size_of_list==0)
            {
                cout<<"Queue is empty\n";
            }
            else
            {
                cout<<"Dequeued element: "<<l1->delFromStart()<<endl;
            }
            break;
        case 3:
            if(l1->size_of_list==0)
            {
                cout<<"Queue is empty\n";
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
