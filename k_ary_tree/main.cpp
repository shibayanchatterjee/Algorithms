#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct TreeNode{
    int key;
    vector<TreeNode*> child;
    TreeNode(int x){
        key = x;
    }
};

class k_ary_tree{
    
};

k_ary_tree obj;

int main ( int argc, char** argv ) {
    int arr = {12, 13, 15, 20, 59, 69, 34, 38};
    TreeNode *root;
    root = new TreeNode(10);
    
    return 0;
}

