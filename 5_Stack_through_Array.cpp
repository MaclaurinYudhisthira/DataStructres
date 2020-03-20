#include<iostream>
using namespace std;
class Stack{
int * arr;
int top;
int n;
public:
    Stack(){
        cout<<"Enter size of stack: ";
        cin>>n;
        arr= new int[n];
        top=-1;
    }
    ~Stack(){
        delete arr;
    }
    void push();
    int pop();
    void traverse();
};
void Stack :: push(){
    if(top==n-1){
        cout<<"Stack overflow";
    }
    else{
        cout<<"Enter the item: ";
        cin>>arr[++top];
    }
}
int Stack :: pop(){
    if(top==-1){
        cout<<"Stack underflow";
    }
    else{
        cout<<"Popped item: "<<arr[top--]<<endl;
    }
}
void Stack::traverse(){
    if(top==-1){
        cout<<"Stack underflow";
    }
    else{
        for(int i=top;i>-1;i--){
            cout<<"| "<<arr[i]<<" ";
        }
        cout<<"]\n";
    }
}

int main(){
    short int choice;
    Stack *st=new Stack();
    do
    {
        cout<<"\n1.Push\n2.Pop\n3.Traverse\n4.Exit\n";
        cin>>choice;
        switch(choice){
        case 1:
            st->push();
            break;
        case 2:
            st->pop();
            break;
        case 3:
            st->traverse();
            break;
        case 4:
            break;
        default:
            cout<<"Invalid input";
            break;
        }
    }while(choice!=4);
    return 0;
}
