#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>

# define max(a, b) (a > b ? a : b)
using namespace std;

struct TreeNode{
    int key;
    TreeNode *left, *right;
    TreeNode(int x){
        key = x;
        left = right = NULL;
    }
};

class Tree{
public:
    TreeNode *createTreeNode(int val);
    TreeNode *insertTreeNode(TreeNode* node, int val);
    void display(TreeNode* node);
    vector<int> inorderTraversal(TreeNode* node);
    vector<int> preorderTraversal(TreeNode* node);
    vector<int> postorderTraversal(TreeNode* node);
    vector<int> levelorderTraversal(TreeNode* node);
    TreeNode *lca(TreeNode *node, TreeNode *p, TreeNode *q);
    bool isvalidBSTUtil(TreeNode *node, int min, int max);
    bool isvalidBST(TreeNode *node);
    int minElem(TreeNode *node);
    int maxElem(TreeNode *node);
    int treeSize(TreeNode *node);
    int minDepth(TreeNode *node);
    int maxDepth(TreeNode *node);
    int diameter(TreeNode *node);
    int height(TreeNode *node);
    int sum_root_leaves_util(TreeNode *node);
    int sum_root_leaves(TreeNode *node);
    bool hasPathSum(TreeNode *node, int sum);
    int sumofleftLeaves(TreeNode *node);
    bool isBalanced(TreeNode *node);
    void mirrorTree(TreeNode *node);
    bool isSymmetric(TreeNode *node);
    vector<vector<int>> zigzaglevelorder(TreeNode *node);
    vector<int> largestlevelValue(TreeNode *node);
    vector<int> largestlevelValueUtil(TreeNode *node, int l);
    TreeNode* inorderPredecessor(TreeNode *node);
    TreeNode* inorderSuccessor(TreeNode *node);
};

TreeNode* inorderPredecessor(TreeNode* node, TreeNode* p){
    if (p -> right){
        p = p -> right;
        while (p -> left)
            p = p -> left;
        return p;
    }
    TreeNode* tmp = NULL;
    while (node != p)
        node = (p -> key > node -> val) ? node -> right : (tmp = node) -> left;
    return tmp;
}
TreeNode* inorderSuccessor(TreeNode *node){
    
}


