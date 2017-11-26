#include <cstdlib>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Stack{
    struct Node *top;
public:
    Stack(){
       top = NULL; 
    }
    void push(int key);
    void display();
    void pop();
    void peek();
};
void Stack::push (int key){
    Node *newNode = new Node;
    newNode -> data = key;
    newNode -> next = top;
    top = newNode;
}
void Stack::display (){
    Node *ptr = top;
    while(ptr){
        cout<<ptr -> data;
        ptr = ptr -> next;
    }
}
void Stack::pop (){
    Node *ptr = top;
    top = top -> next;
    cout<<"Popping out: "<<ptr -> data;
    delete ptr;
}
void Stack::peek (){
    cout<<"Popping out: "<<top -> data;
}
int main ( int argc, char** argv ) {

    return 0;
}

