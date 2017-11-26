#include <iostream>
#include <vector>
#include <stack>
# define max(a, b) (a > b ? a : b)
using namespace std;

struct TreeNode{
    int key;
    TreeNode *left, *right;
    int height;
};
int height(TreeNode *node){
    if(!node) return 0;
    return (node -> height);
}
int getbalance(TreeNode *node){
    if (!node) return 0;
    return height(node -> left) - height(node -> right);
}
TreeNode *newNode(int val){
    TreeNode *newnode = new TreeNode;
    newnode -> key = val;
    newnode -> left = newnode -> right = NULL;
    newnode -> height = 1;
    return newnode;
}
TreeNode *rightrotate(TreeNode *y){
    TreeNode *x = y -> left;
    TreeNode *T2 = x -> right;
    x -> right = y;
    y -> left = T2;
    y -> height = max(height(y -> left), height(y -> right)) + 1;
    x -> height = max(height(x -> left), height(x -> right)) + 1;
    return x;
}
TreeNode *leftrotate(TreeNode *x){
    TreeNode *y = x -> right;
    TreeNode *T2 = y -> left;
    y -> left = x;
    x -> right = T2;
    x -> height = max(height(x -> left), height(x -> right)) + 1;
    y -> height = max(height(y -> left), height(y -> right)) + 1;
    return y;
}
vector<int> preorderTraversal(TreeNode *node){
    if (!node) return vector<int>();
    stack<TreeNode *> s;
    vector<int> v;
    s.push(node);
    while (!s.empty()){
        TreeNode *ptr = s.top();
        v.push_back(ptr -> key);
        s.pop ();
        if (ptr -> left){
            s.push(ptr -> left);
        }
        if (ptr -> right){
            s.push(ptr -> right);
        }
    }
    return v;
}
TreeNode *insert(TreeNode *node, int val){
    if (!node) return NULL;
    if (val < node->key)
        node -> left = insert(node -> left, val);
    else if (val > node ->key)
        node -> right = insert(node -> right, val);
    else
        return node;
    
    node -> height = 1 + max(height(node -> left), height(node -> right));
    
    int balance = getbalance(node);
    if (balance > 1 and val < node -> left -> key)
        return rightrotate(node);
    if (balance < -1 and val > node -> right -> key)
        return leftrotate(node);
    if (balance > 1 and val > node -> left -> key){
        node -> left = leftrotate(node -> left);
        return rightrotate(node);
    }
    if (balance < -1 and val < node -> right -> key){
        node -> right = rightrotate(node -> right);
        return leftrotate(node);
    }
    return node;
}
int main ( int argc, char** argv ) {
    struct TreeNode *root = NULL;
 
    /* Constructing tree given in the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
              30
             /  \
           20   40
          /  \     \
         10  25    50
    */
 
    cout<<"Preorder traversal of the constructed AVL: ";
    vector<int> v;
    v = preorderTraversal(root);
    for (int i = 0; i < v.size(); ++i)
        cout<<v[i]<<" ";
    return 0;
}