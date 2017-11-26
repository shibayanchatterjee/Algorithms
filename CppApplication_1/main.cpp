#include <iostream>
#include <vector>
using namespace std;

int minDistance(string line1, string line2){
    int x = line1.size(), y = line2.size();
    vector<int> cur(x+1, 0);
    for(int i = 1; i <= x; i++)
        cur[i] = i;
    for(int j = 1; j <= y; j++){
        int pre = cur[0];
        cur[0] = j;
        for(int i = 1; i <= x; i++){
            int tmp = cur[i];
            if (line1[i - 1] == line2[j -1])
                cur[i] = pre;
            else cur[i] = min(pre + 1, min(cur[i] + 1, cur[i - 1] + 1));
            pre = tmp;
        }
    }
    return cur[x];
}

int main ( int argc, char** argv ) {
    int d = 0;
    d = minDistance("intentional", "inspire");
    cout<<d;
    return 0;
}

