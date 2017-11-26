#include <cstdlib>
#include <iostream>
using namespace std;

class BTreeNode{
    vector<int> keys;
    int degree, currkeys;
    vector<BTreeNode *> child;
    bool leaf;
};

class BTree{
    BTreeNode *root;
public:
    BTree(int _t);
    void traverse();
    void insert();
    void search();
    
};

int main ( int argc, char** argv ) {
    return 0;
}

