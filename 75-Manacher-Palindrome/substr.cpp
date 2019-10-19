#include <iostream>
using namespace std;
int dp[100][100];

int lps(string& s){
    int N = s.size();
    int ans = 1;
    for(int i = 0; i < N; i++){
        dp[i][i] = 1;
        if(i < N-1){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 2;
                ans = max(ans,dp[i][1+i]);
            } else dp[i][i+1] = 0;
        }
    }
    for(int l=2; l < N; l++){
        for(int i = 0; i+l < N; i++){
            if(s[i] == s[l+i]){
                if(dp[i+1][l+i-1] > 0){
                    dp[i][l+i] = 2+dp[i+1][l+i-1];
                    ans = max(dp[i][l+i],ans);
                } else{
                    dp[i][l+i] = 0;
                }
            }
            else{
                dp[i][l+i] = 0;
            }
        }
    }
    return ans;
}

int main(){
    string s = "geeksforgeeejeeeks";
    cout << lps(s) << endl; 
}
