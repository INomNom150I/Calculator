#include <iostream>
using namespace std;
int dp[100][100];
string str = "geeksforgeeks";

int dfs(int s, int e){
    if(s > e) return 0;
    if(s == e) return 1;
    if(str[s] == str[e]){
        return 2+dfs(s+1,e-1);
    } else{
        return max(dfs(s+1,e),dfs(s,e-1));
    }
}

int main(){
    int N = str.size();
    cout << dfs(0,N-1) << endl; 
}
