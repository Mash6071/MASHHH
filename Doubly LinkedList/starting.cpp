#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next_node;
    node *prev_node;
};
class doublyLinkedList{
    public:
        node * head;
        int size;
    doublyLinkedList(){
        head = NULL;
        size = 0;
    }
    node * create_new_node(int value){
        node * new_node=new node;
        new_node->data = value;
        new_node->next_node = NULL;
        new_node->prev_node = NULL;
        return new_node;
    }
    //O(1)
    int getSize(){
        return size;
    }
    //O(1)
    void insert_at_head(int value){
        size++;
        node * a=create_new_node(value);
        if(head==NULL){
            head = a;
            return;
        }
        a->next_node = head;
        head->prev_node = a;
        head=a;
        // node *newnode=head;
        // a->next_node=newnode;
        // newnode->prev_node=a;
        // head=a;
    }
    void insert_at_anyIndex(int index, int value){
        if(index<0 || index>size){
            return;
        }
        if(index==0){
            insert_at_head(value);
            return;
        }
        size++;
        node *a=head;
        int current_index=0;
        while(current_index!=index-1){
            a=a->next_node;
            current_index++;
        }
        node * NewNode=create_new_node(value);
        NewNode->next_node=a->next_node;
        NewNode->prev_node=a;
        node *b=a->next_node;
        b->prev_node=NewNode;
        a->next_node=NewNode;
    }
    //O(n)
    void delete_node(int index){
        if(index>=size){
            return;
        }
        node *a=head;
        int current_index=0;
        while(current_index!=index){
            a=a->next_node;
            current_index++;
        }
        node *b=a->prev_node;
        node *c=a->next_node;
        if(b!=NULL)
        b->next_node=c;
        if(c!=NULL)
        c->prev_node=b;
        delete a;
        if(index==0){
            head=c;
        }
        size--;
    }
    //O(n)
    void Traverse(){
        node *a=head;
        while(a!=NULL){
            cout<<a->data<<" ";
            a=a->next_node;
        }
        cout<<endl;
    }
    //O(n)
    void Reverse(){
        if(head==NULL){
            return;
        }
        node *a=head;
        int current_index=0;
        while(current_index!=size-1){
            a=a->next_node;
            current_index++;
        }
        node *b=head;
        while(b!=NULL){
            swap(b->next_node,b->prev_node);
            b=b->prev_node;
        }
        head=a;
    }
};
int main(){
    doublyLinkedList dl;
    dl.insert_at_head(10);
    dl.insert_at_head(20);
    dl.insert_at_head(30);
    dl.Traverse();
    cout<<dl.getSize()<<endl;
    dl.insert_at_anyIndex(2,100);
    dl.Traverse();
    cout<<dl.getSize()<<endl;
    dl.delete_node(1);
    dl.Traverse();
    cout<<dl.getSize()<<endl;
    dl.insert_at_head(10);
    dl.insert_at_head(20);
    dl.insert_at_head(30);
    dl.insert_at_anyIndex(2,100);
    dl.Traverse();
    cout<<dl.getSize()<<endl;
    dl.Reverse();
    dl.Traverse();
}