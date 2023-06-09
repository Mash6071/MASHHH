#include<bits/stdc++.h>
using namespace std;
//static array
const int max_size =500;
class Queue{
public:
    int a[max_size];
    int l,r;//l=start,r=end
    Queue(){
        l=0;
        r=-1;
    }
    int getSize(){
        return r-l+1;
    }
    //1
    void enqueue(int value){
        if(r+1>=max_size){
            cout<<"Queue Is Full!"<<endl;
            return;
        }
        r++;
        a[r]=value;
    }
    //1
    void dequeue(){
        if(l>r){
            cout<<"Queue Is Empty!"<<endl;
            return;
        }
        l++;
    }
    int front(){
        if(l>r){
            cout<<"Queue Is Empty!"<<endl;
            return -1;
        }
        return a[l];
    }
};
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(12);
    q.enqueue(3);
    cout<<"Q Size : "<<q.getSize()<<endl;
    cout<<"First Element : "<<q.front()<<endl;
    q.dequeue();
    cout<<"First Element : "<<q.front()<<endl;
    q.dequeue();
    cout<<"First Element : "<<q.front()<<endl;
    q.dequeue();
    cout<<"Q Size : "<<q.getSize()<<endl;
}