vector<int> largestlevelValueUtil(TreeNode *node, int l){
    if (!node) return;
    if (res.size() < l+1) res.push_back(node -> val);
    else{
        if (res[l] < node -> val) res[l] = node -> val;
    }
    largestlevelValueUtil(node -> left, l+1);
    largestlevelValueUtil(node -> right, l+1);
}
vector<int> largestlevelValue(TreeNode *node){
    if (!node) return vector<int>();
    largestlevelValueUtil(node, 0);
    return res;
}
vector<vector<int>> Tree::zigzaglevelorder(TreeNode *node){
    if (!node) return vector<vector<int>>();
    
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(node);
    bool ltor = true;
    while (!q.empty()){
        int size = q.size();
        vector<int> v(size);
        for (int i = 0; i < size; ++i){
            TreeNode *ptr = q.front();
            q.pop();
            int index = (ltor) ? i : (size-i-1);
            v[index] = ptr -> val;
            if (ptr -> left) q.push(ptr -> left);
            if (ptr -> righr) q.push(ptr -> right);
        }
        ltor = !ltor;
        ans.push_back(v);
    }
    return ans;
}
bool Tree::isSymmetric(TreeNode *node){
    if (!node) return true;
    TreeNode *l, *r;
    queue<TreeNode *> q1, q2;
    q1.push(node -> left);
    q2.push(node -> right);
    while (!q1.empty() and !q2.empty ()){
        l = q1.front();
        r = q2.front();
        if (l and r) continue;
        if (!l or !r) return false;
        if (l -> key != r -> key) return false;
        q1.push(l -> left);
        q1.push(l -> right);
        q2.push(r -> right);
        q2.push(r -> left);
    }
    return true;
}
void Tree::mirrorTree(TreeNode *node){
    if (!node) return node;
    else{
        TreeNode *tmp;
        mirrorTree(node -> left);
        mirrorTree(node -> right);
        
        tmp = node -> left;
        node -> right = node -> left;
        node -> left = node -> right;
    }
}
bool Tree::isBalanced(TreeNode *node){
    if (!node) return true;
    if (abs(maxDepth(node) - minDepth(node)) <= 1) ? true : false;
}
int Tree::sumofleftLeaves (TreeNode* node, bool isleft = false){
    if (!node) return 0;
    if (!node -> left and !node -> right) return (isleft) ? (node -> key) : 0;
    return sumofleftLeaves((node -> left), true) + sumofleftLeaves((node -> right), false);
}
int Tree::sum_root_leaves_util(TreeNode* node, int val){
    if (!node) return 0;
    val = val * 10 + node -> key;
    if (!node -> left and !node -> right) return val;
    return sum_root_leaves_util(node -> left, val) + sum_root_leaves_util(node -> right, val);
}
int Tree::sum_root_leaves (TreeNode* node){
    return sum_root_leaves_util(node, 0);
}
bool Tree::hasPathSum (TreeNode* node, int sum){
    if (!node) return false;
    if (node -> key == sum and !node -> left and !node -> right) return true;
    return hasPathSum(node -> left, sum - node -> key) or hasPathSum(node -> right, sum - node -> key);
}
int Tree::height(TreeNode *node){
    if (!node) return 0;
    return (max(height(node -> left), height(node -> right)) + 1);
}
int Tree::diameter(TreeNode *node){
    if (!node) return 0;
    int lheight = height(node -> left);
    int rheight = height(node -> right);
    
    int ldia = diameter(node -> left);
    int rdia = diameter(node -> right);
    return max(ldia + rdia + 1, max(lheight, rheight));
}
int Tree::maxDepth(TreeNode *node){
    if (!node) return 0;
    int leftDepth = maxDepth(node -> left);
    int rightDepth = maxDepth(node -> right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
int Tree::minDepth(TreeNode *node){
    if (!node) return 0;
    int leftDepth = minDepth(node -> left);
    int rightDepth = minDepth(node -> right);
    return leftDepth < rightDepth ? leftDepth + 1 : rightDepth + 1;
}
int Tree::treeSize(TreeNode* node){
   if (!node) return 0;
   return treeSize(node -> left) + 1 + treeSize(node -> right);
}
TreeNode* Tree::minElem (TreeNode* node){
    if (!node) return node;
    while (node)
        node = node -> left;
    return node;
}
TreeNode* Tree::maxElem (TreeNode* node){
    if (!node) return node;
    while (node)
        node = node -> right;
    return node;
}
bool Tree::isvalidBSTUtil (TreeNode* node, int min, int max){
    if (!node) return true;
    if (node -> key <= min or node -> key >= max) return false;
    return isValidBSTUtil(node -> left, min, node -> key) and isValidBSTUtil(node -> right, node -> key, max);
}
bool Tree::isvalidBST (TreeNode* node){
    return isvalidBSTUtil(node, INT_MIN, INT_MAX);
}
TreeNode* Tree::lca(TreeNode *root, TreeNode *p, TreeNode *q){
    if (!root or root == p or root == q) return root;
    TreeNode *left = lca(root -> left, p, q);
    TreeNode *right = lca(root -> right, p, q);
    return !left ? right : !right ? left : root;
}
TreeNode* Tree::createTreeNode (int val){
    TreeNode *newNode = new TreeNode(val);
    return newNode;
}
TreeNode* Tree::insertTreeNode (TreeNode* node, int val){
    if (!node) {
        TreeNode *tmp = createTreeNode(val);
        return tmp;
    }
    else{
        if (val < node -> key)
            node -> left = insertTreeNode(node -> left, val);
        else
            node -> right = insertTreeNode(node -> right, val);
    }
}
void Tree::display(TreeNode *node){
    if (!node) return;
    else{
        display(node -> left);
        cout<<node -> key<<" ";
        display(node -> right);
    }
}
vector<int> Tree::inorderTraversal(TreeNode* node){
    vector<int> v;
    stack<TreeNode *> s;
    TreeNode *currnode = node;
    while(!s.empty () or currnode){
        if (currnode){
            s.push(currnode);
            currnode = currnode -> left;
        }
        else{
            TreeNode *tmp = s.top();
            v.push_back(tmp -> key);
            currnode = tmp -> right;
            s.pop();
        }
    }
    return v;
}
vector<int> Tree::preorderTraversal(TreeNode* node){
    if (!node) return vector<int>();
    stack<TreeNode*> s;
    vector<int> v;
    s.push(node);
    while (!s.empty ()){
        TreeNode *tmp = s.top();
        v.push_back (tmp -> key);
        s.pop();
        if (tmp -> right)
            s.push(tmp -> right);
        if (tmp -> left)
            s.push(tmp -> left);
    }
    return v;
}
vector<int> Tree::postorderTraversal(TreeNode* node){
    if (!node) return vector<int>();
    vector<int> v;
    stack<TreeNode *> s;
    TreeNode *currnode = node, *lastnode = NULL;
    while (!s.empty() or currnode){
        if (currnode){
            s.push(currnode);
            currnode = currnode -> left;
        }
        else{
            TreeNode *tmp = s.top();
            if (tmp -> right and lastnode != tmp -> right){
                currnode = tmp -> right;
            }
            else{
                v.push_back(tmp -> key);
                lastnode = tmp;
                s.pop ();
            }
        }
    }
    return v;
}
vector<int> Tree::levelorderTraversal(TreeNode* node){
    if (!node) return vector<int>();
    queue<TreeNode *> q;
    vector<int> v;
    q.push(node);
    while (!q.empty ()){
        TreeNode *tmp = q.front ();
        q.pop();
        v.push_back (tmp -> key);
        if (tmp -> left)
            q.push(tmp -> left);
        if (tmp -> right)
            q.push(tmp -> right);
    }
    return v;
}

Tree t;

int main ( int argc, char** argv ) {
    int arr[] = {25, 15, 24, 13, 8, 56, 42, 60};
    TreeNode *root;
    root = t.createTreeNode(arr[0]);
    for (int i = 1; i < sizeof(arr)/sizeof(arr[0]); ++i)
        t.insertTreeNode(root, arr[i]);
    
    // t.display (root);
    // cout<<endl;
    
    vector<int> v;
    vector<int>::iterator it;
    v = t.inorderTraversal (root);
    cout<<"In-order traversal: ";
    for(it = v.begin(); it != v.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
    
    v.clear();
    v = t.postorderTraversal (root);
    cout<<"Post-order traversal: ";
    for(it = v.begin(); it != v.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
    
    v.clear();
    v = t.levelorderTraversal (root);
    cout<<"Level-order traversal: ";
    for(it = v.begin(); it != v.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}

