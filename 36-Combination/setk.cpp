#include <iostream>
using namespace std;
const int K = 3;
string b[K];

void combo(string& s, int l){
    if(l < 0){
        for(int i = 0; i < K; i++){
            cout << "{" << b[i] << "}\t";
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < K; i++){
        b[i].push_back(s[l]);
        combo(s,l-1);
        b[i].pop_back();
    }
}


int main(){
    string s = "aab";

    combo(s,s.size()-1);
}
