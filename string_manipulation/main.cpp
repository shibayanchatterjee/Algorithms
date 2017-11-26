#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void countChar(string str, char selChar){
    map<char, int> mymap;
    map<char, int>::iterator it;
    int count = 0, val = 0;
    for (int i = 0; i < str.length(); ++i){
        // cout<<str[i]<<" ";
        if (str[i] == selChar)
            count ++;
    }
    cout<<"Count: "<<count<<endl;
    for (int i = 0; i < str.length(); ++i){
        it = mymap.find(str[i]);
        if (it != mymap.end()){
            it->second ++;
        }
        else{
            mymap[str[i]] = 1;
        }
    }
    for (it = mymap.begin(); it != mymap.end(); ++it){
        cout<<it -> first<<" "<<it -> second<<endl;
    }
    for (int i = 0; i < str.length(); ++i){
        cout<<str.at(i);
    }
    return;
}

vector<int> findAnagrams(string haystack, string needle){
    if (haystack.length() < needle.length()) return vector<int>();
    vector<int> v;
    return v;
}

int main ( int argc, char** argv ){
    string str = "asfd svcd vdv reewf cefvce gwegw";
    char c = 'v';
    countChar(str, c);
    string haystack = "csdocnwcnow", needle = "cdws";
    findAnagrams(haystack, needle);
    return 0;
}