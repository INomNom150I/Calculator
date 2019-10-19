#include <iostream>
using namespace std;
int dp[100][100];

int lps(string& s){
    int N = s.size();
    for(int i = 0; i < N; i++){
        dp[i][i] = 1;
        if(i < N-1){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 2;
            } else dp[i][i+1] = 1;
        }
    }
    for(int l=2; l < N; l++){
        for(int i = 0; i+l < N; i++){
            if(s[i] == s[l+i]) dp[i][l+i] = 2+dp[i+1][l+i-1];
            else{
                dp[i][l+i] = max(dp[i+1][l+i],dp[i][l+i-1]);
            }
        }
    }
    return dp[0][N-1];
}

int main(){
    string s = "geeksforgeeks";
    cout << lps(s) << endl; 
}
