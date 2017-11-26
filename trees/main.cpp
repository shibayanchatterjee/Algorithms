#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    char key;
    vector<Node*> child;
};
Node *createnewNode(char val){
    Node *newNode = new Node;
    newNode -> key = val;
    return newNode;
}
int factorial(int val){
    if (val == 0) return 1;
    return val * factorial(val - 1);
}
void levelorderTraversal(Node *node){
    if (!node) return;
    
    queue<Node*> myqueue;
    vector<char> myvec;
    
    myqueue.push(node);
    while(!myqueue.empty()){
        Node *tmp = myqueue.front ();
        myvec.push_back(tmp -> key);
        myqueue.pop ();
        for (int i = 0; i < tmp ->child.size(); ++i){
            myqueue.push (tmp->child[i]);
        }
    }
    for (int i = 0; i < myvec.size(); ++i){
        cout<<myvec[i]<<" ";
    }
    cout<<endl;
}
void BFS(Node *node){
    
}
void DFS(Node *node){
    if (node){
        cout<<node -> key<<" ";
        for (int i = 0; i < node -> child.size(); ++i){
            DFS(node -> child[i]);
        }
    }
}
int main ( int argc, char** argv ) {
    Node *root = createnewNode('A');
    root->child.push_back (createnewNode('B'));
    root->child.push_back (createnewNode('F'));
    root ->child.push_back (createnewNode('D'));
    root ->child.push_back (createnewNode('E'));
    root ->child[0]->child.push_back (createnewNode('K'));
    root ->child[0]->child.push_back (createnewNode('J'));
    root ->child[2]->child.push_back (createnewNode('G'));
    root ->child[3]->child.push_back (createnewNode('C'));
    root ->child[3]->child.push_back (createnewNode('H'));
    root ->child[3]->child.push_back (createnewNode('I'));
    root ->child[0]->child[0]->child.push_back (createnewNode('N'));
    root ->child[0]->child[0]->child.push_back (createnewNode('M'));
    root ->child[3]->child[2]->child.push_back (createnewNode('L'));
    cout<<"Level-order traversal: ";
    levelorderTraversal(root);
    cout<<"DFS traversal: ";
    DFS(root);
    return 0;
}

