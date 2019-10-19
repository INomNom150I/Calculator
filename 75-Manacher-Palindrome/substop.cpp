#include <iostream>
using namespace std;
int dp[100][100];
string str = "geeksforgeeks";

int dfs(int s, int e){
    if(dp[s][e] >= 0) return dp[s][e];
    if(s > e) {
        dp[s][e] = 0;
    }
    else if(s == e) dp[s][e] = 1;
    else { 
        if(str[s] == str[e]){
            dp[s][e] =  2+dfs(s+1,e-1);
        } else{
            dp[s][e] =  max(dfs(s+1,e),dfs(s,e-1));
        }
    }
    return dp[s][e];
}

int main(){
    int N = str.size();

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,N-1) << endl; 
}
