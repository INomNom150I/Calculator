#include <iostream>
using namespace std;

int val[] = {10, 30, 20}; 
int wt[] = {5, 10, 15}; 
int dp[1000];

int unbound(int w, int size){
    if(w == 0) return 0;
    int ret = 0;
    for(int i = 0; i < size; i++){
        if(wt[i] <= w){
            ret = max(ret,val[i]+unbound(w-wt[i],size));
        }
    }
    return ret;
}

int main() 
{ 
    int W = 100; 
    int n = sizeof(val)/sizeof(val[0]); 
  
    cout << unbound(W, n) << endl; 
  
    return 0; 
} 
