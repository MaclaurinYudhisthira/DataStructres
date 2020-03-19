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
    LinkedList(){
        start=NULL;
        cout<<"A new list is created successfully.\n";
    }
    void addFront(){
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
        }
        cout<<"Added node successfully.\n";
    }
    void addRare(){
        if(start==NULL){
            cout<<"list is empty\n";
        }
        else{
            Node *n=start;
            while(n->next!=NULL){
                n=n->next;
            }
            n->next=new Node();
            cout<<"Enter data:";
            cin>>n->next->data;
        }
        cout<<"Added node successfully.\n";
    }
    void delFront(){
        if(start==NULL){
            cout<<"list is empty";
        }
        else{
            Node *temp=start;
            start=temp->next;
            cout<<"Deleted: "<<temp->data;
            delete temp;
        }
    }
    void delRare(){
        if(start==NULL){
            cout<<"list is empty";
        }
        else{
            Node *n=start;
            while(n->next->next!=NULL){
                n=n->next;
            }
            Node *temp=n->next;
            n->next=NULL;
            cout<<"Deleted: "<<temp->data;
            delete temp;
        }
    }
    void traverse(){
        cout<<"Traverse:\n";
        if(start==NULL){
            cout<<"list is empty.\n";
        }
        else{
            Node *n=start;
            while(n!=NULL){
                cout<<n->data<<endl;
                n=n->next;
            }
        }
    }
    void reverseList(){
        if(start==NULL){
            cout<<"list is empty.\n";
        }
        else{
            Node *temp1=start;
            Node *temp2=temp1->next;
            Node *temp3=temp2->next;
            temp1->next=NULL;
            while(temp3!=NULL)
            {
                temp2->next=temp1;
                temp1=temp2;
                temp2=temp3;
                temp3=temp3->next;
            }
            start=temp2;
            cout<<"Reversed successful\n";
        }
    }
};
int main(){
    short int choice;
    LinkedList *l1=NULL;
    do
    {
        cout<<"1.Create\n2.Insert at beginning\n3.Insert at end\n4.Delete from beginning\n5.Delete from end\n6.Traverse\n7.Reversed\n8.Exit\n";
        cin>>choice;
        switch(choice){
        case 1:
            l1=new LinkedList();
            break;
        case 2:
            l1->addFront();
            break;
        case 3:
            l1->addRare();
            break;
        case 4:
            l1->delFront();
            break;
        case 5:
            l1->delRare();
            break;
        case 6:
            l1->traverse();
            break;
        case 7:
            l1->reverseList();
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
