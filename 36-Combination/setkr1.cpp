#include <iostream>
using namespace std;
const int K = 3;
string b[K];
int a[K];

void combo(string& s, int l){
    if(l < 0){
#if 0
        for(int i = K-1; i >= 0; i--){
            cout << a[i] << " ";
        }
        cout << endl;
#endif
        for(int i = 0; i < K; i++){
            cout << "{" << b[i] << "}\t";
        }
        cout << endl;
        return;
    }
    int c = l-1;
    while(s[c] == s[l]){
        c--;
    }
    int i = 0;
    if(s[l] == s[l+1]){
        i = a[l+1];
    }   
    for(; i < K; i++){
            b[i].push_back(s[l]);
            combo(s,l-1);
        a[l] = i;
            b[i].pop_back();
    }
}


int main(){
    string s = "aaab";

    combo(s,s.size()-1);
}
