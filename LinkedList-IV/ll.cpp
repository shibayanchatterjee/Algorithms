#include <iostream>
#include <map>
using namespace std;

struct Node{
	int key;
	Node *next;
	Node *random;
	Node(int x){
		key = x;
		next = NULL;
		random = NULL;
	}
};

class LinkedList{
	struct Node* fhead, *tail, *rhead;
public:
	LinkedList(){
		fhead = NULL;
		tail = NULL;
		rhead = NULL;
	}
	void insert_front();
	void insert_back();
	void display(Node* head);
	Node* remove(int k);
	void isCycle();
	void commonNode();
	Node* findkth(int k);
	void findmid();
	int cyclelength();
	Node* startnode();
	void compresslist(int k);
	void reverselist();
	void reverselist_groups(int k);
	Node* reverse_groups(Node* head, int k);
	void copy_list_random_pointer();
};

void LinkedList::copy_list_random_pointer(){
	if (!fhead) display(fhead);
	Node *l1, *l2, *newNode;
	for(l1 = fhead; l1 != NULL; l1 = l1 -> next -> next){
		l2 = new Node(l1 -> key);
		l2 -> next = l1 -> next;
		l1 -> next = l2;
	}
	newNode = fhead -> next;
	for(l1 = fhead; l1 != NULL; l1 = l1 -> next -> next){
		if (l1 -> random)
			l1 -> next -> random = l1 -> random -> next;
	}
	for(l1 = fhead; l1 != NULL; l1 = l1 -> next){
		l2 = l1 -> next;
		l1 -> next = l2 -> next;
		if (l2 -> next)
			l2 -> next = l2 -> next -> next;
	}
	display(newNode);
}
void LinkedList::reverselist(){
	Node *curr, *prev, *next;
	curr = rhead;
	prev = NULL;
	while(curr){
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}
	display(prev);
}
void LinkedList::reverselist_groups(int k){
	if (k <= 0) display(rhead);
	Node *newhead;
	newhead = reverse_groups(rhead, k);
	display(newhead);
}
Node* LinkedList::reverse_groups(Node* head, int k){
	Node *next, *curr, *prev;
	curr = head;
	prev = NULL;
	int count = 0;
	while (curr and (count < k)){
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
		count ++;
	}
	if (next)
		head -> next = reverse_groups(next, k);
	return prev;
}
void LinkedList::compresslist(int k){
	if (!rhead or (k <= 1)) display(rhead);
	Node *ptr = rhead, *newhead = NULL, *tail = NULL;
	int count = 0, sum = 0;
	while (ptr){
		if (count < k){
			sum += ptr -> key;
			count ++;
		}
		if ((count == k) or (ptr -> next == NULL)){
			Node *newNode = new Node(sum);
			if (newhead == NULL)
				newhead = newNode;
			else
				tail -> next = newNode;
			tail = newNode;
			count = 0;
			sum = 0;
		}
		ptr = ptr -> next;
	}
	display(newhead);
}
void LinkedList::isCycle(){
	Node *fast, *slow;
	fast = slow = fhead;
	while (fast and fast -> next){
		fast = fast -> next -> next;
		slow = slow -> next;
		if (fast == slow){
			cout<<"List has cycle";
			break;
		}
	}
	cout<<"List has no cycle";
	cout<<endl;
}
void LinkedList::findmid(){
	Node *fast, *slow;
	fast = slow = fhead;
	while (fast and fast -> next){
		fast = fast -> next -> next;
		slow = slow -> next;
	}
	cout<<"Mid elem: "<<slow -> key<<", "<<slow<<endl;
	return;
}
void LinkedList::insert_front(){
	int arr[] = {12, 5, 24, 36, 19, 31, 29};
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i){
		Node *newNode = new Node(arr[i]);
		newNode -> next = fhead;
		fhead = newNode;
	}
	display(fhead);
}
void LinkedList::insert_back(){
	int arr[] = {14, 7, 23, 6, 19, 29};
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
	display(rhead);
}
void LinkedList::display(Node* head){
	Node *ptr = head;
	while(ptr){
		cout<<ptr -> key<<" -> ";
		ptr = ptr -> next;
	}
	cout<<"NULL"<<endl;
}
void LinkedList::commonNode(){
	Node *ptr = fhead;
	map<int, Node*> m;
	map<int, Node*>::iterator it;
	while(ptr){
		it = m.find(ptr -> key);
		if (it == m.end()){
			m[ptr -> key] = ptr;
		}
		ptr = ptr -> next;
	}
	ptr = rhead;
	while(ptr){
		it = m.find(ptr -> key);
		if (it != m.end())
			cout<<"Common node: "<<it -> first<<", "<<it -> second<<endl;
		ptr = ptr -> next;
	}
}

LinkedList l;

int main(){
	l.insert_back();
	l.insert_front();
	l.commonNode();
	l.findmid();
	l.isCycle();
	l.compresslist(4);
	l.reverselist();
	l.reverselist_groups(2);
	l.copy_list_random_pointer();
	return 0;
}
