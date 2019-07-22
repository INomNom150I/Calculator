#include <iostream>
#include <unordered_set>
using namespace std;
string c;
unordered_set<string> st;

void combo(string& s, int l){
    if(l < 0){
        if(st.find(c) == st.end()){
            cout << c << endl;
            st.insert(c);
        }
        return;
    }
    combo(s,l-1);
    c.push_back(s[l]);
    combo(s,l-1);
    c.pop_back();
}


int main(){
    string s = "abbbc";

    combo(s,s.size()-1);
}
