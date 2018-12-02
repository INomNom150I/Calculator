#include <iostream>
using namespace std;
const int N = 10;
int ar[N] = {1,42,23,14,51,16,17,58,29,10};
int sum[N+1];
int size = 10;
void brute(int s, int k){
    if(k==1){
        std::cout << (sum[size] - sum[s]) << endl;
        return;
    }
    for(int i = s+1; i <= size-k+1; i++){
        std::cout << (sum[i] - sum[s]) << " ";
        brute(i,k-1);
    }
}
void brute2(int e, int k){
    if(k==1){
        std::cout << sum[e] << endl;
        return;
    }
    for(int i = k-1; i < e; i++){
        std::cout << (sum[e] - sum[i]) << ' ';
        brute2(i,k-1);
    }
}
int dp1[N][N];
int dptopd(int k, int n){
    if(dp1[k][n] > 0) return dp1[k][n];
    dp1[k][n] = INT_MAX;
    for(int i = k-1; i < n; i++){
        dp1[k][n] = min(dp1[k][n],max(dptopd(k-1,i),sum[n]-sum[i]));
    }   
    return dp1[k][n];
}
int dptop(int k){
    for(int i = 0; i < 10; i++){
        dp1[1][i] = sum[i];
    }         
    return dptopd(k,size);
}

int small = 9999;
void dfs(int s, int k,int big){
    if(k==1){
        big = max(big,sum[size]-sum[s]);
        small = min(small,big);
        return;
    }
    for(int i = s+1; i <= size-k+1; i++){
        dfs(i,k-1,max(big,sum[i] - sum[s]));
    }
}

int dpp(int k){
    int dp[k+1][size+1];
    dp[1][0] = 0;
    for(int i = 1; i <= size;i++){
        dp[1][i] = dp[1][i-1] + ar[i-1];
    }
    for(int i = 2; i <= k; i++){
        for(int j = i; j <= size; j++){
            dp[i][j] = 9999;
            for(int x = i-1; x < j; x++){
                dp[i][j] = min(dp[i][j], max(dp[i-1][x],sum[j]-sum[x]));
            } 
        }       
    }
    return dp[k][size];
}

void calc(){
    sum[0]=0;
    for(int i = 0; i < N; i++){
        sum[i+1] = sum[i] + ar[i];
    }
}

bool ok(int mid, int k){
    int s = 0, g = 0;
    for(int i = 0; i < size; i++){
        s += ar[i];
        if(s > mid){
            s = ar[i];
            g++;
            if(g == k) return false;
        }
    }
    return true; 
}

void bin(int k){
    int l = 0, r = 1000;
    while(l < r){
        int mid =  (l+r)/2;
        std::cout << mid << endl;
        if(ok(mid,k)){
            r = mid;
        }  else{
            l = mid+1;
        }
    }   
    std::cout << l << endl;
}


int main(){
    calc();
    brute(0,3);
    dfs(0,3,0);
    std::cout << small << endl;
    bin(3);
    std::cout << "DP:" << dpp(3) << endl;
    std::cout << "DPtop:" << dptop(3) << endl;
    return 0;
}
