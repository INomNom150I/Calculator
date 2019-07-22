#include <iostream>
using namespace std;
string c;
string c1,c2;

void combo(string& s, int l){
    if(l < 0){
        cout << c << endl;
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
