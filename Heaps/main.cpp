#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char **argv){
    int arr[] = {10, 32, 21, 15, 59, 46};
    priority_queue<int> pq;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        pq.push(arr[i]);
    
    while (!pq.empty()){
        int top = pq.top();
        cout<<top<<endl;
        pq.pop();
    }
    
    return 0;
}