#include<iostream>
using namespace std;
class Stack{
int * arr;
int top;
int n;
public:
    Stack(){
        cout<<"Enter the number of elements: ";
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
        return arr[top--];
    }
}
void Stack::traverse(){
    for(int i=top;i>-1;i--){
        cout<<arr[i]<<endl;
    }
}

int main(){
    short int choice;
    Stack *st=NULL;
    do
    {
        cout<<"1.Create\n2.Push\n3.Pop\n4.Traverse\n";
        cin>>choice;
        switch(choice){
        case 1:
            st=new Stack();
            break;
        case 2:
            st->push();
            break;
        case 3:
            st->pop();
            break;
        case 4:
            (st)->traverse();
            break;
        case 5:
        default:
            cout<<"Invalid input";
            break;
        }
    }while(choice!=5);
}
