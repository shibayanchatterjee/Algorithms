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
	struct Node* fhead, *tail, *rhead;
	LinkedList(){
		fhead = NULL;
		tail = NULL;
		rhead = NULL;
	}
public:
	void insert_front();
	void insert_back();
	void display(Node *head);
	Node* remove(int k);
	bool isCycle(Node *head);
	Node* commonNode();
	Node* findkth(int k);
	int cyclelength();
	Node* startnode();
};

void LinkedList::insert_front(){
	int arr[] = {12, 5, 24, 36, 19, 29};
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i){
		Node *newNode = new Node(arr[i]);
		newNode -> next = fhead;
		fhead = newNode;
	}
	display(fhead);
}

void LinkedList::insert_back(){
	int arr[] = {12, 5, 24, 36, 19, 29};
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i){
		Node *newNode = new Node(arr[i]);
		if (!rhead){
			newNode -> next = rhead;
			rhead = newNode;
		}
		else
			tail -> next = newNode;
		tail = newNode;
	}
	display(fhead);
}

int main(){

	return 0;
}
