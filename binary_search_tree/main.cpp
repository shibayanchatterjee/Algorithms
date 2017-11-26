 # include<iostream>
# include<vector>
# include<stack>
# include <queue>
# include <climits>
# define max(a, b) (a > b ? a : b)

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
};
Node* createTreeNode(int data){
    Node *newNode = new Node;
    newNode -> key = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}
Node *insertTreeNode(Node *node, int data){
    Node *p;
    if (node == NULL){
        node = createTreeNode(data);
        return node;
    }
    else{
        if (data < node -> key)
            node -> left = insertTreeNode(node -> left, data);
        else
            node -> right = insertTreeNode(node -> right, data);
    }
}
void printInOrder(Node *node){
    if (node == NULL) return;
    printInOrder(node -> left);
    cout<<node -> key<<" ";
    printInOrder(node -> right);
}
vector<int> InOrderTraversal(Node *node){
    vector<int> v;
    stack<Node* > s;
    Node *currptr = node;
    while(!s.empty() or currptr){
        if(currptr){
            s.push(currptr);
            currptr = currptr -> left;
        }
        else{
            Node *tmp = s.top();
            currptr = tmp -> right;
            v.push_back (tmp ->key);
            s.pop ();
        }
    }
    return v;
}
vector<int> PreOrderTraversal(Node *node){
    vector<int> myvec;
    stack<Node *> mystack;
    if (node == NULL) return vector<int>();
    mystack.push (node);
    while(!mystack.empty ()){
        Node *ptr = mystack.top ();
        myvec.push_back (ptr -> key);
        mystack.pop();
        if (ptr -> right != NULL){
            mystack.push (ptr -> right);
        }
        if (ptr -> left != NULL){
            mystack.push (ptr -> left);
        }
    }
    return myvec;
}
vector<int> PostOrderTraversal(Node *node){
    vector<int> myvec;
    stack<Node *> mystack;
    if (!node) return vector<int>();
    Node *currNode = node;
    Node *lastNode = NULL;
    while (!mystack.empty() || currNode){
        if (currNode){
            mystack.push (currNode);
            currNode = currNode -> left;
        }
        else{
            Node *tmp = mystack.top();
            if (tmp -> right && lastNode != tmp -> right){
                currNode = tmp -> right;
            }
            else{
                myvec.push_back(tmp -> key);
                lastNode = tmp;
                mystack.pop();
            }
        }
    }
    return myvec;
}
void printPreOrder(Node *node){
    if (node == NULL) return;
    cout<<node -> key<<" ";
    printPreOrder(node -> left);
    printPreOrder(node -> right);
}
void printPostOrder(Node *node){
    if (node == NULL) return;
    printPostOrder(node -> left);
    printPostOrder(node -> right);
    cout<<node -> key<<" ";
}
Node* minTree(Node *node){
    if (!node) return NULL;
    while(node -> left)
        node = node -> left;
    return node;
}
Node* maxTree(Node *node){
    if (!node) return NULL;
    while(node -> right)
        node = node -> right;
    return node;
}
int treeSize(Node *node){
    if (!node) return 0;
    return treeSize(node -> left) + 1 + treeSize(node -> right);
}
int minDepth(Node *node){
    if (!node or (node -> left and node -> right)) return 0;
    int leftDepth = minDepth(node -> left);
    int rightDepth = minDepth(node -> right);
    return leftDepth < rightDepth ? leftDepth + 1 : rightDepth + 1;
    // return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
int maxDepth(Node *node){
    if (!node or (node -> left and node -> right)) return 0;
    int leftDepth = minDepth(node -> left);
    int rightDepth = minDepth(node -> right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
bool isBalanced(Node *node){
    if (!node) return true;
    return (maxDepth(node) - minDepth(node) <= 1) ? true : false;
}
Node* mirrorTree(Node *node){
    if (!node) return NULL;
    else{
        Node *tmp;
        if (node -> left) mirrorTree(node -> left);
        if (node ->right) mirrorTree(node -> right);
        
        tmp = node -> left;
        node -> left = node -> right;
        node -> right = tmp;
    }
    return node;
}
Node* search(Node *node, int val){
    if (!node) return NULL;
    if (node -> key == val) return node;
    else{
        if (val < node -> key)
            search(node -> left, val);
        else
            search(node -> right, val);
    }
}
vector<int> levelOrder(Node *node){
    queue<Node*> q;
    vector<int> v;
    if (node) q.push(node);
    while (!q.empty()){
        Node *ptr = q.front ();
        v.push_back(ptr -> key);
        q.pop();
        if (ptr -> left) q.push (ptr -> left);
        if (ptr -> right) q.push (ptr -> right);
    }
    return v;
}
int height(Node *node){
    if(!node) return 0;
    return (max(height(node -> left), height(node -> right)) + 1);
}
int caldiameter(Node *node){
    if (!node) return 0;
    int lheight = height(node -> left);
    int rheight = height(node -> right);
    
    int ldia = caldiameter(node -> left);
    int rdia = caldiameter(node -> right);
    return max(lheight + rheight + 1, max(ldia, rdia));
}
bool isBST(Node *node){
    return isBST(node, INT_MIN, INT_MAX);
}
bool isBST(Node *node, int min, int max){
    if (!node) return true;
    if (node -> key < min or node -> key > max) return false;
    return (isBST(node -> left, min, (node -> key) - 1) and isBST(node -> right, (node -> key) + 1, max));
}
int main(int argc, char** argv){
    Node *root = NULL;
    int a[] = {10, 8, 36, 24, 60, 48, 53};
    root = createTreeNode(a[0]);
    for (int i = 1; i < sizeof(a)/sizeof(a[0]); ++i){
        insertTreeNode(root, a[i]);
    }
    
    /*
    cout<<"Pre-Order: ";
    printPreOrder(root);
    cout<<endl;
    cout<<"Post-Order: ";
    printPostOrder(root);
    cout<<endl;*/
    
    vector<int> inorder, preorder, postorder, levelorder;
    inorder = InOrderTraversal(root);
    cout<<"In-Order: ";
    for (int i = 0; i < inorder.size(); ++i)
        cout<<inorder[i]<<" ";
    cout<<endl;
    
    preorder = PreOrderTraversal(root);
    cout<<"Pre-Order: ";
    for (int i = 0; i < preorder.size(); ++i)
        cout<<preorder[i]<<" ";
    cout<<endl;
    
    postorder = PostOrderTraversal(root);
    cout<<"Post-Order: ";
    for (int i = 0; i < postorder.size(); ++i)
        cout<<postorder[i]<<" ";
    cout<<endl;
    
    levelorder = levelOrder(root);
    cout<<"Level-Order: ";
    for (int i = 0; i < levelorder.size(); ++i)
        cout<<levelorder[i]<<" ";
    cout<<endl;
    
    int dia = caldiameter(root);
    cout<<"Diameter: "<<dia<<endl;
    
    root = mirrorTree(root);
    inorder = InOrderTraversal(root);
    cout<<"In-Order, mirrored: ";
    for (int i = 0; i < inorder.size(); ++i)
        cout<<inorder[i]<<" ";
    cout<<endl;
    
    dia = caldiameter(root);
    cout<<"Diameter: "<<dia<<endl;
    
    return 0;
}

