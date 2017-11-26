#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main ( int argc, char** argv ) {
    fstream fo;
    fo.open("test.out", ios::in | ios::out);
    if (!fo){
        cout<<"Cannot open file"<<endl;
        return 0;
    }
    char str[255];
    while(fo){
        fo.getline (str, 255);
        if(fo) cout<<str<<endl;
    }
    fo.close();
    
    string txt = "Here I am ";
    char ch = " ";
    
    unsigned int pos = txt.find(ch), initialPos = 0;
    vector<string> myvec;
    while(pos != string::npos){
        myvec.push_back(txt.substr ());
        initialPos = pos + 1;
        pos = txt.find(ch, initialPos);
    }
    myvec.push_back(txt.substr(initialPos, min(pos, txt.size())- initialPos + 1));
    return 0;
}

