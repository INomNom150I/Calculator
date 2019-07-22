#include <iostream>
#include <unordered_set>
using namespace std;
string c;
unordered_set<string> st;

void combo(string& s, int l){
    if(l < 0){
        cout << c << endl;
        return;
    }
    int r = l;
    while(r >= 0 && s[r] == s[l]){
        r--;
    } 
    for(int i = l; i > r; i--){
        c.push_back(s[l]);
        combo(s,r);
    }
    for(int i = l; i > r; i--){
        c.pop_back();
    }
    combo(s,r);
}


int main(){
    string s = "abbbc";

    combo(s,s.size()-1);
}
