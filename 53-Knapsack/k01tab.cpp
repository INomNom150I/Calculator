#include <iostream>
using namespace std;

int val[] = {10, 30, 20}; 
int wt[] = {5, 10, 15}; 
int dp[100][100];

int main() 
{ 
    int W = 100; 
    int n = sizeof(val)/sizeof(val[0]); 
    memset(dp,0,sizeof(dp));
  
    for(int i = 1; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(wt[i-1] > w) dp[i][w] = dp[i-1][w];
            else dp[i][w] = max(dp[i-1][w-wt[i-1]] + val[i-1],dp[i][w]);
        }
    } 

    cout << dp[n][W] << endl; 
  
    return 0; 
} 
