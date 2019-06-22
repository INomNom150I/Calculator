#include <iostream>
using namespace std;
string a = "abcd";
string b;

void dfs(int s, int d){
    if(b.size() == d){
        cout << b << endl;
        return;
    }
    if(s >= a.size()) return;
    b.push_back(a[s]);
    dfs(s+1,d);
    b.pop_back();
    dfs(s+1,d);
}

int main(){
    cout << a.size() << endl;
    for(int i = 1; i <= a.size(); i++){
        dfs(0,i);
    }
}
