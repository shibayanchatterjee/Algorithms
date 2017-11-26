#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int key;
    Node *next, *random;
    Node(int x){
        key = x;
        next = random = NULL;
    }
};
class LinkedList{
public:
    void display(Node *head);
    Node* clone(Node *head);
    void middle(Node *head);
    Node* appendlist(Node *head);
};

Node* ziplist(Node *head){
    
}

void LinkedList::display (Node* head){
    Node *ptr = head;
    while (ptr){
        cout<<ptr -> key<<" ";
        ptr = ptr -> next;
    }
    cout<<"NULL"<<endl;
}
Node* LinkedList::clone (Node* head){
    if (!head) return NULL;
    Node *newhead, *l1, *l2;
    for (l1 = head; l1 != NULL; l1 = l1 -> next -> next){
        l2 = new Node(l1 -> key);
        l2 -> next = l1 -> next;
        l1 -> next = l2;
    }
    newhead = head -> next;
    for(l1 = head; l1 != NULL; l1 = l1 -> next -> next){
        if (l1 -> random != NULL) l1 -> next -> random = l1 -> random -> next;
    }
    for(l1 = head; l1 != NULL; l1 = l1 -> next){
        l2 = l1 -> next;
        l1 -> next = l2 -> next;
        if (l2 -> next != NULL) l2 -> next = l2 -> next -> next;
    }
    return newhead;
}
void LinkedList::middle(struct Node *head){
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
 
    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->key);
    }
}

LinkedList l;

int main ( int argc, char** argv ) {
    Node *start = new Node(8);
    start -> next = new Node(13);
    start -> next -> next = new Node(29);
    start -> next -> next -> next = new Node(19);
    start -> next -> next -> next -> next = new Node(21);
    l.display (start);
    
    // Setting the random pointer, for cloning
    start -> random = start -> next -> next;
    start -> next -> random = start;
    start -> next -> next -> random = start -> next -> next -> next -> next;
    start -> next -> next -> next -> random = start -> next;
    
    // Cloning linked-list
    Node *newstart = NULL;
    newstart = l.clone (start);
    l.display(newstart);
    return 0;
}