#include <iostream>
using namespace std;

int val[] = {10, 30, 20}; 
int wt[] = {5, 10, 15}; 
int dp[100][100];

int dfs(int n, int c){
    if(n == 0) return 0;
    if(dp[n][c] != -1) return dp[n][c];
    if(wt[n-1] > c){
        dp[n][c] = dfs(n-1,c);
    } else{
        dp[n][c] = max(dfs(n-1,c),val[n-1]+dfs(n-1,c-wt[n-1]));
    }
    return dp[n][c];
    
}

int main() 
{ 
    int W = 100; 
    int n = sizeof(val)/sizeof(val[0]); 
    memset(dp,-1,sizeof(dp));
  
    cout << dfs(n,W) << endl; 
  
    return 0; 
} 
