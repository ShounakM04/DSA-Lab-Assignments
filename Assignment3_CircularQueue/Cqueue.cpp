#include <iostream>
using namespace std;

class Queue{
    private:
    int front,rear;
    int arr[10];

    public:
    Queue(){
        front=0;
        rear=0;
    }
    bool isEmpty(){
        if(rear==front){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if((rear+1)%10==front){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int element){
        if(isFull()){
            cout<<"Queue is full."<<endl;
        }
        else{
            arr[rear]=element;
            rear=((rear+1)%10);
        }
    }

    int dequeue(){
        int x;
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
            return 0;
        }
        else{
            x=arr[front];
            front=((front+1)%10);
            return x;
        }
    }

    void display(){
        if(front<rear){
            for(int i=front;i<rear;i++){
                cout<<arr[i]<<"   ";
            }
        }
        else{
            for(int i=front;i<10;i++){
                cout<<arr[i]<<"   ";
            }
            for(int i=0;i<rear;i++){
                cout<<arr[i]<<"   ";
            }
        }
        cout<<endl;
        cout<<"Front: "<<front<<endl;
        cout<<"Rear: "<<rear<<endl;
        cout<<endl;
    }

    int menu(){
        int ch;
        cout<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display all elements"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter the operation to be performed"<<endl;
        cin>>ch;
        return ch;
    }
};

