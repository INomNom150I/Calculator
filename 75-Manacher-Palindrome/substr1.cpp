#include <iostream>
using namespace std;
int dp[100][100];

int lps(string& s){
    int N = s.size();
    int ans = 1;
    for(int i = 0; i < N; i++){
        dp[0][i] = 1;
        if(i < N-1){
            if(s[i] == s[i+1]){
                dp[1][i] = 2;
                ans = max(ans,dp[1][i]);
            } else dp[1][i] = 0;
        }
    }
    for(int l=2; l < N; l++){
        for(int i = 0; i+l < N; i++){
            if(s[i] == s[l+i]){
                if(dp[l-2][i+1] > 0){
                    dp[l][i] = 2+dp[l-2][i+1];
                    ans = max(dp[l][i],ans);
                } else{
                    dp[l][i] = 0;
                }
            }
            else{
                dp[l][i] = 0;
            }
        }
    }
    return ans;
}

int main(){
    string s = "geeksforgeeejeeeks";
    cout << lps(s) << endl; 
}
