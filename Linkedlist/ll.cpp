#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
    Node *head1 = new Node;
public:
    LinkedList(){
        head1 = NULL;
    }
    void insert(int key);
    void display(Node *node);
    void remove();
    void addNode(int val);
    void revlist();
    void findkth(int k);
    void testcyclicity();
    int minVal();
    int maxVal();
};

void LinkedList::maxVal (){
    Node *ptr = head1;
    int maxV = INT_MIN;
    while (ptr){
        if (ptr -> data > maxV)
            maxV = ptr -> data;
        ptr = ptr -> next;
    }
    cout<<"Max. val: "<<maxV;
}
void LinkedList::minVal (){
    Node *ptr = head1;
    int minV = INT_MAX;
    while (ptr){
        if (ptr -> data < minV)
            minV = ptr -> data;
        ptr = ptr -> next;
    }
    cout<<"Min. val: "<<minV;
}
void LinkedList::addNode (int val){
    Node *ptr = head1;
    
    Node *newNode = new Node;
    newNode -> data = val;
    newNode -> next = NULL;
    if (val < ptr -> data){
        newNode -> next = ptr;
        head1 = newNode;
    }
    else{
        int flag = 0;
        while (ptr->next){
            if (val < ptr->next->data){
                newNode -> next = ptr -> next;
                ptr -> next = newNode;
                flag = 1;
                break;
            }
            ptr = ptr -> next;
        }
        if (flag == 0){
            ptr -> next = newNode;
        }
    }
    display(head1);
}
void LinkedList::insert(int key){
    Node *newNode = new Node;
    newNode -> data = key;
    newNode -> next = head1;
    head1 = newNode;
    display(head1);
}
void LinkedList::display(Node *node){
    Node *ptr = node;
    while (ptr){
        cout<<ptr -> data<<"->";
        ptr = ptr -> next;
    }
    cout<<"NULL"<<endl;
}
void LinkedList::revlist (){
    Node *prevNode, *nextNode, *currNode;
    prevNode = nextNode = NULL;
    currNode = head1;
    while(currNode){
        nextNode = currNode -> next;
        currNode -> next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head1 = prevNode;
    display(head1);
}
void LinkedList::findkth (int k){
    Node *fastrunner, *slowrunner;
    fastrunner = slowrunner = head1;
    int count = 1;
    while (count <= k){
        fastrunner = fastrunner -> next;
        count ++;
    }
    while (fastrunner){
        slowrunner = slowrunner -> next;
        fastrunner = fastrunner -> next;
    }
    cout<<"Elem: "<<slowrunner -> data<<endl;
}
void LinkedList::testcyclicity (){
    Node *slowrunner, *fastrunner;
    int flag = 0;
    slowrunner = fastrunner = head1;
    while(fastrunner and fastrunner -> next){
        fastrunner = fastrunner -> next -> next;
        slowrunner = slowrunner -> next;
        if (fastrunner == slowrunner){
            flag = 1;
            break;
        }
    }
    if (flag == 1){
        cout<<"LL has a cycle "<<endl;
        int len = 1;
        while(fastrunner != slowrunner){
            fastrunner = fastrunner -> next;
            len ++;
        }
        fastrunner = head1;
        while(fastrunner != slowrunner){
            fastrunner = fastrunner -> next;
            slowrunner = slowrunner -> next;
        }
        cout<<"Cycle head: "<<slowrunner -> data;
        cout<<"Cycle len: "<<len;
    }   
    else
        cout<<"LL has no cycle "<<endl;
}

LinkedList l;

int main(){
    int a[] = {47, 36, 19, 15, 10};
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); ++i){
        l.insert(a[i]);
    }
    l.addNode(20);
    l.addNode(5);
    l.addNode(50);

    l.revlist ();
    l.findkth (3);
    l.testcyclicity ();
    return 0;
}