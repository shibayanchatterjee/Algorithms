#include <cstdlib>
#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *next;
    Node(int x){
        key = x;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* insert(Node *head, int key);
    void display(Node *head);
    Node* insert_at_end();
};

LinkedList l;

int main ( int argc, char** argv ) {
    Node *head;
    head = NULL;
    int arr[] = {2, 15, 24, 36, 13};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        l.insert(head, arr[i]);
    l.display(head);
    return 0;
}