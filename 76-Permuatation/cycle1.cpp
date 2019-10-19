#include <iostream>
using namespace std;

int n;
int ar[] = {4,5,3,2,1,0};
bool v[100];

void dfs(int s){
    if(v[s]) return;
    cout << s << ' ';
    v[s] = true;
    for(int i = 0; i < n; i++){
        if(ar[i] == s){
            dfs(i);
        }
    }
}

int main(){
    n = sizeof(ar)/sizeof(int);
    int m = 0;
    for(int i = 0; i < n; i++){
        if(!v[ar[i]]){
            m++;
            dfs(ar[i]);
            cout << endl;
        }
    }
    cout << m << endl;
}
