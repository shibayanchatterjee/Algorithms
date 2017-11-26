#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int val;
    Node *next;
};

class Stacks{
    Node *top = NULL;
    int len = 0;
public:
    void push(int key);
    void pop();
    void display();
    void size();
    void peek();
};

void Stacks::push (int data){
    struct Node *newNode = new Node;
    newNode -> val = data;
    newNode -> next = top;
    top = newNode;
    len ++;
}
void Stacks::display (){
    Node *ptr = top;
    while (ptr){
        cout<<ptr -> val<<" -> ";
        ptr = ptr -> next;
    }
    cout<<"NULL"<<endl;
}
void Stacks::pop(){
    Node *tmp = top;
    top = top -> next;
    delete (tmp);
    len --;
}
void Stacks::size (){
    cout<<"Size: "<<len<<endl;
}
void Stacks::peek (){
    cout<<"Top elem: "<<top -> val<<endl;
}

Stacks s;

int main ( int argc, char** argv ) {
    int a[] = {12, 18, 5, 46, 37, 28, 7};
    s.push(a[0]);
    s.push (a[1]);
    s.push(a[3]);
    s.display();
    s.size ();
    s.peek ();
    s.pop();
    s.push (a[4]);
    s.push (a[5]);
    s.display();
    s.size ();
    s.peek ();
    s.pop ();
    s.display();
    s.size ();
    s.peek ();
    s.push (a[6]);
    s.display();
    s.peek();
    s.size();
    return 0;
}

