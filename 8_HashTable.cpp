#include<iostream>
using namespace std;
class Item{
public:
    int key;
    int value;
    Item(){
        key=-1;
        value=-1;
    }
};
class Hashtable{
Item *arr;
int _size;
int _HashFunction(int key){
    return key%_size;
}
public:
    Hashtable(){
        cout<<"Enter the number of elements: ";
        cin>>_size;
        arr= new Item[_size];
        cout<<"HashTable created successfully.\n";
    }
    ~Hashtable(){
        delete arr;
    }
    void Add(){
        cout<<"Warning: Please do not use -1 as key............!!!\n";
        int key,val;
        cout<<"Enter key: ";
        cin>>key;
        int index=_HashFunction(key);
        if(arr[index].key!=-1){
            cout<<"Key conflict error.\n"<<endl;
        }else{
            arr[index].key=key;
            cout<<"Enter value: ";
            cin>>val;
            arr[index].value=val;
        }
    }
    void DisplayItems(){
        cout<<"Items in HashTable: ";
        for(int i=0;i<_size;i++){
            if(arr[i].key!=-1){
                cout<<arr[i].key<<": "<<arr[i].value<<endl;
            }
        }
    }
    void FindValue(){
        int key=-1;
        cout<<"Enter key: ";
        cin>>key;
        int index=_HashFunction(key);
        if(arr[index].key==-1){
            cout<<"Key not found.\n"<<endl;
        }
        else{
            cout<<arr[index].key<<": "<<arr[index].value<<endl;
        }
    }
    void Remove(){
        int key=-1;
        cout<<"Enter key: ";
        cin>>key;
        int index=_HashFunction(key);
        if(arr[index].key==-1){
            cout<<"Key not found.\n"<<endl;
        }
        else{
            cout<<"Removed item:\n";
            cout<<arr[index].key<<": "<<arr[index].value<<endl;
            arr[index].key=-1;
            arr[index].value=-1;
        }
    }
};

int main(){
    short int choice;
    Hashtable *hashT=NULL;
    do
    {
        cout<<"1.Create\n2.Add\n3.Delete\n4.Find value\n5.Traverse\n6.Exit\n";
        cin>>choice;
        switch(choice){
        case 1:
            hashT=new Hashtable();
            break;
        case 2:
            hashT->Add();
            break;
        case 3:
            hashT->Remove();
            break;
        case 4:
            hashT->FindValue();
            break;
        case 5:
            hashT->DisplayItems();
            break;
        case 6:
            break;
        default:
            cout<<"Invalid input........!!!\n";
            break;
        }
    }while(choice!=5);
}
