#include <cstdlib>
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *next;
};

class Queue{
    Node *head = NULL, *tail = NULL;
    int len = 0;
public:
    void enqueue(int data);
    void dequeue();
    void size();
    void front();
    void display();
};

void Queue::display(){
    Node *ptr = NULL;
    cout<<"Display: ";
    ptr = head;
    while (ptr){
        cout<<ptr -> val<<" -> ";
        ptr = ptr -> next;
    }
    cout<<"NULL"<<endl;
}
void Queue::enqueue (int data){
    struct Node* newNode = new Node;
    newNode -> val = data;
    newNode -> next = NULL;
    if (head == NULL)
        head = tail = newNode;
    else{
        Node *ptr = head;
        while (ptr){
            if (ptr -> next == NULL){
                ptr -> next = newNode;
                break;
            }
            ptr = ptr -> next;
        }
        tail = newNode;
    }
    len ++;
    cout<<"Enqueued: "<<data<<endl;
}
void Queue::dequeue (){
    Node *tmp = head;
    head = head -> next;
    cout<<"Dequeued: "<<tmp -> val<<endl;
    delete (tmp);
    len --;
}
void Queue::size (){
    cout<<"Size: "<<len<<endl;
}
void Queue::front (){
    cout<<"Front elem: "<<head -> val<<endl;
}

Queue q;

int main ( int argc, char** argv ) {
    int a[] = {10, 25, 16, 8, 24, 29, 7, 21};
    q.enqueue (a[0]);
    q.enqueue (a[1]);
    q.enqueue (a[2]);
    q.enqueue (a[3]);
    q.display ();
    q.front ();
    q.size ();
    q.dequeue ();
    q.size ();
    q.front ();
    q.display ();
    q.enqueue (a[4]);
    q.enqueue (a[5]);
    q.display ();
    q.size ();
    q.front ();
    q.enqueue (a[6]);
    q.size ();
    q.display ();
    return 0;
}