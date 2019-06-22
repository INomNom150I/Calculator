#include <iostream>
using namespace std;

int val[] = {10, 30, 20}; 
int wt[] = {5, 10, 15}; 
int dp[1001];

int unbound(int w, int size){
    if(w == 0) return 0;
    if(dp[w] != -1) return dp[w];
    for(int i = 0; i < size; i++){
        if(wt[i] <= w){
            dp[w] = max(dp[w],val[i]+unbound(w-wt[i],size));
        }
    }
    return dp[w];
}

int main() 
{ 
    int W = 100; 
    int n = sizeof(val)/sizeof(val[0]); 
    memset(dp,-1,sizeof(dp));
  
    cout << unbound(W, n) << endl; 
  
    return 0; 
} 
