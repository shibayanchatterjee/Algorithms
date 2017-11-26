struct ListNode{
    int key;
    ListNode *next;
};

ListNode* compressLinkedlist(ListNode* head, int n){
    if (!head) return head;
    int len = 0;
    ListNode *ptr =  head;
    while(ptr){
        ptr = ptr -> next;
        len ++;
    }
    if (len < n) return head;
    ptr = head;
    int k = 0, newkey;
    ListNode *newhead = NULL;
    while(ptr){
        if (k <= n){
            newkey = newkey + ptr -> key;
            k ++;
        }
        if (k == n){
            ListNode *newNode = new ListNode;
            newNode -> key = newkey;
            newNode -> next = newhead;
            newhead = newNode;
            k = 0
        }
        ptr = ptr -> next;
    }
    return newhead;
}
