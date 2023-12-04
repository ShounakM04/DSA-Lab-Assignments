#include <iostream>
#include <C:\Users\Shounak\Desktop\DSAL\Assignment3_CircularQueue\Cqueue.cpp>
using namespace std;

int main(){
    Queue q;
   while(1){
        int x=q.menu();
        switch(x){
            case 1:
                cout<<"enter element to be enqueued."<<endl;
                int elem;
                cin>>elem;
                q.enqueue(elem);
                break;

            case 2:
                cout<<"Dequeued element is: "<<q.dequeue()<<endl;
                break;

            case 3:
                cout<<endl;
                cout<<"Queue"<<endl;
                q.display();
                break;

            case 4:
                exit(0);

        }
    }
    return 0;
}
