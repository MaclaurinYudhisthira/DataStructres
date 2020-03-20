#include<iostream>
using namespace std;
class Queue{
int * arr;
int _front;
int _rare;
int _size;
public:
    Queue(){
        cout<<"Enter size of Queue: ";
        cin>>_size;
        arr= new int[_size];
        _front=0;
        _rare=-1;
    }
    ~Queue(){
        delete arr;
    }
    void EnQueue();
    int DeQueue();
    void traverse();
};
void Queue :: EnQueue(){
    if(_rare==_size-1){
        cout<<"Queue is full.\n";
    }
    else{
        cout<<"Enter the item: ";
        cin>>arr[++_rare];
    }
}
int Queue :: DeQueue(){
    if(_rare<_front){
        cout<<"Queue is empty.\n";
    }
    else{
        cout<<"Dequeued item: "<<arr[_front++]<<endl;
    }
}
void Queue :: traverse(){
    if(_rare<_front){
        cout<<"Queue is empty.\n";
    }
    else{
        for(int i=_front;i<=_rare;i++){
            cout<<"| "<<arr[i]<<" ";
        }
        cout<<"]\n";
    }
}

int main(){
    short int choice;
    Queue *Q1=new Queue();
    do
    {
        cout<<"\n1.EnQueue\n2.DeQueue\n3.Traverse\n4.Exit\n";
        cin>>choice;
        switch(choice){
        case 1:
            Q1->EnQueue();
            break;
        case 2:
            Q1->DeQueue();
            break;
        case 3:
            Q1->traverse();
            break;
        case 4:
            break;
        default:
            cout<<"Invalid input.\n";
            break;
        }
    }while(choice!=4);
    return 0;
}
