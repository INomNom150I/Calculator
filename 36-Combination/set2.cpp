#include <iostream>
using namespace std;
string c;
string c1,c2;

void combo(string& s, int l){
    if(l < 0){
        cout << c1 << "\t" << c2<< endl;
        return;
    }
    c1.push_back(s[l]);
    combo(s,l-1);
    c1.pop_back();
    c2.push_back(s[l]);
    combo(s,l-1);
    c2.pop_back();
}


int main(){
    string s = "abc";

    combo(s,s.size()-1);
}
