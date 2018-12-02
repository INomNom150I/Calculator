#include <iostream>
#include <vector>
#include <fstream>
#include <bprof.h>
using namespace std;
const int N = 2048;
vector<int> ar;
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
    for(int i = 0; i < size; i++){
        dp1[1][i] = sum[i];
    }         
    return dptopd(k,size);
}

int small = INT_MAX;
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
            dp[i][j] = INT_MAX;
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
    int l = 0, r = sum[size];
    while(l < r){
        int mid =  (l+r)/2;
        //std::cout << mid << endl;
        if(ok(mid,k)){
            r = mid;
        }  else{
            l = mid+1;
        }
    }   
    std::cout << "Bin Result:\t"<< l << endl;
}


int main(){
    int k = 100;
    int ans;
    ifstream in("a.in");
    while(!in.eof()){
        int t;
        in >> t;
        ar.push_back(t);
    }
    size = ar.size();
    std::cout << size << std::endl;;
    calc();
    //brute(0,k);
    //dfs(0,k,0);
    //std::cout << small << endl;
    PROFILE(bin(k));
    PROFILE( std::cout << "DP:" << dpp(k) << endl);
    PROFILE( std::cout << "DPtop:" << dptop(k) << endl);
    return 0;
}
