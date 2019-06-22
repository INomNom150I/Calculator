#include <iostream>
using namespace std;

int val[] = {10, 30, 20}; 
int wt[] = {5, 10, 15}; 
int dp[1000];

int dfs(int n, int c){
    if(n == 0) return 0;
    if(wt[n-1] > c){
        return dfs(n-1,c);
    }
    return max(dfs(n-1,c),val[n-1]+dfs(n-1,c-wt[n-1]));
    
}

int main() 
{ 
    int W = 100; 
    int n = sizeof(val)/sizeof(val[0]); 
  
    cout << dfs(n,W) << endl; 
  
    return 0; 
} 
